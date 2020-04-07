#ifndef SEQUENCE
#define SEQUENCE
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <random>
#include <ctime>
const int n = 4;
class Sequence
{
public:
    Sequence()
    {
        trueseq = new char[n];
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
    void makerand(char trueseq[n])
    {
        srand(time(nullptr));
        bool is;
        int element;
        for (int i = 0; i < n;)
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