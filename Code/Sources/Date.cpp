#include "Date.h"

#include <sstream>
#include <string>

void Date::checkDay() {
  if (day < 1)
    throw InvalidDate(month, day, year, "Day must be a positive integer.");
  if (month < 1 || month > 12)
    throw InvalidDate(
        month, day, year,
        "Month must be a positive integer less than or equal to 12.");
  if (year < 0)
    throw InvalidDate(month, day, year,
                      "Year must be an integer greater than or equal to 0.");
  if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
      month == 10 || month == 12) {
    if (day > 31)
      throw InvalidDate(month, day, year,
                        "There are only 31 days in the given month.");
  } else if (month == 2) {
    if (day > 29)
      throw InvalidDate(
          month, day, year,
          "There are never more than 29 days in the given month.");
  } else {
    if (day > 30)
      throw InvalidDate(month, day, year,
                        "There are only 30 days in the given month.");
  }
  if ((year % 4) != 0 && month == 2 && day == 29)
    throw InvalidDate(month, day, year,
                      "The given year is not a leap year and there are only 28 "
                      "days in the given month.");
}
Date::Date() {
  month = 1;
  day = 1;
  year = 2023;
}
Date::Date(short month, short day, short year) {
  this->month = month;
  this->day = day;
  this->year = year;
  checkDay();
}
void Date::set(Date date) {
  this->month = date.getMonth();
  this->day = date.getDay();
  this->year = date.getYear();
  checkDay();
}
void Date::set(short month, short day, short year) {
  this->month = month;
  this->day = day;
  this->year = year;
  checkDay();
}
std::string Date::toString() const {
  std::stringstream ss;
  if (month < 10) ss << '0';
  ss << month << '/';
  if (day < 10) ss << '0';
  ss << day << '/' << year;
  return ss.str();
}
int Date::compareDates(Date date1, Date date2) const {
  int comparison = 0;
  if (date1.year < date2.year) {
    comparison = -1;
    return comparison;
  }
  if (date1.year > date2.year) {
    comparison = 1;
    return comparison;
  }
  if (date1.month < date2.month) {
    comparison = -1;
    return comparison;
  }
  if (date1.month > date2.month) {
    comparison = 1;
    return comparison;
  }
  if (date1.day < date2.day) {
    comparison = -1;
    return comparison;
  }
  if (date1.day > date2.day) {
    comparison = 1;
    return comparison;
  }

  return comparison;
}
bool Date::operator<(const Date &right) const {
  Date temp(this->month, this->day, this->year);
  if (compareDates(temp, right) == -1)
    return true;
  else
    return false;
}
bool Date::operator>(const Date &right) const {
  Date temp(this->month, this->day, this->year);
  if (compareDates(temp, right) == 1)
    return true;
  else
    return false;
}
bool Date::operator<=(const Date &right) const {
  Date temp(this->month, this->day, this->year);
  if (compareDates(temp, right) == -1 || compareDates(temp, right) == 0)
    return true;
  else
    return false;
}
bool Date::operator>=(const Date &right) const {
  Date temp(this->month, this->day, this->year);
  if (compareDates(temp, right) == 1 || compareDates(temp, right) == 0)
    return true;
  else
    return false;
}
bool Date::operator==(const Date &right) const {
  Date temp(this->month, this->day, this->year);
  if (compareDates(temp, right) == 0)
    return true;
  else
    return false;
}
bool Date::operator!=(const Date &right) const {
  Date temp(this->month, this->day, this->year);
  if (compareDates(temp, right) != 0)
    return true;
  else
    return false;
}
std::ostream &operator<<(std::ostream &os, const Date &obj) {
  os << obj.toString();
  return os;
}
std::istream &operator>>(std::istream &is, Date &obj) {
  is >> obj.month >> obj.day >> obj.year;
  obj.checkDay();
  return is;
}
