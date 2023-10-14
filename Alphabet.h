#ifndef ALPHABET_H
#define ALPHABET_H

#include <iostream>
using namespace std;

class Alphabet
{
    public:
        Alphabet();
        virtual ~Alphabet();
        Alphabet(const Alphabet& other);

        void print();

        string GetremainingLets() const { return remainingLets; }
        void SetremainingLets(string s) { remainingLets = s; }

    protected:

    private:
        string remainingLets;
};

#endif // ALPHABET_H
