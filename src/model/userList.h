#ifndef USER_LIST_H
#define USER_LIST_H

#include <forward_list> 
#include <string>

#include "User.h"
#include "UserType.h"



class userList::public User
{
	private:
		std::forward_list<User> uList;
	public:
		userList() = delete; // don't have parameterless constructor
		userList(char**);
		
		
			
};
#endif
