/*
Author: Mia Kelley-Lanser
Date: 05/07/2023
All rights reserved
*/

#include "EntryDatabase.h"

#include <cmath>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

#include "Entry.h"

EntryDatabase::EntryDatabase() {}
int EntryDatabase::binarySearchLoc(int first, int last, Entry entry) {
  while (first <= last) {
    int middle = (first + last) / 2;
    if (entries[middle] == entry) return middle;
    if (entries[middle] < entry)
      first = middle + 1;
    else
      last = middle - 1;
  }
  return last + 1;
}
int EntryDatabase::binarySearch(int first, int last, Entry entry) {
  if (first > last) return -1;
  int middle = (first + last) / 2;
  if (entries[middle] == entry) return middle;
  if (entries[middle] < entry)
    return binarySearch(middle + 1, last, entry);
  else
    return binarySearch(first, middle - 1, entry);
}
void EntryDatabase::addEntry(Entry entry) {
  int index = binarySearchLoc(0, entries.size() - 1, entry);
  entries.insert(entries.begin() + index, entry);
  balance += entry.getAmount();
}
void EntryDatabase::editEntry(Entry oldEntry, Entry newEntry) {
  deleteEntry(oldEntry);
  balance -= oldEntry.getAmount();
  addEntry(newEntry);
  balance += newEntry.getAmount();
}
void EntryDatabase::deleteEntry(Entry entry) {
  std::string exception = "The given entry does not exist.";

  int index = binarySearch(0, entries.size(), entry);

  if (index < 0) throw std::invalid_argument(exception);
  entries.erase(entries.begin() + index);
  balance -= entry.getAmount();
}
void EntryDatabase::deleteAllEntries() {
  if (!this->entries.empty()) entries.clear();
  balance = 0.0;
}
void EntryDatabase::displayAllEntries(std::ostream &os) {
  os << this->toString();
}
void EntryDatabase::displayEntries(std::ostream &os, std::string category) {
  os << "Date" << std::setw(27) << "Subcategory" << std::setw(19) << "Amount"
     << std::endl;
  os << "--------------------------------------------------" << std::endl;

  double currentBal = 0.0;
  for (int i = 0; i < int(entries.size()); i++) {
    if (entries[i].getCategory() == category) {
      currentBal += entries[i].getAmount();
      os << entries[i].getDate() << std::setw(20) << entries[i].getSubcategory()
         << std::setw(20) << std::fixed << std::setprecision(2)
         << entries[i].getAmount() << std::endl;
    }
  }
  os << std::setw(30) << "TOTAL" << std::setw(20) << std::fixed
     << std::setprecision(2) << currentBal << std::endl;
}
void EntryDatabase::displayEntries(std::ostream &os, std::string category,
                                   bool expense) {
  os << "Date" << std::setw(27) << "Subcategory" << std::setw(19) << "Amount"
     << std::endl;
  os << "--------------------------------------------------" << std::endl;

  double currentBal = 0.0;
  for (int i = 0; i < int(entries.size()); i++) {
    if (entries[i].getCategory() == category) {
      if ((expense && entries[i].getAmount() < 0.0) ||
          (!expense && entries[i].getAmount() >= 0.0)) {
        currentBal += std::abs(entries[i].getAmount());
        os << entries[i].getDate() << std::setw(20)
           << entries[i].getSubcategory() << std::setw(20) << std::fixed
           << std::setprecision(2) << std::abs(entries[i].getAmount())
           << std::endl;
      }
    }
  }
  os << std::setw(30) << "TOTAL" << std::setw(20) << std::fixed
     << std::setprecision(2) << currentBal << std::endl;
}
void EntryDatabase::displayBalance(std::ostream &os) {
  os << "Balance: " << std::fixed << std::setprecision(2) << balance;
}

std::string EntryDatabase::toString() const {
  std::stringstream ss;
  ss << "Date" << std::setw(25) << "Category" << std::setw(25) << "Subcategory"
     << std::setw(16) << "Amount" << std::setw(16) << "Balance" << std::endl;
  ss << "----------------------------------------------------------------------"
        "----------------"
     << std::endl;

  double currentBal = 0.0;
  for (int i = 0; i < int(entries.size()); i++) {
    currentBal += entries[i].getAmount();
    ss << entries[i] << std::setw(15) << std::fixed << std::setprecision(2)
       << currentBal << std::endl;
  }
  return ss.str();
}

std::ostream &operator<<(std::ostream &os, const EntryDatabase &obj) {
  os << obj.toString();
  return os;
}
