#ifndef SEQUENCE
#define SEQUENCE
#include <iostream>
#include <random>
#include <ctime>
#include <vector>

using namespace std;

class Sequence
{
public:
    Sequence(std::vector<char> alphabet)
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

    void makerand(std::vector<char> alphabet)
    {
        srand(time(0));
        auto rng = std::default_random_engine{};
        std::random_shuffle(alphabet.begin(), alphabet.end());
        for (int i = 0; i < 4; ++i)
            trueseq[i] = alphabet[i];
    }
};

#endif