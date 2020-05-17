#ifndef GAME_TEST
#define GAME_TEST

#include "game.h"
#include "sequence.h"
#include <gtest/gtest.h>
#include <string>

TEST(GAME, is_input_valid)
{
    std::vector<char> alphabet = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    Game game(alphabet, 4);
    std::string str;
    ASSERT_FALSE(game.is_input_valid(str));
    str = "12a4";
    ASSERT_FALSE(game.is_input_valid(str));
    str = "12";
    ASSERT_FALSE(game.is_input_valid(str));
    str = "12345";
    ASSERT_FALSE(game.is_input_valid(str));
    str = "1233";
    ASSERT_FALSE(game.is_input_valid(str));
    str = "1234";
    ASSERT_TRUE(game.is_input_valid(str));
}

#endif