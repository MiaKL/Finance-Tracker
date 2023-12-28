/*
Author: Mia Kelley-Lanser
Date: 05/07/2023
All rights reserved
*/

#include "CategoryDatabase.h"

#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

CategoryDatabase::CategoryDatabase() {}
CategoryDatabase::CategoryDatabase(std::vector<Category> categories) {
  setCategories(categories);
}
int CategoryDatabase::findCategoryIndex(std::string category) {
  int index = -1;
  for (int i = 0; i < int(categories.size()); i++) {
    if (categories[i].getTitle() == category) index = i;
  }
  return index;
}
int CategoryDatabase::findSubcategoryIndex(std::string category,
                                           std::string subcategory) {
  int index = findCategoryIndex(category);
  if (index >= 0) {
    int subIndex = categories[index].findSubcategoryIndex(subcategory);
    return subIndex;
  }
  return index;
}
void CategoryDatabase::addCategory(Category category) {
  std::stringstream exception;
  exception << category.getTitle() << " category already exists.";

  int index = findCategoryIndex(category.getTitle());

  if (index >= 0) throw std::invalid_argument(exception.str());
  categories.push_back(category);
}
void CategoryDatabase::addSubcategory(std::string category,
                                      std::string subcategory) {
  int index = findCategoryIndex(category);
  if (index < 0) {
    Category newCategory(category, subcategory);
    addCategory(newCategory);
  } else {
    categories[index].addSubcategory(subcategory);
  }
}
void CategoryDatabase::deleteCategory(Category category) {
  std::stringstream exception;
  exception << "No " << category.getTitle() << " category exists.";

  int index = findCategoryIndex(category.getTitle());

  if (index < 0) throw std::invalid_argument(exception.str());
  categories.erase(categories.begin() + index);
}
void CategoryDatabase::deleteAllCategories() {
  if (!this->categories.empty()) categories.clear();
}
std::string CategoryDatabase::toString() const {
  std::stringstream ss;
  for (int i = 0; i < int(categories.size()); i++) {
    if (i > 0) ss << std::endl;
    ss << categories[i].toString() << std::endl;
  }
  return ss.str();
}
void CategoryDatabase::setCategories(std::vector<Category> categories) {
  deleteAllCategories();
  for (int i = 0; i < int(categories.size()); i++) {
    addCategory(categories[i]);
  }
}
std::ostream &operator<<(std::ostream &os, const CategoryDatabase &obj) {
  for (int i = 0; i < int(obj.categories.size()); i++) {
    os << obj.categories[i];
  }
  return os;
}
