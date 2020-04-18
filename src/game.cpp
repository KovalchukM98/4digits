#ifndef GAME
#define GAME
#include <string>
#include <iostream>
#include "sequence.cpp"

class Game
{
public:
	Game()
	{
		sec = new Sequence(alphabet);
		turns = 0;
	}

	~Game()
	{
		delete sec;
	}

	void join()
	{
		bool is_game_over = false;
		int lenght = 4;
		char *input = new char[lenght];
		int *result;
		std::string str;
		while (!is_game_over)
		{
			std::cout << "введите " << lenght << " числа от 0 до 9 " << std::endl;
			getline(std::cin , str);
			if (!is_valid(str, lenght))
			{
				std::cout << "некорректный ввод" << std::endl;
				continue;
			}
			turns++;
			for (int i = 0; i < lenght; ++i)
			{
				input[i] = str[i];
			}
			result = sec->check(input, lenght);
			is_game_over = result_check(result);
			delete[] result;
		}
		std::cout << input << " is right answer" << std::endl;
		std::cout << "your turns : " << turns << "\n" << std::endl;
		//leaders_board.compare(turns);  ????
		delete input;
	}

	bool result_check(int *result){
		if( result[0] < 4){
				std::cout << "\n" << "turn : " << turns << std::endl;
				std::cout << "	bulls : " << result[0] << std::endl;
				std::cout << "	cows  :" << result[1] << "\n" << std::endl;
				return false;
		}
		else{
			std::cout << "\n 	You win!" << std::endl;
		}
		return true;
	}

	bool is_valid(std::string str, int lenght)
	{	
		if( str.size() != static_cast<unsigned int>(lenght)){
			return false;
		}
		for (int i = 0; i < lenght; ++i)
		{
			bool is_suitable_symbol = false;
			for (int j = i - 1; j >= 0; --j)
			{
				if (str[j] == str[i])
				{
					return false;
				}
			}

			for (int j = 0; j < 10; ++j)
			{
				if (str[i] == alphabet[j])
				{
					is_suitable_symbol = true;
					break;
				}
			}
			if (!is_suitable_symbol)
			{
				return false;
			}
		}
		return true;
	}

private:
	char alphabet[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	Sequence *sec;
	int turns;
};

#endif