/*
Author: Mia Kelley-Lanser
Date: 05/07/2023
All rights reserved
*/

#pragma once

#include <string>

#include "Date.h"

// Forward class declaration for friend ostream overloaded operator
class Entry;
std::ostream &operator<<(std::ostream &, const Entry &);

class Entry {
 private:
  Date date;                // date of transaction
  double amount;            // positive for income, negative for expense
  std::string category;     // category title
  std::string subcategory;  // optional subcategory title

  /**
   * @brief Compares two entry objects. Returns 1 if entry1 should come before
   * entry2, 0 if they are the equivalent, and -1 if entry1 should come after
   * entry2 (first organized by earliest date, then by category and subcategory
   * lexicographically)
   *
   * @param entry1 (Entry)
   * @param entry2 (Entry)
   * @return int
   */
  int compareEntries(Entry entry1, Entry entry2) const;

 public:
  /**
   * @brief Entry constructor with month, day, year, amount, and category
   * parameters; sets date to the given month day and year (may throw
   * InvalidDate error), amount to the given value, and category to the given
   * string
   *
   * @param month
   * @param day
   * @param year
   * @param amount
   * @param category
   */
  Entry(short month, short day, short year, double amount,
        std::string category);
  /**
   * @brief Entry constructor with month, day, year, amount, category, and
   * subcategory parameters; uses a constructor initializer (to Entry
   * constructor with month, day, year, (may throw InvalidDate error), amount,
   * and category) to set the date, amount, and category, then sets subcategory
   * to the given string
   *
   * @param month
   * @param day
   * @param year
   * @param amount
   * @param category
   * @param subcategory
   */
  Entry(short month, short day, short year, double amount, std::string category,
        std::string subcategory);
  /**
   * @brief Entry constructor with date, amount, and category parameters; uses a
   * constructor initializer (to Entry constructor with month, day, year, (may
   * throw InvalidDate error), amount, and category) to set the given values
   *
   * @param date
   * @param amount
   * @param category
   */
  Entry(Date date, double amount, std::string category);
  /**
   * @brief Entry constructor with date, amount, category, and subcategory
   * parameters; uses a constructor initializer (to Entry constructor with
   * month, day, year, (may throw InvalidDate error), category, and subcategory)
   * to set the given values
   *
   * @param date
   * @param amount
   * @param category
   * @param subcategory
   */
  Entry(Date date, double amount, std::string category,
        std::string subcategory);

  // Setters
  void setDate(short month, short day,
               short year);  // may throw InvalidDate error
  void setDate(Date date);   // may throw InvalidDate error
  void setAmount(double amount) { this->amount = amount; }
  void setCategory(std::string category) { this->category = category; }
  void setSubcategory(std::string subcategory);

  // Getters
  Date getDate() const { return date; }
  double getAmount() const { return amount; }
  std::string getCategory() const { return category; }
  std::string getSubcategory() const { return subcategory; }

  /**
   * @brief  Entry class toString() method; returns a string listing the
   * date, category, optional subcategory, and amount in the following format:
   *
   * Date: (mm/dd/year)
   * Category: (category)
   * (if subcategory) Subcategory: (subcategory)
   * Amount: (amount)
   *
   * @return std::string
   */
  std::string toString() const;

  // Overloaded ouput operator
  //    format: (mm/dd/year)  (category)  (subcategory)     (amount)
  friend std::ostream &operator<<(std::ostream &, const Entry &obj);

  // Overloaded comparison operators
  //    (compares by entry dates, then category and subcategory
  //    (lexicographically))
  bool operator<(const Entry &right) const;
  bool operator>(const Entry &right) const;
  bool operator<=(const Entry &right) const;
  bool operator>=(const Entry &right) const;
  bool operator==(const Entry &right) const;
  bool operator!=(const Entry &right) const;
};
