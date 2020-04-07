#ifndef GAME
#define GAME

#include "sequence.cpp"

using namespace std;

class Game
{
public:
	Game(){
		sec = new Sequence;
		turns = 0;
		for(int i = 0 ; i < 10 ; ++i){
			slovar[i] = i;
		}
	}

	~Game(){
		delete sec;
	}

	void join(){
		bool flag = false;
		int lenght = 4;
		char *input = new char[lenght];
		
		string str;
		while(!flag){
			cout << "введите " << lenght << " числа от 0 до 9 " << endl;
    		cin >> str;
    		cout << str << endl;
    		for(int i = 0 ; i < lenght ; ++i){
    			cout << "AAAAAAAAAAAAA" <<endl;
    			input[i] = str[i];
			}
    		//cout << input <<endl;
    		if(is_valid(input , lenght)){
    			 sec->check(input , lenght);
    		}
    		else {
    			cout << "некорректный ввод" << endl;
    			continue;
    		}
		}
		delete input;
	}

	bool is_valid(char *input , int lenght){
		for(int i = 0 ; i < lenght ; ++i){
			bool eq = false;
			for(int j = 0 ; j < 10 ; ++j){
				cout << slovar[i] << endl;
				if( input[i] == slovar[j]){
					eq = true;
					break;
				}
			}
			if(!eq){
				return false;
			}
		}
		return true;
	}

private:
    char slovar[10];
    Sequence *sec;
    int turns;
};

#endif