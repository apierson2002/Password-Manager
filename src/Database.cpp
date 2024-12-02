#include "Database.h"
#include <string>
#include <iostream>
#include <Wt/Dbo/Dbo.h>


Database::Database(const std:string& dbpath) {
  if (sqlite3_open(dbPath.c_str(), &db) != SQLITE_OK) {
    throw std::runtime_error("Failed to open database");
  }

}

Database::~Database() {
  sqlite3_close(db);
}

bool Database::LoginHandler(const std::string& username, const std::string& password) {
  auto sqlite3 = std::make_unique<dbo::backend::Sqlite3>("passmang.db");
  dbo::Session session;
  session.setConnection(std::move(sqlite3));
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
