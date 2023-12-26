/*
Author: Mia Kelley-Lanser
Class: Advanced C++
Date: 05/07/2023
*/

#pragma once

#include <string>

#include "CategoryDatabase.h"
#include "Entry.h"
#include "EntryDatabase.h"

class UserDatabase {
 private:
  CategoryDatabase categoryDatabase;  // a user's categories
  EntryDatabase entryDatabase;        // a user's entries

 public:
  /**
   * @brief Creates a new Category object with the given category title and adds
   * it to the categoryDatabase; throws an invalid_argument if a Category
   * object with the given title already exists
   *
   * @param category (string)
   */
  void createNewCategory(std::string category);
  /**
   * @brief Adds the given subcategory string to the Category object in
   * categoryDatabase's subcategories vector<string> with the given category
   * title; if no Category object with the given title exists, creates it and
   * adds it to the categoryDatabase with the given category title and
   * subcategory; throws an invalid_argument if a subcategory with the same name
   * already exists in the Category object with the given category title
   *
   * @param category (string)
   * @param subcategory (string)
   */
  void createNewSubcategory(std::string category, std::string subcategory);
  /**
   * @brief Creates a new Entry object with the given values (no subcategory)
   * and adds it to the entryDatabase; if no Category object with the given
   * title exists in the categoryDatabase, creates a new category with the given
   * title and adds it to the categoryDatabase
   *
   * @param month (short)
   * @param day (short)
   * @param year (short)
   * @param category (string)
   * @param amount (double) positive for income, negative for expense
   */
  void createNewEntry(short month, short day, short year, std::string category,
                      double amount);
  /**
   * @brief Creates a new Entry object with the given values (has subcategory)
   * and adds it to the entryDatabase; if no Category object with the given
   * title exists in the categoryDatabase, creates a new category with the given
   * title and subcategory and adds it to the categoryDatabase; if the Category
   * object exists, but has no subcategory with the given name, adds the new
   * subcategory to that Category object's subcategories vector<string>
   *
   * @param month (short)
   * @param day (short)
   * @param year (short)
   * @param category (string)
   * @param subcategory (string)
   * @param amount (double) positive for income, negative for expense
   */
  void createNewEntry(short month, short day, short year, std::string category,
                      std::string subcategory, double amount);
  /**
   * @brief Deletes the given oldEntry from the entries vector<Entry> in the
   * entryDatabase, then adds the new entry to entries; throws an
   * invalid_argument error if the old entry does not exist
   *
   * @param oldEntry (Entry)
   * @param newEntry (Entry)
   */
  void editEntry(Entry oldEntry, Entry newEntry);
  /**
   * @brief Removes the entry with the given values (no subcategory) from the
   * entries vector<Entry> in the entryDatabase; throws an invalid_argument
   * error if no such entry exists
   *
   * @param month (short)
   * @param day (short)
   * @param year (short)
   * @param category (string)
   * @param amount (double) positive for income, negative for expense
   */
  void deleteEntry(short month, short day, short year, std::string category,
                   double amount);
  /**
   * @brief Removes the entry with the given values (has subcategory) from the
   * entries vector<Entry> in the entryDatabase; throws an invalid_argument
   * error if no such entry exists
   *
   * @param month (short)
   * @param day (short)
   * @param year (short)
   * @param category (string)
   * @param subcategory (string)
   * @param amount (double)
   */
  void deleteEntry(short month, short day, short year, std::string category,
                   std::string subcategory, double amount);
  /**
   * @brief Clears the entries vector<Entry> in entryDatabase if it ist not
   * already empty (sets balance to 0.0)
   *
   */
  void deleteAllEntries();

  /**
   * @brief Prints the current balance of all the entry amounts added up
   * to the given ostream&
   *
   * @param os (ostream&)
   */
  void displayBalance(std::ostream& os);
  /**
   * @brief Prints all the entries in the entryDatabase to the given ostream&,
   * giving a header with the categories (Date, Category, Subcategory, Amount,
   * Balance) and subsequently each entry in the database in lexicographical
   * order (first according to date, then category, then subcategory)
   *
   * @param os (ostream&)
   */
  void displayAllEntries(std::ostream& os);
  /**
   * @brief Prints all entries in the entryDatabase whose category is the same
   * as the given category to the given ostream address; gives a header with the
   * categories (Date, Subcategory, Amount) and subsequently each entry's
   * information in lexicographical order (first according to date, then
   * subcategory) under these categories; prints their added total at the bottom
   *
   * @param os (ostream&)
   * @param category (string)
   */
  void displayEntries(std::ostream& os, std::string category);
  /**
   * @brief Prints all entries in the entryDatabase whose category is the same
   * as the given category and are expenses if expense == true or are incomes if
   * expense == false; gives a header with the categories (Date, Subcategory,
   * Amount) and subsequently each entry's information in lexicographical order
   * (first according to date, then subcategory) under these categories;
   * absolute values of the amounts are printed (no negatives for expenses);
   * prints the absolute value of their added total at the bottom
   *
   * @param os (ostream&)
   * @param category (string)
   * @param expense (bool) true to print expenses, false to print incomes
   */
  void displayEntries(std::ostream& os, std::string category, bool expense);

  // getter
  std::vector<Entry> getEntries() { return entryDatabase.getEntries(); }

  // Note: while the CategoryDatabase class has methods to delete categories,
  // the UserDatabase class does not allow access to these. This is because
  // entries depend on a category, and if one were to be deleted, you could have
  // stale category titles in entry objects. The option to delete is still given
  // in the CategoryDatabase class because the class could be used in another
  // context where deletion would make sense and may even be necessary.
};
