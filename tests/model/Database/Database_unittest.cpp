#include "../../../src/model/Database.h"
#include "gtest/gtest.h"

class DatabaseTest : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        testDBFile = "Passmang.db";
        db = new Database(testDBFile);
    }

    void TearDown() override { delete db; }

    std::string testDBFile;
    Database* db;
};

TEST_F(DatabaseTest, Constructor)
{
    EXPECT_NO_THROW(Database("Passmang.db"));
}

TEST_F(DatabaseTest, InsertRecord)
{
    // Test inserting into a valid table (adjust table and schema to your
    // database)
    EXPECT_TRUE(db->insertRecord(
        "User",
        "1, 'Test User', 'password123', 'admin', '2024-12-04 12:00:00'"));
}

TEST_F(DatabaseTest, RetrieveRecord)
{
    std::string record = db->retrieveRecord("User", "UserID=1");
    EXPECT_FALSE(record.empty());
    EXPECT_NE(record.find("Test User"), std::string::npos);
}

TEST_F(DatabaseTest, UpdateRecord)
{
    EXPECT_TRUE(
        db->UpdateRecord("User", "Username='Updated User'", "UserID=1"));
    std::string record = db->retrieveRecord("User", "UserID=1");
    EXPECT_NE(record.find("Updated User"), std::string::npos);
}

TEST_F(DatabaseTest, DeleteRecord)
{
    EXPECT_TRUE(db->DeleteRecord("User", "UserID=1"));
    std::string record = db->retrieveRecord("User", "UserID=1");
    EXPECT_EQ(record, "");
}
/*
TEST_F(DatabaseTest, ValidateUser) {
    // Test user credentials
    std::string testUsername = "TestUser";
    std::string testPassword = "password123";
    std::string hashedPassword = HashClass::ToHash(testPassword);

    // Insert the user into the database
    std::string testData = "9, '" + testUsername + "', '" + hashedPassword + "',
'admin', '2024-12-04 12:00:00'"; EXPECT_TRUE(db->insertRecord("Users",
testData));

    // Validate user with correct credentials
    EXPECT_TRUE(db->validateUser(testUsername, testPassword));

    // Validate user with incorrect password
    EXPECT_FALSE(db->validateUser(testUsername, "wrongPassword"));

    // Cleanup
    EXPECT_TRUE(db->DeleteRecord("Users", "UserID=9"));
}*/
