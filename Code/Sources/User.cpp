#include "User.h"
#include "QtCore/qlogging.h"

#include <sstream>
#include <string>
#include <string_view>

#include <QByteArray>

namespace users {
User::User(std::string_view userName, std::string_view password, int userID)
    : m_userName(userName), m_password(password) {
  setUserID(userID);
}
void User::setUserID(int userID) {
    if (userID < 0) userID = 0;
    m_userID = userID;
}
std::string User::encryptDecrypt(std::string text) const {
  int length = text.length();
  std::string newText = "";
  for (int i = 0; i < length; i++) {
    int keyIndex = i % encryptionKey.length();
    newText += text[i] ^ encryptionKey[keyIndex];
  }
  return newText;
}
std::string User::encrypt_b64(std::string text) const {
 QByteArray qba_text;
 qba_text.append(text);
 return std::string(qba_text.toBase64());
}
std::string User::decrypt_b64(std::string text) const {
 QByteArray qba_text;
 qba_text.append(text);
 return std::string(QByteArray::fromBase64(qba_text));
}
std::string User::toString() const {
  std::stringstream ss;
  ss << "Username: " << m_userName << "\nPassword: " << m_password
     << "\nUser ID: " << m_userID << std::endl;
  return ss.str();
}
std::ostream &operator<<(std::ostream &os, const User &obj) {
  std::string user = obj.getUserName();
  std::string pass = obj.encrypt_b64(obj.encryptDecrypt(obj.getPassword()));
  os << obj.getUserID() << "\n"
     << user << "\n"
     << pass << "\n\n";
  return os;
}
std::istream &operator>>(std::istream &is, User &obj) {
  std::string input;

  getline(is, input, '\n');
  if (is.eof()) {
      return is;
  }
  try {
    obj.setUserID(stoi(input));
  } catch (std::invalid_argument e)  {
  }

  getline(is, input, '\n');
  std::string un = input;
  obj.setUserName(input);
  getline(is, input);
  std::string pass = obj.encryptDecrypt(obj.decrypt_b64(input));
  obj.setPassword(pass);
  getline(is, input); // blank line
  return is;
}
}  // namespace users
