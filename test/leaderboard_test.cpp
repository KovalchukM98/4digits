#ifndef LEADERBOARD_TEST
#define LEADERBOARD_TEST

#include <gtest/gtest.h>
#include <leaderboard.h>
#include <string>

TEST(LEADERBOARD, isNameValid)
{
    std::string teststring;
    Leaderboard testboard;
    teststring = "Name";
    ASSERT_TRUE(testboard.is_name_valid(teststring));
    teststring = "Anything123";
    ASSERT_TRUE(testboard.is_name_valid(teststring));
    teststring = "123";
    ASSERT_TRUE(testboard.is_name_valid(teststring));
}

TEST(LEADERBOARD, isNameInvalid)
{
    std::string teststring;
    Leaderboard testboard;
    teststring = " ";
    ASSERT_FALSE(testboard.is_name_valid(teststring));
    teststring = "wwwwwwwwwwwwwwww";
    ASSERT_FALSE(testboard.is_name_valid(teststring));
}

TEST(LEADERBOARD, isDataValid)
{
    std::string teststring;
    Leaderboard testboard;
    teststring = "Name 10";
    ASSERT_TRUE(testboard.is_data_valid(teststring));
    teststring = "200 10";
    ASSERT_TRUE(testboard.is_data_valid(teststring));
}

TEST(LEADERBOARD, isDataInvalid)
{
    std::string teststring;
    Leaderboard testboard;
    teststring = "1";
    ASSERT_FALSE(testboard.is_data_valid(teststring));
    teststring = "";
    ASSERT_FALSE(testboard.is_data_valid(teststring));
}

#endif