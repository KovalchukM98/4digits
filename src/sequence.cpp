#ifndef SEQUENCE
#define SEQUENCE
#include <iostream>
#include <random>
#include <ctime>

class Sequence
{
public:
    Sequence()
    {
        trueseq = new char[4];
        makerand();
    }

    ~Sequence()
    {
        delete[] trueseq;
    }
    int *check(char *input, int n)
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
        int *a;
        a = new int[2];
        a[0] = bulls;
        a[1] = cows;
        return a;
    }

private:
    char *trueseq;


    void makerand()
    {
        srand(time(0));
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
};

#endif