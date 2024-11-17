#include "userList.h"
#include <algorithm>

bool userList::addUser(int id, User user, userType role)
{
	/*
	 * IMPORTANT NOTES
	 * ---------------
	 *  auto: figures out var type for iterators
	 *  find_if: searches for an element that matches a certain condition (std library)
	 *  [&user]: capture list 
	 *  
	 */		// go from the star to the end of the vector. Capture list reference of User object u
	auto it = std::find_if(userList.begin(), userList.end(), [&user](const User& u)
	{
		return u.getUsername() == user.getUsername();//if the user exists, don't add em to the list
	});

	if(it != userList.end()) // if your iterator didn't make it to the end of the list 
				 // then it can't be added
		return false;
	User newUser(id, user.getUsername(), user.getPassword(), role);// create a User object
	userList.push_back(newUser);// add newUser to end of the vector 

	return true;
}

bool userList::deleteUser()
{
	// Find user by userName using std::find_if
	auto it = std::find_if(userList.begin(), userList.end(), [&username](const User& u)
	{
		return u.getUsername() == username;//verify the user is in the list
	});

	if(it != username)// check if the user was found
	{
		userList.erase(it);// if found, delete user
		return true;// user deleted
	}

	return false;

}

bool userList::getUser(const User& currentUser)
{
	return getUser(currentUser);
}

bool userList::searchUser(const User& currentUser)
{
	// Use std::find_if to search for a user by their username
	auto it = std::find_if(userList.begin(), userList.end(), [&currentUser](const User& u)
	{
		return u.getUsername() == currentUser.getUsername();  // Check if the username matches
	});

	// If the iterator is not equal to the end, the user was found
	return it != userList.end();
}
