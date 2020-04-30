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
	std::string answer = sec.get_answer();
	std::pair<int, int> res;
	ASSERT_EQ(sec.count_bulls_and_cows(answer).first, 4);
	ASSERT_EQ(sec.count_bulls_and_cows(answer).second, 0);
	char tmp = answer[0];
	answer[0] = answer[1];
	answer[1] = tmp;
	ASSERT_EQ(sec.count_bulls_and_cows(answer).first, 2);
	ASSERT_EQ(sec.count_bulls_and_cows(answer).second, 2);
	tmp = answer[2];
	answer[2] = answer[3];
	answer[3] = tmp;
	ASSERT_EQ(sec.count_bulls_and_cows(answer).first, 0);
	ASSERT_EQ(sec.count_bulls_and_cows(answer).second, 4);
}

#endif