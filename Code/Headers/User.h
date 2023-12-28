/*
Author: Mia Kelley-Lanser
Date: 05/07/2023
All rights reserved
*/

#pragma once

#include <string>
#include <string_view>

namespace users {
// Forward class declaration for friend ostream and istream overloaded operators
class User;
std::ostream &operator<<(std::ostream &, const User &);
std::istream &operator>>(std::istream &, User &);

class User {
 private:
  std::string m_userName;
  std::string m_password;
  int m_userID;
  std::string encryptionKey = "HkDFEhSjsqo";

  void setUserID(int userID);

 protected:
  /**
   * @brief Encrypts or decrypts (same function) the given string using encryptionKey;
   * works like a Vignere cipher with XOR
   * @param text (string)
   * @return
   */
  std::string encryptDecrypt(std::string text) const;
  /**
   * @brief Used in conjunction with encryptDecrypt method-- returns encrypted string
   * encoded in b64 to handle non-ASCII characters and newlines
   * @param text (string)
   * @return
   */
  std::string encrypt_b64(std::string text) const;
  /**
   * @brief Used in conjunction with encryptDecrypt method-- returns decrypted string
   * encoded in b64 to handle non-ASCII characters and newlines
   * @param text (string)
   * @return
   */
  std::string decrypt_b64(std::string text) const;

  // protected setter-- userName is only set in constructor
  void setUserName(std::string_view userName) { m_userName = userName; }

 public:
  /**
   * @brief Constructs a new User object with the given username and password;
   * m_userID is set to the current value of m_nextUserID (which starts at 1000
   * for the first instance of a User object), then increases the m_nextUserID
   * by 1
   *
   * @param userName (string_view)
   * @param password (string_view)
   */
  User(std::string_view userName, std::string_view password, int userID);

  // setter (don't need public setUserName since a user usually can change
  // password but not username -- permanent)
  void setPassword(std::string_view password) { m_password = password; }

  // getters
  std::string getUserName() const { return m_userName; }
  std::string getPassword() const { return m_password; }
  int getUserID() const { return m_userID; }

  /**
   * @brief User class toString(); returns a string with the username, password,
   * and user ID
   *
   * @return std::string
   */
  std::string toString() const;

  // Overloaded ouput and input operators (encrypts and decrypts password)
  friend std::ostream &operator<<(std::ostream &, const User &obj);
  friend std::istream &operator>>(std::istream &, User &obj);
};
}  // namespace users
