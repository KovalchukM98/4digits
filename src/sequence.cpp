#ifndef SEQUENCE
#define SEQUENCE
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

class Sequence
{
public:
    Sequence(char alphabet[10])
    {
        trueseq = new char[4];
        makerand(alphabet);
    }

    ~Sequence()
    {
        delete[] trueseq;
    }
    int *check(char *input, int n)
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
        // cout << "true : " << trueseq << endl;
        return a;
    }

private:
    char *trueseq;

    void makerand(char alphabet[10])
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