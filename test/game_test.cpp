#ifndef GAME_TEST
#define GAME_TEST

#include "game.h"
#include "sequence.h"
#include <gtest/gtest.h>
#include <string>

TEST(GAME, is_valid)
{
    Game game_test(4);
    std::string str;
    ASSERT_FALSE(game_test.is_valid(str));
    str = "12a4";
    ASSERT_FALSE(game_test.is_valid(str));
    str = "12";
    ASSERT_FALSE(game_test.is_valid(str));
    str = "12345";
    ASSERT_FALSE(game_test.is_valid(str));
    str = "1233";
    ASSERT_FALSE(game_test.is_valid(str));
    str = "1234";
    ASSERT_TRUE(game_test.is_valid(str));
}

#endif