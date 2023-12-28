/*
Author: Mia Kelley-Lanser
Date: 05/07/2023
All rights reserved
*/

#include "Entry.h"

#include <iomanip>
#include <sstream>
#include <string>

#include "Date.h"

Entry::Entry(short month, short day, short year, double amount,
             std::string category) {
  setDate(month, day, year);
  setAmount(amount);
  setCategory(category);
}
Entry::Entry(short month, short day, short year, double amount,
             std::string category, std::string subcategory)
    : Entry(month, day, year, amount, category) {
  setSubcategory(subcategory);
}
Entry::Entry(Date date, double amount, std::string category)
    : Entry(date.getMonth(), date.getDay(), date.getYear(), amount, category) {}
Entry::Entry(Date date, double amount, std::string category,
             std::string subcategory)
    : Entry(date.getMonth(), date.getDay(), date.getYear(), amount, category,
            subcategory) {}

void Entry::setDate(short month, short day, short year) {
  this->date.set(month, day, year);
}
void Entry::setSubcategory(std::string subcategory) {
  this->subcategory = subcategory;
}

std::string Entry::toString() const {
  std::stringstream ss;
  ss << "Date: " << date << "\nCategory: " << category;
  if (subcategory != "") ss << "\nSubcategory: " << subcategory;
  ss << std::fixed << std::setprecision(2);
  ss << "\nAmount: " << amount << std::endl;
  return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Entry &obj) {
  os << std::left << std::setw(21) << obj.date << std::setw(22) << obj.category << std::setw(17)
     << obj.subcategory << std::right << std::setw(10) << std::fixed << std::setprecision(2)
     << obj.amount;
  return os;
}

int Entry::compareEntries(Entry entry1, Entry entry2) const {
  int comparison = 0;
  if (entry1.date < entry2.date) {
    comparison = -1;
    return comparison;
  }
  if (entry1.date > entry2.date) {
    comparison = 1;
    return comparison;
  }
  if (entry1.category < entry2.category) {
    comparison = -1;
    return comparison;
  }
  if (entry1.category > entry2.category) {
    comparison = 1;
    return comparison;
  }
  if (entry1.subcategory < entry2.subcategory) {
    comparison = -1;
    return comparison;
  }
  if (entry1.subcategory > entry2.subcategory) {
    comparison = 1;
    return comparison;
  }

  return comparison;
}

bool Entry::operator<(const Entry &right) const {
  Entry temp(this->date, this->amount, this->category, this->subcategory);
  if (compareEntries(temp, right) == -1)
    return true;
  else
    return false;
}
bool Entry::operator>(const Entry &right) const {
  Entry temp(this->date, this->amount, this->category, this->subcategory);
  if (compareEntries(temp, right) == 1)
    return true;
  else
    return false;
}
bool Entry::operator<=(const Entry &right) const {
  Entry temp(this->date, this->amount, this->category, this->subcategory);
  if (compareEntries(temp, right) == -1 || compareEntries(temp, right) == 0)
    return true;
  else
    return false;
}
bool Entry::operator>=(const Entry &right) const {
  Entry temp(this->date, this->amount, this->category, this->subcategory);
  if (compareEntries(temp, right) == 1 || compareEntries(temp, right) == 0)
    return true;
  else
    return false;
}
bool Entry::operator==(const Entry &right) const {
  Entry temp(this->date, this->amount, this->category, this->subcategory);
  if (compareEntries(temp, right) == 0)
    return true;
  else
    return false;
}
bool Entry::operator!=(const Entry &right) const {
  Entry temp(this->date, this->amount, this->category, this->subcategory);
  if (compareEntries(temp, right) != 0)
    return true;
  else
    return false;
}
