#include <iostream>
#include <cstring>

#include "GuessedWord.h"
#include "Alphabet.h"
#include "Trials.h"

using namespace std;

int main()
{
    GuessedWord gW;
    Alphabet alph;
    Trials tr;

    bool finished = false;
    char let;

    while (!finished)
    {
        cout << endl;
        cout << "---------------------------------------------------------------" << endl;
        cout << "\t\t\t";
        tr.print();
        cout << endl;
        cout << "\t";
        gW.print();
        cout << endl;
        alph.print();
        cout << endl;

        cout << "Give a letter (q for quit): ";
        cin >> let; // or sth else? Because it reads also strings, one character each time.

        // Check if letter is valid.
        while (let != 'a' && let != 'b' && let != 'c' && let != 'd' && let != 'e'
               && let != 'f' && let != 'g' && let != 'h' && let != 'i' && let != 'j'
               && let != 'k' && let != 'l' && let != 'm' && let != 'n' && let != 'o'
               && let != 'p' && let != 'q' && let != 'r' && let != 's' && let != 't'
               && let != 'u' && let != 'v' && let != 'w' && let != 'x' && let != 'y' && let != 'z')
        {
            cout << "Please give a valid letter (small Latin letters): ";
            cin >> let;
        }

        // Check if the letter was used.

        int index = -1;
        bool letNotUsed = false;
        for (int i = 0; i < (int) alph.GetremainingLets().length(); i++)
        {
            if (alph.GetremainingLets()[i] == let)
            {
                letNotUsed = true;
                index = i;
            }
        }

        // Remove letter from the alphabet.
        if (letNotUsed)
        {
            string temp = alph.GetremainingLets();
            temp.erase(index, 1);
            alph.SetremainingLets(temp);
        }
        else
        {
            cout << "You already used this letter. Give an other one: ";
            continue;
        }

        // Now that letter is valid and was not used, search it in the word.

        int pos = -1;
        bool letInWord = false;
        for (int i = 0; i < (int) gW.Getword().length(); i++)
        {
            if (gW.Getword()[i] == let)
            {
                letInWord = true;
                pos = i;
            }
        }

        if (letInWord)
        {
            string word = gW.GetguessedWord(); // We used the auxiliary variable 'word' because it does not work without it.
            word[pos] = let;
            gW.SetguessedWord(word);
        }
        else
        {
            cout << "The word does not contain this letter. Try again!" << endl;
            tr.SetunsuccessfulTrialsLeft(tr.GetunsuccessfulTrialsLeft() - 1);
        }


        // Do something with 'finished'.
        bool underscoreInGuessedW = false;
        for (int i = 0; i < (int) gW.GetguessedWord().length(); i++)
        {
            if (gW.GetguessedWord()[i] == '_')
                underscoreInGuessedW = true;
        }

        if (!underscoreInGuessedW)
        {
            // Print out the final state of the guessed word.
            cout << endl;
            cout << "---------------------------------------------------------------" << endl;
            cout << "\t\t\t";
            tr.print();
            cout << endl;
            cout << "\t";
            gW.print();
            cout << endl;
            alph.print();
            cout << endl;

            cout << "Congratulations! You found the word!" << endl;
            finished = true;
        }
        else if (tr.GetunsuccessfulTrialsLeft() == 0)
        {
            // Print out the final state of the guessed word.
            cout << endl;
            cout << "---------------------------------------------------------------" << endl;
            cout << "\t\t\t";
            tr.print();
            cout << endl;
            cout << "\t";
            gW.print();
            cout << endl;
            alph.print();
            cout << endl;

            cout << "Too many unsuccessful trials! To play again, run the program again." << endl;
            finished = true;
        }

    }

    return 0;
}
