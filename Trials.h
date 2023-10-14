#ifndef TRIALS_H
#define TRIALS_H

#include <iostream>
using namespace std;

class Trials
{
    public:
        Trials();
        virtual ~Trials();

        void print();

        int GetunsuccessfulTrialsLeft() const { return unsuccessfulTrialsLeft; }
        void SetunsuccessfulTrialsLeft(int val) { unsuccessfulTrialsLeft = val; }

    protected:

    private:
        int unsuccessfulTrialsLeft = 10;
};

#endif // TRIALS_H
