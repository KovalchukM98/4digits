#ifndef SEQUENCE
#define SEQUENCE
#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <algorithm>
#include "sequence.h"

Sequence::Sequence(std::vector<char> alphabet)
    {
        trueseq = new char[4];
        makerand(alphabet);
    }

Sequence::~Sequence()
    {
        delete[] trueseq;
    }
    int* Sequence::check(char *input, int n)
    {
        int bulls = 0, cows = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i != j)
                {
                    if (input[i] == trueseq[j])
                    {
                        ++cows;
                    }
                }
                else
                {
                    if (input[i] == trueseq[j])
                        ++bulls;
                }
            }
        }
        int *a;
        a = new int[2];
        a[0] = bulls;
        a[1] = cows;
        // std::cout << "true : " << trueseq << std::endl;
        return a;
    }

void Sequence::makerand(std::vector<char> alphabet)
    {
        srand(time(0));
        random_shuffle(alphabet.begin(), alphabet.end());
        for (int i = 0; i < 4; ++i)
            trueseq[i] = alphabet[i];
    }

#endif