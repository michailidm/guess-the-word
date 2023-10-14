#include "Alphabet.h"

Alphabet::Alphabet()
{
    //ctor

    remainingLets = "abcdefghijklmnopqrstuvwxyz";
}

Alphabet::~Alphabet()
{
    //dtor
}

Alphabet::Alphabet(const Alphabet& other)
{
    //copy ctor
}

void Alphabet::print()
{
    for (int i = 0; i < (int) remainingLets.length(); i++)
        cout << remainingLets[i] << " ";    // TO FIX (with ?: before the space): after the last letter the space is redundant.
    cout << endl;
}
