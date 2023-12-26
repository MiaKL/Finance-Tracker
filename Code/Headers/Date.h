/*
Author: Mia Kelley-Lanser
Course: Advanced C++
Date: 05/07/2023
*/

#pragma once

#include <string>

// Forward class declaration for friend ostream and istream overloaded operators
class Date;
std::ostream &operator<<(std::ostream &, const Date &);
std::istream &operator>>(std::istream &, Date &);

class Date {
 private:
  short month;
  short day;
  short year;
  /**
   * @brief Checks if the date is valid. Throws an InvalidDate error if any
   * member variables are negative, month > 12, day
   * exceeds the max number of days in the given month (29, 30, or 31
   * depending), or date is set to leap day in a non-leap-year
   */
  void checkDay();
  /**
   * @brief Compares two date objects. Returns 1 if date1 is newer than date2,
   * 0 if they are the same, and -1 if
   * date1 is older than date2
   *
   * @param date1
   * @param date2
   * @return int
   */
  int compareDates(Date date1, Date date2) const;

 public:
  // exception class for an invalid date
  class InvalidDate {
   private:
    short month;
    short day;
    short year;
    std::string
        errorType;  // error message saying what is invalid about the date

   public:
    InvalidDate(short month, short day, short year, std::string errorType) {
      this->month = month, this->day = day, this->year = year;
      this->errorType = errorType;
    }
    short getMonth() const { return month; }
    short getDay() const { return day; }
    short getYear() const { return year; }
    std::string getErrorType() const { return errorType; }
  };
  /**
   * @brief Default constructor (no parameters) creates a new Date object set to
   * January 1, 2023 (month = 1, day = 1, year = 2023)
   *
   */
  Date();
  /**
   * @brief Constructs a new Date object with the given month, day, and year,
   * uses checkDay() to determine if the given date is valid (an InvalidDate
   * error will be thrown if it is not)
   *
   * @param month (short)
   * @param day (short)
   * @param year (short)
   */
  Date(short month, short day, short year);
  /**
   * @brief Sets an existing Date object's member variables to match the given
   * Date object's member variables
   *
   * @param date
   */
  void set(Date date);
  /**
   * @brief Sets an existing Date object's member variables to the given month,
   * and year. Uses checkDay() to determine if the given date is valid (an
   * InvalidDate error will be thrown if it is not)
   *
   * @param month (short)
   * @param day (short)
   * @param year (short)
   */
  void set(short month, short day, short year);

  // Getters
  short getMonth() const { return month; }
  short getDay() const { return day; }
  short getYear() const { return year; }

  /**
   * @brief Returns a string with the date in the following format:
   * MM/DD/year
   *
   * @return std::string
   */
  std::string toString() const;

  // Overloaded comparison operators
  //      use compareDates(); an earlier date is considered less than a newer
  //      date and vice versa
  bool operator<(const Date &right) const;
  bool operator>(const Date &right) const;
  bool operator<=(const Date &right) const;
  bool operator>=(const Date &right) const;
  bool operator==(const Date &right) const;
  bool operator!=(const Date &right) const;

  // Overloaded ouput and input operators
  friend std::ostream &operator<<(std::ostream &,
                                  const Date &obj);  // uses toString()
  friend std::istream &operator>>(
      std::istream &,
      Date &obj);  // uses checkDay() -- may throw InvalidDate exception
};
