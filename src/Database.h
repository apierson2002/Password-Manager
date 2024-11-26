#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>

class Database {
  public:
    database(const std::string& dbFile);
    ~Database();

    bool LoginHandler(const std::string& username, const std::string& password);
    bool RoleCheck(const std::string& role);
    bool GetCredentialList();
    bool GetUserList();
    bool GetOneUser(int UserID);
    bool GetOneCredential(int CredentialID);
    bool AddUser(const std::string& username, const std::string& password, const std::string& role);
    bool AddCredential(const std::string& username, const std::string& password, const std::string& email, const std::string& description, int userID);
    bool DeleteUser(int UserID);
    bool DeleteCredential(int CredentialID);
    bool EditUser(int UserID, const std::string& username, const std::string& password, const std::string& role);
    bool EditCredential(int CredentialID, const std::string& username, const std::string& password, const std::string& email, const std::string& description);

  private:
    std::string dbFileName;
};

#endif // DATABASE_H
