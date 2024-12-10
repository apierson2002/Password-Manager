/*
 * Password Manager - Witty Application
 *
 * View - Search Credential
 * momerk, 12/7/2024
 */

#include "CredentialForm.h"
#include "Database.h"
#include "userType.h"

#ifndef SEARCHCREDVIEW_H
#define SEARCHCREDVIEW_H

class searchCredView : public CredentialForm
{
  public:
    // searchCredView() = delete;
    searchCredView(Database& db,
                   passMang::Role userRole,
                   const std::string& userID);

  private:
    void searchCred();
    Database& db;
    passMang::Role userRole;
    const std::string& userID;
    Wt::WGroupBox* resultBox;
    Wt::WContainerWidget* contentContainer;
};

#endif /* SEARCHCREDVIEW_H */
