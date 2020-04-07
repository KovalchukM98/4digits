#ifndef SEQUENCE
#define SEQUENCE
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <random>
#include <ctime>

class Sequence
{
public:
    Sequence()
    {
        trueseq = new char[4];
        makerand(trueseq);
    }

    ~Sequence()
    {
        delete[] trueseq;
    }
    void check(char *truseq, char *input[], int n)
    {
        int bulls = 0, cows = 0;
        while (true)
        {
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
        }
    }

private:
    char *trueseq;
    void makerand(char trueseq[4])
    {
        srand(time(nullptr));
        bool is;
        int element;
        for (int i = 0; i < 4;)
        {
            is = false;
            element = rand() % 9;
            for (int j = 0; j < i; ++j)
            {
                if (trueseq[j] == (element + '0'))
                {
                    is = true;
                    break;
                }
            }
            if (!is)
            {
                trueseq[i] = element + '0';
                ++i;
            }
        }
    }
}

#endif