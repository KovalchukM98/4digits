#ifndef LEADERBOARD_TEST
#define LEADERBOARD_TEST

#include <gtest/gtest.h>
#include <leaderboard.h>
#include <string>

TEST(LEADERBOARD, isFileOpen)
{
    Leaderboard testboard;
    ASSERT_TRUE(testboard.load_from_file("data/records"));
    ASSERT_FALSE(testboard.load_from_file("src/records"));
}
TEST(LEADERBOARD, isNameValid)
{
    std::string str;
    Leaderboard testboard;
    str = "Name";
    ASSERT_TRUE(testboard.is_name_valid(str));
    str = "Anything123";
    ASSERT_TRUE(testboard.is_name_valid(str));
    str = "123";
    ASSERT_TRUE(testboard.is_name_valid(str));
    str = "Anything 123";
    ASSERT_FALSE(testboard.is_name_valid(str));
    str = " ";
    ASSERT_FALSE(testboard.is_name_valid(str));
    str = "wwwwwwwwwwwwwwww";
    ASSERT_FALSE(testboard.is_name_valid(str));
}

TEST(LEADERBOARD, Insert)
{
    std::string str;
    std::string testname;
    Leaderboard testboard;
    testboard.clear();
    str = "Name";
    int testurns = 10;
    int pos = 1;
    testboard.insert(str, testurns, pos);
    ASSERT_EQ(testboard.get_record(pos).second, 10);
    ASSERT_EQ(testboard.get_record(pos).first, str);
    for (int i = 0; i < 7; ++i) {
        str = "Name";
        str += std::to_string(i);
        testurns = 50 + i;
        testboard.insert(str, testurns, pos);
    }
    ASSERT_EQ(testboard.get_record(9).first, " ");
    ASSERT_EQ(testboard.get_record(9).second, 0);
    str = "Name50";
    testurns = 50;
    testboard.insert(str, testurns, pos);
    ASSERT_EQ(testboard.get_record(9).first, "Name");
    ASSERT_EQ(testboard.get_record(9).second, 10);
    str = "Name40";
    testurns = 40;
    testboard.insert(str, testurns, pos);
    ASSERT_EQ(testboard.get_record(9).first, "Name0");
    ASSERT_EQ(testboard.get_record(9).second, 50);
}

TEST(LEADERBOARD, isDataValid)
{
    std::string str;
    Leaderboard testboard;
    str = "Name 10";
    ASSERT_TRUE(testboard.is_data_valid(str));
    str = "200 10";
    ASSERT_TRUE(testboard.is_data_valid(str));
    str = "1";
    ASSERT_FALSE(testboard.is_data_valid(str));
    str = "";
    ASSERT_FALSE(testboard.is_data_valid(str));
}

#endif