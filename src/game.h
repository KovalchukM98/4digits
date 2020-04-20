#ifndef GAME_H
#define GAME_H

#include <utility>
#include "sequence.h"

class Game
{
public:
	Game();

	~Game();

	void join();

private:
	bool is_valid(std::string str, int lenght);

	bool result_check(std::pair<int,int> result);
	
	std::vector<char> alphabet;
	Sequence *sec;
	int turns;
};

#endif