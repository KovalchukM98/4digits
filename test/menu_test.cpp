#include "Menu.h"
#include <gtest/gtest.h>
#include <string>

TEST(MENU, isValid)
{
    std::string teststring;
    Menu test;
    teststring = "1";
    ASSERT_EQ(true, test.is_valid(teststring));
    teststring = "2";
    ASSERT_EQ(true, test.is_valid(teststring));
}
TEST(MENU, isInValid)
{
    std::string teststring;
    Menu test;
    teststring = "12";
    ASSERT_EQ(false, test.is_valid(teststring));
    teststring = " ";
    ASSERT_EQ(false, test.is_valid(teststring));
    teststring = "a";
    ASSERT_EQ(false, test.is_valid(teststring));
    teststring = "6";
    ASSERT_EQ(false, test.is_valid(teststring));
}