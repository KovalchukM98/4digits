all: bin/programm

bin/programm: build/main.o build/menu.o build/game.o build/sequence.o
	g++ -Wall --std=c++17 -Werror build/main.o build/menu.o build/game.o build/sequence.o -o bin/programm

build/main.o: src/main.cpp
	g++ -Wall --std=c++17 -Werror -c src/main.cpp -o build/main.o

build/game.o: src/game.cpp
	g++ -Wall --std=c++17 -Werror -c src/game.cpp -o build/game.o

build/menu.o: src/menu.cpp
	g++ -Wall --std=c++17 -Werror -c src/menu.cpp -o build/menu.o

build/sequence.o: src/sequence.cpp
	g++ -Wall --std=c++17 -Werror -c src/sequence.cpp -o build/sequence.o

clean:
	rm -rf *.o build/*.o
