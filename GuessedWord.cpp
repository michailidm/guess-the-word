#include "GuessedWord.h"

GuessedWord::GuessedWord()
{
    //ctor

    guessedWord = "_____";

}

void GuessedWord::print()
{
    for (int i = 0; i < (int) guessedWord.length(); i++)
        cout << guessedWord[i] << " ";   // TO FIX (with ?: before the space): after the last letter the space is redundant.
    cout << endl;
}
