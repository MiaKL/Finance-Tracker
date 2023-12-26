/*
Author: Mia Kelley-Lanser
Class: Advanced C++
Date: 05/07/2023
*/

#pragma once

#include <vector>

#include "Entry.h"

// Forward class declaration for friend ostream overloaded operator
class EntryDatabase;
std::ostream &operator<<(std::ostream &, const EntryDatabase &);

class EntryDatabase {
 private:
  std::vector<Entry> entries;
  double balance{0.0};  // total balance when all entry amounts are added

  /**
   * @brief Iterative binary search to find the index of where to add a new
   * entry to keep entries vector<Entry> sorted (must be sorted before doing
   * binary search for the search to work)
   *
   * @param first (int) the beginning of the vector
   * @param last (int) the end of the vector
   * @param entry (Entry) the entry to be added
   * @return int
   */
  int binarySearchLoc(int first, int last, Entry entry);
  /**
   * @brief Recursive binary search to find the index of an Entry object in the
   * entries vector <Entry (must be sorted before doing binary search for the
   * search to work)
   *
   * @param first (int) the beginning of the vector portion to search
   * @param last (int) the end of the vector portion to search
   * @param entry (Entry) the entry to search for
   * @return int
   */
  int binarySearch(int first, int last, Entry entry);

 public:
  /**
   * @brief EntryDatabase default constructor
   *
   */
  EntryDatabase();

  /**
   * @brief Adds the given entry to the entries vector<Entry; uses
   * binarySearchLoc to determine where to add the entry to keep the
   * entries in order; adds the new entry's amount to the balance
   *
   * @param entry (Entry)
   */
  void addEntry(Entry entry);
  /**
   * @brief Deletes the given oldEntry from the entries vector<Entry>, then adds
   * the new entry to entries; subtracts the old entry's amount from the
   * balance and adds the new entry's amount; throws an invalid_argument error
   * if the old entry does not exist
   *
   * @param oldEntry (Entry)
   * @param newEntry (Entry)
   */
  void editEntry(Entry oldEntry, Entry newEntry);
  /**
   * @brief Removes the given entry from the entries vector<Entry>; subtracts
   * the entry's amount from the balance; throws an invalid_argument
   * error if the entry does not exist
   *
   * @param entry (Entry)
   */
  void deleteEntry(Entry entry);
  /**
   * @brief Clears the entries vector<Entry> if it ist not already empty; sets
   * balance to 0.0
   *
   */
  void deleteAllEntries();

  /**
   * @brief Prints this classes toString() to the given ostream address (prints
   * all entries in the database)
   *
   * @param os (ostream&)
   */
  void displayAllEntries(std::ostream &os);
  /**
   * @brief Prints all entries in the database whose category is the same as the
   * given category, as well as their added total, to the given ostream address;
   * also prints a header giving the categories (Date, Subcategory, Amount)
   *
   * @param os (ostream&)
   * @param category (string)
   */
  void displayEntries(std::ostream &os, std::string category);
  /**
   * @brief Prints all entries in the database whose category is the same as the
   * given category and are expenses if expense == true or are incomes if
   * expense == false, as well as the absolute value of their added total to the
   * given ostream address; (if expense == true, the absolute values of the
   * amounts are displayed), (does not print the category, as this would be
   * redundant, but does print the subcategory of each entry if present); also
   * prints a header giving the categories (Date, Subcategory, Amount)
   *
   * @param os (ostream&)
   * @param category (string)
   * @param expense (bool)
   */
  void displayEntries(std::ostream &os, std::string category, bool expense);
  /**
   * @brief Prints the current balance (balance member variable) to the given
   * ostream&
   *
   * @param os (ostream&)
   */
  void displayBalance(std::ostream &os);

  // getters
  double getBalance() { return balance; }
  std::vector<Entry> getEntries () { return entries; }

  /**
   * @brief EntryDatabase class toString() method; returns a string listing each
   * entry using the Entry class's overloaded ouput operator, in addition to the
   * balance after each entry's amount is taken into account and a header giving
   * the categories (Date, Category, Subcategory, Amount, Balance)
   *
   * @return std::string
   */
  std::string toString() const;

  // Overloaded ouput operator
  //    uses toString() method
  friend std::ostream &operator<<(std::ostream &, const EntryDatabase &obj);
};
