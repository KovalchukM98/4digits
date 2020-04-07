#ifndef SEQUENCE
#define SEQUENCE

class Sequence
{
public:
    Sequence()
    {
        trueseq = new char[4];
    }

    ~Sequence()
    {
        delete[] trueseq;
    }

private:
    char *trueseq;
    void makerand(char trueseq[])
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
                    there = true;
                    break;
                }
            }
            if (!there)
            {
                trueseq[i] = element + '0';
                ++i;
            }
        }
    }
}

#endif