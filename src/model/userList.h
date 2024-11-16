#ifndef USER_LIST_H
#define USER_LIST_H

#include <vector> 
#include <string>

#include "User.h"
#include "UserType.h"



class userList::public User
{
	private:
		std::vector<string> uList;
		bool addUser(int, User, userType); /* Not sure what the NULL parameter 
						      is there for or how I'd go about
						      implementing it */
		bool deleteUser();
		bool getUser();
		bool searchUser();
		
			
};
#endif
