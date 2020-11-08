// Typing_Speed_Checker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <fstream>
#include <set>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

int main()
{
    srand((unsigned int)time(NULL));
    vector <string> dict;
    fstream file;
    file.open("dataFile.txt");
    string word;
    while (file >> word) {
        dict.push_back(word);
    }
    file.close();

    int score = 0;
    int length = dict.size();
    clock_t start;
    start = clock();
    while (1) {
        int t = rand() % (length - 1);
        string output = dict[t];
        string input;
        cout << "Type: "<< output << endl;
        cin >> input;
        if (input == output) {
            score += 10;
            cout << "Correct \n\n";
        }
        else {
            cout << "Incorrect! \n\n";
            break;
        }
    }
    clock_t end;
    end = clock();
    cout << "Grand_Score: " << score << endl;
    cout << "Your typing speed is: ";
    float results = score / 10;
    results = results / float(end - start) / CLOCKS_PER_SEC;
    cout << float(results*60)<<"wpm"<< endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
