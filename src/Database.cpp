nclude "Database.h"
#include <sqlite3.h>
#include <iostream>
#include <stdexcept>


Database::Database(const std::string& dbFile) : dbFileName(dbFile) {


}

Database::~Database() {

}

Database::~Database() {

}

bool Database::LoginHandler(const std::string& username, const std::string& password) {

}

bool Database::RoleCheck(const std::string& role) {

}

bool Database::GetCredentialList() {

}

bool Database::GetUserList() {
}

bool Database::GetOneUser(int UserID) {
}

bool Database::GetOneCredential(int CredentialID) {
}

bool Database::AddUser(const std::string& username, const std::string& password, const std::string& role) {

}

bool Database::AddCredential(const std::string& username, const std::string& password, const std::string& email, const std::string& description, int userID) {
}

bool Database::DeleteUser(int UserID) {
}

bool Database::DeleteCredential(int CredentialID) {
}

bool Database::EditUser(int UserID, const std::string& username, const std::string& password, const std::string& role) {
}

bool Database::EditCredential(int CredentialID, const std::string& username, const std::string& password, const std::string& email, const std::string& description) {

}
