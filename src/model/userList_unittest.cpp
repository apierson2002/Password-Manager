#include <gtest/gtest.h>
#include "UserType.h"
#include "User.h"
#include "userList.h"

namespace passMang
{
	TEST_F(UserListTest, AddUserTest)
	{
		User newUser(3, "charlie", "password789", UserType::Regular);
		User lastLogin;
		EXPECT_TRUE(userList.addUser(3, newUser, UserType::Regular, lastLogin));

		User existingUser(1, "alice", "password123", UserType::Admin);
		User lastLoginExisting;
		EXPECT_FALSE(userList.addUser(1, existingUser, UserType::Admin, lastLoginExisting));
	}

	TEST_F(UserListTest, SearchUserTest)
	{
		User searchUser(0, "bob", "password456", UserType::Regular);
		EXPECT_TRUE(userList.searchUser(searchUser));

		User nonExistentUser(0, "alice", "password123", UserType::Regular);
		EXPECT_FALSE(userList.searchUser(nonExistentUser));
	}

	TEST_F(UserListTest, DeleteUserTest)
	{
		User deleteUser(0, "alice", "passwrod123", UserType::Admin);
		EXPECT_TRUE(userList.deleteUser(deleteUser));

		User nonExistentUser(0, "eve", "password456", UserType::Regular);
		EXPECT_FALSE(userList.deleteUser(nonExistentUser));
	}

	TEST_F(UserListTest, EmptyUserListTest)
	{
		UserListTest emptyTest;
		User searchUser(0, "alice", "password123", UserType::Admin);
		EXPECT_FALSE(emptyTest.userList.searchUser(searchUser));
	}


} // end namespace
