/*
Author: Mia Kelley-Lanser
Class: Advanced C++
Date: 05/07/2023
*/

#pragma once

#include <string>
#include <vector>

// Forward class declaration for friend ostream overloaded operator
class Category;
std::ostream &operator<<(std::ostream &, const Category &);

class Category {
 private:
  std::string title;                       // name of the category
  std::vector<std::string> subcategories;  // vector of names of subcategories

 public:
  /**
   * @brief Category constructor with title parameter; sets title to the given
   * string
   *
   * @param title (string)
   */
  Category(std::string title);
  /**
   * @brief Category constructor with title and one subcategory parameters; sets
   * title to the given string and adds the given subcategory to the
   * subcategories vector
   *
   * @param title (string)
   * @param subcategory (string)
   */
  Category(std::string title, std::string subcategory);
  /**
   * @brief Category constructor with title and subcategories vector<string>
   * parameters; sets title to the given string and copies elements of the given
   * subcategory vector<string> into this subcategories vector<string>; uses
   * addSubcategory() method to add them-- throws an invalid_argument error if
   * there are any duplicate elements
   *
   * @param title (string)
   * @param subcategories (vector<string>)
   */
  Category(std::string title, std::vector<std::string> subcategories);

  /**
   * @brief Searches for the given subcategory in the subcategories
   * vector<string>; returns the index of the subcategory if found, or -1 if not
   * found
   *
   * @param subcategory (string)
   * @return int
   */
  int findSubcategoryIndex(std::string subcategory);
  /**
   * @brief Adds the given subcategory to the subcategories vector<string>;
   * throws an invalid_argument error if the subcategory already exists
   *
   * @param subcategory (string)
   */
  void addSubcategory(std::string subcategory);
  /**
   * @brief Removes the given subcategory from the subcategories vector<string>;
   * throws an invalid_argument error if the subcategory does not exist
   *
   * @param subcategory (string)
   */
  void deleteSubcategory(std::string subcategory);
  /**
   * @brief Clears the subcategories vector<string> if it ist not already empty
   *
   */
  void deleteAllSubcategories();

  /**
   * @brief  Category class toString() method; returns a string listing the
   * category title and subcategories in the following format:
   *
   * Category: (title)
   * Subcategories: (subcategory), (subcategory), etc.
   *
   * @return std::string
   */
  std::string toString() const;

  // Setters
  void setTitle(std::string title) { this->title = title; }
  void setSubcategories(
      std::vector<std::string>
          subcategories);  // clears current subcategories vector<string>, then
                           // adds each given subcategory (throws an
                           // invalid_argument error if there are any duplicate
                           // elements)

  // Getters
  std::string getTitle() const { return title; }
  std::vector<std::string> getSubcategories() const { return subcategories; }
  std::string getSubcategoriesString()
      const;  // returns a string listing the subcategories

  // Overloaded ouput operator
  //    format: (title): (subcategory), (subcategory), etc.
  friend std::ostream &operator<<(std::ostream &, const Category &obj);
};
