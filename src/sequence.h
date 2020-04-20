#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <vector>

class Sequence
{
public:
    Sequence(std::vector<char> alphabet);

    ~Sequence();

    int *count_bulls_and_cows(char *input, int n);

private:
    void makerand(std::vector<char> alphabet);
    char *trueseq;
};

#endif