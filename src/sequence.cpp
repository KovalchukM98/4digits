#ifndef SEQUENCE
#define SEQUENCE

class Sequence
{
public:
    Sequence()
    {
        trueseq = new char[4];
    }

    ~Sequence() {}

private:
    char *trueseq;
}

#endif