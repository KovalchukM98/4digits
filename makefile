FLAGS = -Wall -Werror --std=c++17

USER_DIR_S = build/src

EXECUTABLE = bin/program

TESTS = bin/test

USER_DIR_T = build/test

GTEST_DIR = thirdparty/googletest

GOOGLE_TEST_INCLUDE = thirdparty/googletest/include

GFLAGS += -isystem thirdparty/googletest/include

LDFLAGS += -g -Wall -Wextra -pthread -std=c++17

all: $(EXECUTABLE) $(TESTS)

$(EXECUTABLE): $(USER_DIR_S)/main.o $(USER_DIR_S)/game.o  $(USER_DIR_S)/leaderboard.o  $(USER_DIR_S)/menu.o  $(USER_DIR_S)/sequence.o
	g++ $(FLAGS) $(USER_DIR_S)/main.o $(USER_DIR_S)/game.o  $(USER_DIR_S)/leaderboard.o  $(USER_DIR_S)/menu.o  $(USER_DIR_S)/sequence.o -o $(EXECUTABLE)

$(USER_DIR_S)/main.o: src/main.cpp
	g++ $(FLAGS) -c src/main.cpp -o $(USER_DIR_S)/main.o

$(USER_DIR_S)/game.o: src/game.cpp
	g++ $(FLAGS) -c src/game.cpp -o $(USER_DIR_S)/game.o

$(USER_DIR_S)/leaderboard.o: src/leaderboard.cpp
	g++ $(FLAGS) -c src/leaderboard.cpp -o $(USER_DIR_S)/leaderboard.o

$(USER_DIR_S)/menu.o: src/menu.cpp
	g++ $(FLAGS) -c src/menu.cpp -o $(USER_DIR_S)/menu.o

$(USER_DIR_S)/sequence.o: src/sequence.cpp
	g++ $(FLAGS) -c src/sequence.cpp -o $(USER_DIR_S)/sequence.o


$(TESTS): $(USER_DIR_T)/leaderboard_test.o $(USER_DIR_S)/leaderboard.o $(USER_DIR_T)/menu_test.o $(USER_DIR_S)/menu.o $(USER_DIR_T)/game_test.o $(USER_DIR_S)/game.o $(USER_DIR_T)/sequence_test.o $(USER_DIR_S)/sequence.o
	g++ $(GFLAGS) $(LDFLAGS) -L$(GTEST_DIR)/lib -l gtest_main -l gtest -lpthread $(USER_DIR_T)/leaderboard_test.o $(USER_DIR_S)/leaderboard.o $(USER_DIR_T)/menu_test.o $(USER_DIR_S)/menu.o $(USER_DIR_T)/game_test.o $(USER_DIR_S)/game.o $(USER_DIR_T)/sequence_test.o $(USER_DIR_S)/sequence.o -o $(TESTS)


$(USER_DIR_T)/leaderboard_test.o: test/leaderboard_test.cpp
	g++ $(GFLAGS) $(LDFLAGS) -I $(GOOGLE_TEST_INCLUDE) -I src -c test/leaderboard_test.cpp -o $@

$(USER_DIR_T)/menu_test.o: test/menu_test.cpp
	g++ $(GFLAGS) $(LDFLAGS) -I $(GOOGLE_TEST_INCLUDE) -I src -c test/menu_test.cpp -o $@

$(USER_DIR_T)/sequence_test.o: test/sequence_test.cpp
	g++ $(GFLAGS) $(LDFLAGS) -I $(GOOGLE_TEST_INCLUDE) -I src -c test/sequence_test.cpp -o $@

$(USER_DIR_T)/game_test.o: test/game_test.cpp
	g++ $(GFLAGS) $(LDFLAGS) -I $(GOOGLE_TEST_INCLUDE) -I src -c test/game_test.cpp -o $@

clean:
	rm -rf $(USER_DIR_S)/*.o
	rm -rf $(USER_DIR_T)/*.o
	rm -rf bin/*
