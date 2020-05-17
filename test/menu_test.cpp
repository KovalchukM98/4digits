#ifndef MENU_TEST
#define MENU_TEST

#include <game.h>
#include <gtest/gtest.h>
#include <menu.h>
#include <string>

TEST(MENU, is_menu_input_valid)
{
    std::string str;
    Menu menu;
    str = "1";
    ASSERT_TRUE(menu.is_input_valid(str, 1, 5));
    str = "2";
    ASSERT_TRUE(menu.is_input_valid(str, 1, 5));
    str = "2";
    ASSERT_FALSE(menu.is_input_valid(str, 3, 5));
}

#endif