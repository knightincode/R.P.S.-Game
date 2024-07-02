/*
Samuel Knight
Rock Paper Scissors Game
C++
07/01/2024
*/

#include <iostream>
#include <cstdio>
using namespace std;

char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer);

int main() {
    srand(time(0)); // Seed the random number generator once

    do {
        char player;
        char computer;

        player = getUserChoice(); // Get player's choice
        if (player == '0') {
          cout << "\nGame exited.\n";
            break; // Exit the loop if player enters '0'
        }

        cout << "\nYour choice: ";
        showChoice(player);

        computer = getComputerChoice(); // Get computer's choice
        cout << "Computers choice: ";
        showChoice(computer);
        cout << endl;

        chooseWinner(player, computer); // Determine the winner
        cout << "******************************\n";

    } while (true); // Loop continues indefinitely until '0' is entered

    return 0; // Exit the program after the loop ends
}

char getUserChoice() {
    char player;

    cout << "~ Rock, Paper, Scissors Game! ~\n";
    cout << "********************************\n";

    do {
        cout << "Choose one of the following:\n";
        cout << endl;
        //cout << "*********************\n";
        cout << "'r': for Rock\n";
        cout << "'p': for Paper\n";
        cout << "'s': for Scissors\n";
        cout << "'0': to exit game.\n";
        cout << endl;
        cin >> player;
    } while (player != 'r' && player != 'p' && player != 's' && player != '0');

    return player;
}

char getComputerChoice() {
    srand(time(0));
    int num = rand() % 3 + 1;

    switch (num) {
        case 1: return 'r';
        case 2: return 'p';
        case 3: return 's';
    }

    return num;
}

void showChoice(char choice) {
    switch (choice) {
        case 'r': cout << "Rock\n"; break;
        case 'p': cout << "Paper\n"; break;
        case 's': cout << "Scissors\n"; break;
    }
}

void chooseWinner(char player, char computer) {
    switch (player) {
        case 'r':
            if (computer == 'r') {
                cout << endl << "It's a Tie! :/\n\n";
            } else if (computer == 'p') {
                cout << endl << "You Lose! :(\n\n";
            } else {
                cout << endl << "You Win! :)\n\n";
            }
            break;
        case 'p':
            if (computer == 'r') {
                cout << endl << "You Win! :)\n\n";
            } else if (computer == 'p') {
                cout << endl << "It's a Tie! :/\n\n";
            } else {
                cout << "You Lose! :(\n\n";
            }
            break;
        case 's':
            if (computer == 'r') {
                cout << endl << "You Lose! :(\n\n";
            } else if (computer == 'p') {
                cout << endl << "You Win! :)\n\n";
            } else {
                cout << endl << "It's a Tie! :/\n\n";
            }
            break;
    }
}