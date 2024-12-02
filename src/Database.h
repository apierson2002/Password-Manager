#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>

class Database {
  public:
    Database(const std::string& dbFile);
    ~Database();

    //User
    std::vector<std::vector<std::string>> GetUserList();
    bool LoginHandler(const std::string& username, const std::string& password, Role r);
    bool EditUser(int UserID, const std::string& username, const std::string& password, const Role r);
    bool DeleteUser(int UserID, const Role r);
    bool GetOneUser(int UserID, const Role r);
    bool AddUser(const std::string& username, const std::string& password, const Role r);

    //Credential
    std::vector<std::vector<std::string>> GetCredentialList();
    bool AddCredential(const std::string& username, const std::string& password, const std::string& email, const std::string& description, int userID, Role r);
    bool DeleteCredential(int CredentialID, Role r);
    bool GetOneCredential(int CredentialID);
    bool EditCredential(int CredentialID, const std::string& username, const std::string& password, const std::string& email, const std::string& description, Role r);

  private:
    sqlite3* dbFile;
    bool executeQuery
    bool executeNonQuery
};


#endif // DATABASE_H
