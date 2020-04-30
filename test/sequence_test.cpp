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
}

#endif