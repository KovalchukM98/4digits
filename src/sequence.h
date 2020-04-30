#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <string>
#include <utility>
#include <vector>

class Sequence {
public:
    Sequence(std::vector<char> alphabet, int lenght);

    ~Sequence();

    std::pair<int, int> count_bulls_and_cows(std::string input);

    std::string get_answer();

private:
    void makerand(std::vector<char> alphabet);

    std::string trueseq;
    int seq_lenght;
};

#endif