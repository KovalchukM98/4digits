#include <gtest/gtest.h>
#include <leaderboard.h>
#include <string>

TEST(LEADERBOARD, isNameValid) {
  std::string teststring;
  Leaderboard testboard;
  teststring = "Name";
  ASSERT_EQ(true, testboard.is_name_valid(teststring));
  teststring = "Anything123";
  ASSERT_EQ(true, testboard.is_name_valid(teststring));
  teststring = "123";
  ASSERT_EQ(true, testboard.is_name_valid(teststring));
}

TEST(LEADERBOARD, isNameInvalid) {
  std::string teststring;
  Leaderboard testboard;
  teststring = " ";
  ASSERT_EQ(false, testboard.is_name_valid(teststring));
}