/*
 * Password Manager - Witty Application
 *
 * Password Manager Application
 * mmerkle, jathur  12/3/2024
 */

// must include this file to use the Role enum
#include "userType.h"
// must include this file to access Database object
#include "Database.h"

#include <string>

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>

#ifndef PASSMANGAPP_H
#define PASSMANGAPP_H

using namespace Wt;

class passMangApp : public WApplication
{
  public:
    passMangApp() = delete;
    explicit passMangApp(const WEnvironment& env);

  private:
    void onInternalPathChange();
    void userLogin();
    bool checkLogin(const std::string& usernm, const std::string& pass);
    void createHeaderContainer();
    void createNavigationContainer();
    void updateNavigation();
    void showHomeScreen();
    void createFooterContainer();
    void addUser();
    void addCredential();
    void resultAddSuccess();
    void resultAddFailure();
    void searchCredential();
    void searchUser();
    void resultSearchFailure();
    void editCredential();
    void editUser();
    Database db;
    std::string appName;
    WContainerWidget* content;
    WContainerWidget* navigation;
    bool navCreated = false;
    int invalidCount = 0;
    passMang::Role userRole;
    int userID;
};

#endif /* PASSMANGAPP_H */
