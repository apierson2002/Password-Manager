#ifndef USER_LIST_H
#define USER_LIST_H

#include <vector> 
#include <string>

#include "User.h"
#include "UserType.h"


namespace User{
class userList::public User
{
	private:
		std::vector<User> uList;
		bool getUserLogin(User, User); /* Not sure what the NULL parameter 
						      is there for or how I'd go about
						      implementing it */
		std::vector<User> getUserList();
		User getUser(const User&, int);
		bool ADDuSER(User, User, userType, User);
		bool editUser(User, User, userType, User);
		bool searchUser(const User&);
		bool deleteUser(User&);
		
			
};
}
#endif
