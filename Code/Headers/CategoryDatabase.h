/*
Author: Mia Kelley-Lanser
Class: Advanced C++
Date: 05/07/2023
*/

#pragma once

#include <vector>

#include "Category.h"

// Forward class declaration for friend ostream overloaded operator
class CategoryDatabase;
std::ostream &operator<<(std::ostream &, const CategoryDatabase &);

class CategoryDatabase {
 private:
  std::vector<Category> categories;  // vector of created categories

 public:
  /**
   * @brief CategoryDatabase default constructor
   *
   */
  CategoryDatabase();
  /**
   * @brief CategoryDatabase constructor with categories parameter; copies
   * elements of the given categories vector<Category> into this categories
   * vector<Category>; uses addCategory() method to add them-- throws an
   * invalid_argument error if there are any duplicate elements
   *
   * @param categories
   */
  CategoryDatabase(std::vector<Category> categories);

  /**
   * @brief Searches for the given category in the categories
   * vector<Category>; returns the index of the category if found, or -1 if not
   * found
   *
   * @param category (string)
   * @return int
   */
  int findCategoryIndex(std::string category);
  /**
   * @brief Searches for the given subcategory in the subcategories
   * vector<string> of the Category object with the given title; returns the
   * index of the subcategory if found, or -1 if not found; also returns -1 if
   * no Category object exists with the given title
   *
   * @param category (string)
   * @param subcategory (string)
   * @return int
   */
  int findSubcategoryIndex(std::string category, std::string subcategory);
  /**
   * @brief Adds the given category to the categories vector<Category>;
   * throws an invalid_argument error if the category already exists
   *
   * @param category (Category)
   */
  void addCategory(Category category);
  /**
   * @brief Adds the given subcategory to the Category object with the given
   * category title; if no such Category object exists, adds new category with
   * the given title and subcategory; throws an invalid_argument if the Category
   * object with the given title already has a subcategory with the same name
   *
   * @param category (string)
   * @param subcategory (string)
   */
  void addSubcategory(std::string category, std::string subcategory);
  /**
   * @brief Removes the given category from the categories vector<Category>;
   * throws an invalid_argument error if the category does not exist
   *
   * @param category (Category)
   */
  void deleteCategory(Category category);
  /**
   * @brief Clears the categories vector<Category> if it ist not already empty
   *
   */
  void deleteAllCategories();

  /**
   * @brief CategoryDatabase class toString() method; returns a string listing
   * all the categories with their titles and subcategories in the following
   * format:
   *
   * Category: (title)
   * Subcategories: (subcategory), (subcategory), etc.
   *
   * Category: (title2)
   * Subcategories: (subcategory), (subcategory), etc.
   *
   * @return std::string
   */
  std::string toString() const;

  // Setter
  void setCategories(
      std::vector<Category>
          categories);  // clears current categories vector<Category>, then
                        // adds each given category (throws an
                        // invalid_argument error if there are any duplicate
                        // elements)

  // Getter
  std::vector<Category> getCategories() const { return categories; }

  // Overloaded ouput operator
  //    format:
  //    (title): (subcategory), (subcategory), etc.
  //    (title2): (subcategory), (subcategory), etc.
  friend std::ostream &operator<<(std::ostream &, const CategoryDatabase &obj);
};
