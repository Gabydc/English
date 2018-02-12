/*
 * main.cpp
 *
 *  Created on: Mar 8, 2013
 *      Author: martijn
 */

#include <fstream>
#include <istream>
#include <sstream>
#include <iostream>
#include <algorithm>    // std::random_shuffle
#include <vector>
#include <unistd.h>

using namespace std;

// Puts the results in an already constructed vector
vector<string> &split(const string &s, char delim, vector<string> &elems)
{
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim))
    {
        elems.push_back(item);
    }
    return elems;
}

// Returns a new vector
vector<string> split(const string &s, char delim)
{
    vector<string> elems;
    return split(s, delim, elems);
}

int main()
{
    vector<string> list;

    const char *filename = "";
    int choice;

    // info
    cout << "==========================================" << endl;
    cout << "            Wordlist unit 1-10            " << endl;
    cout << "==========================================" << endl;

    // make choice
    cout << "1)  Unit 1" << endl;
    cout << "2)  Unit 2" << endl;
    cout << "3)  Unit 3" << endl;
    cout << "4)  Unit 4" << endl;
    cout << "5)  Unit 5" << endl;
    cout << "6)  Unit 6" << endl;
    cout << "7)  Unit 7" << endl;
    cout << "8)  Unit 8" << endl;
    cout << "9)  Unit 9" << endl;
    cout << "10) Unit 10" << endl;
    cout << "==========================================" << endl;
    cout << "Make your choice: ";
    cin >> choice;
    cout << "==========================================" << endl;

    switch (choice)
    {
    case 1:
        filename = "unit1.dat";
        break;
    case 2:
        filename = "unit2.dat";
        break;
    case 3:
        filename = "unit3.dat";
        break;
    case 4:
        filename = "unit4.dat";
        break;
    case 5:
        filename = "unit5.dat";
        break;
    case 6:
        filename = "unit6.dat";
        break;
    case 7:
        filename = "unit7.dat";
        break;
    case 8:
        filename = "unit8.dat";
        break;
    case 9:
        filename = "unit9.dat";
        break;
    case 10:
        filename = "unit10.dat";
        break;
    }

    // read words from .dat file
    ifstream input(filename);
    for (string line; getline(input, line);)
    {
        list.push_back(line);
    }

    int correct = 0;
    int quit = 0;
    string quitstr = "quit";
    int question = 0;

    // make choice
    cout << "1) alphabetical" << endl;
    cout << "2) random" << endl;
    cout << "==========================================" << endl;
    cout << "Make your choice: ";
    cin >> choice;
    cout << "==========================================" << endl;

    string dummy = "";
    getline(cin, dummy);

    // run actual word test
    switch (choice)
    {
    case 1:
    {
        //cout << "ascending order" << endl;

        // all words in ascending order
        for (unsigned i = 0; i < list.size(); ++i)
        {
            ++question;

            vector<string> x = split(list.at(i), '=');
            cout << i+1;
            cout << ") '" << x.at(1) << "' " << endl;

            string answer = "";
            int tries = 0;

            while (answer != x.at(0))
            {
                if (tries == 3)
                {
                    cout << "Correct is: " << x.at(0) << endl;
                    break;
                }

                cout << ">> ";
                //cin >> answer;
                getline(cin, answer);
                //cin.ignore();

                if (answer == x.at(0))
                {
                    ++correct;
                    break;
                }

                if (answer == quitstr)
                {
                    quit = 1;
                    break;
                }

                ++tries;
            }

            if (quit == 1)
            {
                --question;
                break;
            }
        }

        break;
    }
    case 2:
    {
        //cout << "random order" << endl;

        // words in random order
        vector<int> myvector;
        for (unsigned i = 0; i < list.size(); ++i)
            myvector.push_back(i); // 1 2 3 4 5 6 7 8 9

        // using built-in random generator:
        random_shuffle(myvector.begin(), myvector.end());

        for (unsigned i = 0; i < list.size(); ++i)
        {
            ++question;

            int number = myvector.at(i);

            vector<string> x = split(list.at(number), '=');
            cout << i+1 << ") '";
            cout << x.at(1) << "' " << endl;

            string answer = "";
            int tries = 0;

            while (answer != x.at(0))
            {
                if (tries == 3)
                {
                    cout << "Correct is: " << x.at(0) << endl;
                    break;
                }

                cout << ">> ";
                //cin >> answer;
                getline(cin, answer);
                //cin.ignore();

                if (answer == x.at(0))
                {
                    ++correct;
                    break;
                }

                if (answer == quitstr)
                {
                    quit = 1;
                    break;
                }

                ++tries;
            }

            if (quit == 1)
            {
                --question;
                break;
            }
        }
        break;
    }
    default:
        break;
    }

    cout << "Correct answers  : " << correct << endl;
    cout << "Total questions  : " << question << endl;
    cout << "Accuracy (grade) : " << 100 * correct / (question) << "%" << endl;

    return 0;
}
