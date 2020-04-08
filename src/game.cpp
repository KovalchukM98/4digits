#ifndef GAME
#define GAME

#include "sequence.cpp"

using namespace std;

class Game
{
public:
	Game()
	{
		sec = new Sequence;
		turns = 0;
	}

	~Game()
	{
		delete sec;
	}

	void join()
	{
		bool flag = false;
		int lenght = 4;
		char *input = new char[lenght];
		int *result;
		string str;
		while (!flag)
		{
			cout << "введите " << lenght << " числа от 0 до 9 " << endl;
			getline(cin , str);
			if (!is_valid(str, lenght))
			{
				cout << "некорректный ввод" << endl;
				continue;
			}
			for (int i = 0; i < lenght; ++i)
			{
				input[i] = str[i];
			}
			cout << "AAAAAAAAA" <<endl;
			result = sec->check(input, lenght);
			cout << "BBBBBBBBB" <<endl;
			cout << "cows : " << result[0] << endl;
			cout << "bulls :" << result[1] << endl;
			delete[] result;
		}
		delete input;
	}

	bool is_valid(string str, int lenght)
	{	
		int k = str.size();
		if( k != lenght){
			return false;
		}
		for (int i = 0; i < lenght; ++i)
		{
			bool eq = false;
			for (int j = i - 1; j >= 0; --j)
			{
				if (str[j] == str[i])
				{
					return false;
				}
			}

			for (int j = 0; j < 10; ++j)
			{
				if (str[i] == slovar[j])
				{
					eq = true;
					break;
				}
			}
			if (!eq)
			{
				return false;
			}
		}
		return true;
	}

private:
	char slovar[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	Sequence *sec;
	int turns;
};

#endif