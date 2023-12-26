#include "Category.h"

#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

Category::Category(std::string title) { setTitle(title); }
Category::Category(std::string title, std::string subcategory) {
  setTitle(title);
  addSubcategory(subcategory);
}
Category::Category(std::string title, std::vector<std::string> subcategories) {
  setTitle(title);
  setSubcategories(subcategories);
}
int Category::findSubcategoryIndex(std::string subcategory) {
  int index = -1;
  for (int i = 0; i < int(subcategories.size()); i++) {
    if (subcategories[i] == subcategory) index = i;
  }
  return index;
}
void Category::addSubcategory(std::string subcategory) {
  std::stringstream exception;
  exception << subcategory << " subcategory already exists in " << title
            << " category.";

  int index = findSubcategoryIndex(subcategory);
  if (index >= 0) throw std::invalid_argument(exception.str());
  subcategories.push_back(subcategory);
}
void Category::deleteSubcategory(std::string subcategory) {
  std::stringstream exception;
  exception << "No " << subcategory << " subcategory exists.";

  int index = findSubcategoryIndex(subcategory);
  if (index < 0) throw std::invalid_argument(exception.str());
  subcategories.erase(subcategories.begin() + index);
}
void Category::deleteAllSubcategories() {
  if (!this->subcategories.empty()) subcategories.clear();
}
std::string Category::toString() const {
  std::stringstream ss;
  ss << "Category: " << title;
  if (!subcategories.empty())
    ss << "\nSubcategories: " << getSubcategoriesString();
  ss << std::endl;
  return ss.str();
}
void Category::setSubcategories(std::vector<std::string> subcategories) {
  deleteAllSubcategories();
  for (int i = 0; i < int(subcategories.size()); i++) {
    addSubcategory(subcategories[i]);
  }
}
std::string Category::getSubcategoriesString() const {
  std::stringstream ss;
  for (int i = 0; i < int(subcategories.size()); i++) {
    if (i > 0) ss << ", ";
    ss << subcategories[i];
  }
  return ss.str();
}
std::ostream &operator<<(std::ostream &os, const Category &obj) {
  os << obj.getTitle() << ": " << obj.getSubcategoriesString() << std::endl;
  return os;
}
