#ifndef SEQUENCE_TEST
#define SEQUENCE_TEST

#include "sequence.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(SEQUENCE, count_bulls_and_cows)
{
    std::vector<char> alphabet = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    Sequence sec(alphabet, 4);
    ASSERT_TRUE(sec.set_trueseq("1234"));
    std::string str = sec.get_answer();
    std::pair<int, int> res;
    ASSERT_EQ(sec.count_bulls_and_cows(str).first, 4);
    ASSERT_EQ(sec.count_bulls_and_cows(str).second, 0);
    str = "1243";
    ASSERT_EQ(sec.count_bulls_and_cows(str).first, 2);
    ASSERT_EQ(sec.count_bulls_and_cows(str).second, 2);
    str = "4321";
    ASSERT_EQ(sec.count_bulls_and_cows(str).first, 0);
    ASSERT_EQ(sec.count_bulls_and_cows(str).second, 4);
    str = "9876";
    ASSERT_EQ(sec.count_bulls_and_cows(str).first, 0);
    ASSERT_EQ(sec.count_bulls_and_cows(str).second, 0);
}

#endif