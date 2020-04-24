#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <string>
#include <utility>
#include <vector>

class Sequence {
public:
    Sequence(std::vector<char> alphabet);

    ~Sequence();

    std::pair<int, int> count_bulls_and_cows(std::string input, int n);

private:
    void makerand(std::vector<char> alphabet);
    char* trueseq;
};

#endif