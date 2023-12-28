/*
Author: Mia Kelley-Lanser
Date: 05/07/2023
All rights reserved
*/

#include "UserDatabase.h"

#include <sstream>
#include <string>

void UserDatabase::createNewCategory(std::string category) {
  Category newCategory(category);
  categoryDatabase.addCategory(newCategory);
}
void UserDatabase::createNewSubcategory(std::string category,
                                        std::string subcategory) {
  categoryDatabase.addSubcategory(category, subcategory);
}
void UserDatabase::createNewEntry(short month, short day, short year,
                                  std::string category, double amount) {
  if (categoryDatabase.findCategoryIndex(category) < 0) {
    createNewCategory(category);
  }
  Entry newEntry(month, day, year, amount, category);
  entryDatabase.addEntry(newEntry);
}
void UserDatabase::createNewEntry(short month, short day, short year,
                                  std::string category, std::string subcategory,
                                  double amount) {
  int index = categoryDatabase.findCategoryIndex(category);
  if (index < 0) {
    createNewSubcategory(category, subcategory);
  } else {
    int subIndex = categoryDatabase.findSubcategoryIndex(category, subcategory);
    if (subIndex < 0) {
      createNewSubcategory(category, subcategory);
    }
  }
  Entry newEntry(month, day, year, amount, category, subcategory);
  entryDatabase.addEntry(newEntry);
}
void UserDatabase::editEntry(Entry oldEntry, Entry newEntry) {
  entryDatabase.editEntry(oldEntry, newEntry);
}
void UserDatabase::deleteEntry(short month, short day, short year,
                               std::string category, double amount) {
  Entry entry(month, day, year, amount, category);
  entryDatabase.deleteEntry(entry);
}
void UserDatabase::deleteEntry(short month, short day, short year,
                               std::string category, std::string subcategory,
                               double amount) {
  Entry entry(month, day, year, amount, category, subcategory);
  entryDatabase.deleteEntry(entry);
}
void UserDatabase::deleteAllEntries() { entryDatabase.deleteAllEntries(); }

void UserDatabase::displayBalance(std::ostream& os) {
  entryDatabase.displayBalance(os);
}
void UserDatabase::displayAllEntries(std::ostream& os) { os << entryDatabase; }
void UserDatabase::displayEntries(std::ostream& os, std::string category) {
  entryDatabase.displayEntries(os, category);
}
void UserDatabase::displayEntries(std::ostream& os, std::string category,
                                  bool expense) {
  entryDatabase.displayEntries(os, category, expense);
}
