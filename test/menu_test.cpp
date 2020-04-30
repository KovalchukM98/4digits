#include <game.h>
#include <gtest/gtest.h>
#include <menu.h>
#include <string>

TEST(MENU, is_menu_input_valid)
{
    std::string teststring;
    Menu test;
    teststring = "1";
    ASSERT_EQ(true, test.is_menu_input_valid(teststring));
    teststring = "2";
    ASSERT_EQ(true, test.is_menu_input_valid(teststring));
}
TEST(MENU, isInValid)
{
    std::string teststring;
    Menu test;
    teststring = "12";
    ASSERT_EQ(false, test.is_menu_input_valid(teststring));
    teststring = " ";
    ASSERT_EQ(false, test.is_menu_input_valid(teststring));
    teststring = "a";
    ASSERT_EQ(false, test.is_menu_input_valid(teststring));
    teststring = "6";
    ASSERT_EQ(false, test.is_menu_input_valid(teststring));
}

TEST(MENU, is_settings_input_valid)
{
    std::string str;
    Menu test_menu;
    str = "2";
    ASSERT_TRUE(test_menu.is_settings_input_valid(str));
    str = "9";
    ASSERT_TRUE(test_menu.is_settings_input_valid(str));
    str = "10";
    ASSERT_FALSE(test_menu.is_settings_input_valid(str));
    str = "+";
    ASSERT_FALSE(test_menu.is_settings_input_valid(str));
    str.clear();
    ASSERT_FALSE(test_menu.is_settings_input_valid(str));
}