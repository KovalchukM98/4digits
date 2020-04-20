#ifndef GAME_H
#define GAME_H

#include "sequence.h"

class Game
{
public:
	Game();

	~Game();

	void join();

private:
	bool is_valid(std::string str, int lenght);

	bool result_check(int *result);
	
	std::vector<char> alphabet;
	Sequence *sec;
	int turns;
};

#endif