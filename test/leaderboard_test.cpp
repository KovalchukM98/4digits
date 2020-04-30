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
TEST(LEADERBOARD, Insert)
{
    std::string teststring;
    std::string testname;
    Leaderboard testboard;
    teststring = "Name";
    int testurns = 10;
    int pos = 1;
    testboard.insert(teststring, testurns, pos);
    ASSERT_EQ(testboard.get_record(pos).second, 10);
    ASSERT_EQ(testboard.get_record(pos).first, teststring);
    // teststring = "SMTHNG";
    // pos = 2;
    // testurns = 50;
    // testboard.insert(teststring, testurns, pos);
    // ASSERT_EQ(testboard.get_record(pos).second, 50);
    // ASSERT_EQ(testboard.get_record(pos).first, teststring);
    // teststring = "yes";
    // pos = 2;
    // testurns = 40;
    // testboard.insert(teststring, testurns, pos);
    // ASSERT_EQ(testboard.get_record(3).second, 50);
    // teststring = "SMTHNG";
    // ASSERT_EQ(testboard.get_record(3).first, teststring);
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