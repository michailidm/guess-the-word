#include "Trials.h"

Trials::Trials()
{
    //ctor
}

Trials::~Trials()
{
    //dtor
}

void Trials::print()
{
    cout << "Trials left: " << GetunsuccessfulTrialsLeft() << endl;
}

