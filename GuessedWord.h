#ifndef GUESSEDWORD_H
#define GUESSEDWORD_H

#include <iostream>
using namespace std;

class GuessedWord
{
    public:
        GuessedWord();

        void print();

        string Getword() const { return word; }
        void Setword(string val) { word = val; }
        string GetguessedWord() const { return guessedWord; }

        void SetguessedWord(string val) { guessedWord = val; }

    protected:

    private:
        string word = "water";
        string guessedWord;
};

#endif // GUESSEDWORD_H
