#ifndef LEADERBOARD_TEST
#define LEADERBOARD_TEST

#include <gtest/gtest.h>
#include <leaderboard.h>
#include <string>

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

TEST(LEADERBOARD, is_new_record)
{
    Leaderboard board;
    ASSERT_TRUE(board.load_from_file("data/test_records.txt"));
    ASSERT_EQ(board.is_new_record(1), 0);
    ASSERT_EQ(board.is_new_record(10), 1);
    ASSERT_EQ(board.is_new_record(20), 2);
    ASSERT_EQ(board.is_new_record(22), 2);
    ASSERT_EQ(board.is_new_record(39), 3);
    ASSERT_EQ(board.is_new_record(40), 4);
    ASSERT_EQ(board.is_new_record(400), -1);
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

TEST(LEADERBOARD, load_from_file)
{
    Leaderboard board;
    ASSERT_FALSE(board.load_from_file("false"));
    board.clear();
    ASSERT_TRUE(board.load_from_file("data/test_records.txt"));
    ASSERT_EQ(board.get_record(0).first, "player1");
    ASSERT_EQ(board.get_record(0).second, 10);
    ASSERT_EQ(board.get_record(2).first, "player3");
    ASSERT_EQ(board.get_record(2).second, 30);
    ASSERT_EQ(board.get_record(9).first, "player10");
    ASSERT_EQ(board.get_record(9).second, 100);
}

#endif