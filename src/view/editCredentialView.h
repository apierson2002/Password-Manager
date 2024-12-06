/*
 * Password Manager - Witty Application
 *
 * View - Add a Credential to the list
 * jathur, Tristen 12/05/24
 */


#include "CredentialForm.h"

#ifndef EDITCREDENTIALVIEW_H
#define EDITCREDENTIALVIEW_H

class editCredentialView : public CredentialForm
{
  public:
    // editCredentialView() = delete;
    editCredentialView(); // explicit editCredentialView(passMang::CredentialList&
                         // cl);

  private:
    void editNewCredential();
};

#endif /* EDITCREDENTIALVIEW_H */
