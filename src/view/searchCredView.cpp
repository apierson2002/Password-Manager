/*
 * Password Manager - Witty Application
 *
 * View - Search Credential
 * momerk, 12/7/2024
 */

#include <memory>
#include <sstream>
#include <string>

#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WGroupBox.h>
#include <Wt/WPushButton.h>
#include <Wt/WString.h>
#include <Wt/WText.h>

#include "searchCredView.h"

using namespace Wt;

searchCredView::searchCredView(Database& db, passMang::Role userRole, const std::string& userID) :
    db(db), userRole(userRole), userID(userID)
{
    CredentialForm(false);
    addButton->setText("Search");
    addButton->clicked().connect(this, &searchCredView::searchCred);

    addWidget(std::make_unique<WBreak>());
    resultBox = addWidget(std::make_unique<Wt::WGroupBox>("Results"));
    contentContainer =
        resultBox->addWidget(std::make_unique<Wt::WContainerWidget>());

    // if user role is admin, then show all credentials for all users
    if (userRole == passMang::Role::Admin) {
        addWidget(std::make_unique<WBreak>());
        addWidget(std::make_unique<WBreak>());

        // create box for credentials
        auto credBox =
            std::make_unique<Wt::WGroupBox>("All Credentials for All Users");
        // get all credentials
        std::string allCredentials = db.retrieveRecord("Credentials", "1=1");

        // parse credentials recieved
        std::stringstream credSS(allCredentials);
        std::string credID, name, username, password, email, descrip,
            lastChange, uID;

        while (std::getline(credSS, credID, ',')) {
            if (credSS.eof()) {
                break;
            }

            // parse credential to get cred attributes
            std::getline(credSS, name, ',');
            std::getline(credSS, username, ',');
            std::getline(credSS, password, ',');
            std::getline(credSS, email, ',');
            std::getline(credSS, descrip, ',');
            std::getline(credSS, lastChange, ',');

            // handle the period seperating the userID and the next record
            std::getline(credSS, uID, '.');

            // add credential to credential box
            credBox->addWidget(
                std::make_unique<Wt::WText>("Credential ID: " + credID));
            credBox->addWidget(std::make_unique<WBreak>());
            credBox->addWidget(std::make_unique<Wt::WText>("Name: " + name));
            credBox->addWidget(std::make_unique<WBreak>());
            credBox->addWidget(
                std::make_unique<Wt::WText>("Username: " + username));
            credBox->addWidget(std::make_unique<WBreak>());
            credBox->addWidget(
                std::make_unique<Wt::WText>("Password: " + password));
            credBox->addWidget(std::make_unique<WBreak>());
            credBox->addWidget(std::make_unique<Wt::WText>("Email: " + email));
            credBox->addWidget(std::make_unique<WBreak>());
            credBox->addWidget(
                std::make_unique<Wt::WText>("Description: " + descrip));
            credBox->addWidget(std::make_unique<WBreak>());
            credBox->addWidget(
                std::make_unique<Wt::WText>("Last Changed: " + lastChange));
            credBox->addWidget(std::make_unique<WBreak>());
            credBox->addWidget(std::make_unique<Wt::WText>("User ID: " + uID));
            credBox->addWidget(std::make_unique<WBreak>());
            credBox->addWidget(std::make_unique<Wt::WText>(
                "-------------------------------------"));
            credBox->addWidget(std::make_unique<WBreak>());
        }
        // add cred box to view
        addWidget(std::move(credBox));
    }
}

void
searchCredView::searchCred()
{
    contentContainer->clear();

    bool isID, isUsername, isEmail, isName, isDescrip, isMatch;
    std::string stringId, username, email, name, descrip;
    std::string credRecord, criteria;
    // int id;

    // Check for inputs ------------------------------------------------
    stringId = WString(idEdit->text()).toUTF8();
    if (stringId.empty())
        isID = false;
    else {
        // id = std::stoi(stringId);
        isID = true;
    }

    username = WString(usernameEdit->text()).toUTF8();
    if (username.empty())
        isUsername = false;
    else
        isUsername = true;

    email = WString(emailEdit->text()).toUTF8();
    if (email.empty())
        isEmail = false;
    else
        isEmail = true;

    name = WString(credNameEdit->text()).toUTF8();
    if (name.empty())
        isName = false;
    else
        isName = true;

    descrip = WString(descriptionEdit->text()).toUTF8();
    if (descrip.empty())
        isDescrip = false;
    else
        isDescrip = true;

    // std::cout << "STRING ID:" << stringId << std::endl;
    // std::cout << "USERNAME:" << username << std::endl;
    // std::cout << "EMAIL:" << email << std::endl;
    // std::cout << "NAME:" << name << std::endl;
    // std::cout << "DESCRIP:" << descrip << std::endl;

    //------------------------------------------------------------------

    // Search in order of valid inputs: credential ID, username, email
    isMatch = false;

    if (isID) {
        // Search by credential ID
        if (userRole == passMang::Role::Admin)
		criteria = "CredentialID=" + stringId;
	else
		criteria = "CredentialID="+ stringId + " AND UserID="+ userID;        

	credRecord = db.retrieveRecord("Credentials", criteria);

        if (! credRecord.empty())
            isMatch = true;
    }

    if (isUsername && ! isMatch) {
        // Search by username
        if (userRole == passMang::Role::Admin)
        	criteria = "CredUsername='" + username + "'";
        else
        	criteria = "CredUsername='" + username + "' AND UserID="+ userID;
	
	credRecord = db.retrieveRecord("Credentials", criteria);

        if (! credRecord.empty())
            isMatch = true;
    }

    if (isEmail && ! isMatch) {
        // Search by email
        if (userRole == passMang::Role::Admin)
        	criteria = "CredEmail='" + email + "'";
        else
        	criteria = "CredEmail='" + email + "' AND UserID="+ userID;
	
	credRecord = db.retrieveRecord("Credentials", criteria);

        if (! credRecord.empty())
            isMatch = true;
    }

    if (isName && ! isMatch) {
        // Search by cred name
        if (userRole == passMang::Role::Admin)
        	criteria = "CredName='" + name + "'";
        else
        	criteria = "CredName='" + name + "' AND UserID="+ userID;
	
	credRecord = db.retrieveRecord("Credentials", criteria);

        if (! credRecord.empty())
            isMatch = true;
    }

    if (isDescrip && ! isMatch) {
        // Search by description
        if (userRole == passMang::Role::Admin)
        	criteria = "CredDescription='" + descrip + "'";
        else
        	criteria = "CredDescription='" + descrip + "' AND UserID="+ userID;

	credRecord = db.retrieveRecord("Credentials", criteria);

        if (! credRecord.empty())
            isMatch = true;
    }

    // Display results
    if (isMatch) {
        // resultBox->clear();
        // resultBox->setTitle("Results");
        // resultBox->addWidget(std::make_unique<Wt::WText>(credRecord));
        contentContainer->addWidget(std::make_unique<Wt::WText>(credRecord));
    } else {
        wApp->setInternalPath("/search-failure", true);
    }
}
