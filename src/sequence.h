#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <vector>

class Sequence
{
public:
    Sequence(std::vector<char> alphabet);

    ~Sequence();

    int *check(char *input, int n);

private:
    void makerand(std::vector<char> alphabet);
    char *trueseq;
};

#endif