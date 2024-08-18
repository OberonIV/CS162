/*********************************************************************
** Program Filename: hooping.cpp
** Author: Carl Jeffri Resurreccion
** Date: 28/01/2024
** Description: This program is a simulation of a two player basketball
* shooting contest.
** Input: Players input an integer to choose money ball rack, an integer
* to choose shooting ability, and an integer to choose if they want to
* replay.
** Output: Program will output shooting outcome for each rack, total score
* for each rack, total score for all racks, and the winner between two players.
*********************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

/*********************************************************************
** Function: get_money_rack_pos
** Description: Function that takes a user input used to define the
* position of the money rack of the ball.
** Parameters: None.
** Pre-Conditions: User inputs a valid
* value of position, or a number between 1 and 5 (inclusive).
** Post-Conditions:The value of position is returned.
*********************************************************************/

int get_money_rack_pos() {
    int money_rack_pos = 0;
    cout << "Where do you want to put your money-ball rack? Enter 1-5: ";
    cin >> money_rack_pos;
    // Error checking for valid input
    if (money_rack_pos >= 1 && money_rack_pos <= 5) {
        return money_rack_pos;
    }
    else {
        cout << "Error! Please enter a valid input." << endl;
        get_money_rack_pos();
    }
    return 0;
}

/*********************************************************************
** Function: get_shooting_ability
** Description: Function that takes a user input to define the shooting
* ability of the player. 
** Parameters: None.
** Pre-Conditions: User inputs a valid
* value of ability, or a number between 1 and 99 (inclusive).
** Post-Conditions: The value of ability is returned.
*********************************************************************/

int get_shooting_ability() {
    int shooting_ability = 0;
    cout << "Enter your shooting ability, from 1 to 99: ";
    cin >> shooting_ability;
    // Error checking for valid input
    if (shooting_ability >= 1 && shooting_ability <= 99) {
        return shooting_ability;
    }
    else {
        cout << "Error! Please enter a valid input." << endl;
        get_shooting_ability();
    }
    return 0;
}

/*********************************************************************
** Function: print_scores
** Description: Function that prints out the outcome of each shooting outcome
* as well as the score for each rack, and score total.
** Parameters: score_array
** Pre-Conditions: score_array must be populated with characters. 
** Post-Conditions: Console will print out each rack as well as the total for each rack.
* The value of counter, or the total points, will be returned.
*********************************************************************/

int print_scores(char score_array[5][5]) {
    int counter = 0;
    for (int i = 0; i < 5; i++) {
        int counter_rack = 0;
        cout << "Rack " << i + 1 << ": ";
        for (int j = 0; j < 5; j++) {
            cout << score_array[i][j] << " ";
            // Adds 1 to counter if element in array is 'O'
            if (score_array[i][j] == 'O') {
                counter_rack += 1;
                counter += 1;
            }
            // Adds 2 to counter if element in array is 'M'
            else if (score_array[i][j] == 'M') {
                counter_rack += 2;
                counter += 2;
            }
            // Does not need to check for X, as it adds 0 points
        }
        cout << "| " << counter_rack << " pts";
        cout << endl;
    }
    cout << "Total: " << counter << " pts" << endl;
    cout << endl;
    return counter;
}

/*********************************************************************
** Function: shot_success
** Description: Calculates the success of each shot using random number
* generation and user inputted shooting ability.
** Parameters: shooting_ability
** Pre-Conditions: shooting_ability is inputted by the user and function is called
* by populate_array.
** Post-Conditions: Function will return true or false to determine whether
* a shot is successful.
*********************************************************************/

bool shot_success(int shooting_ability) {
    // Determines the shooting outcome by generating a random number between 1 and 100
    int shooting_outcome = rand() % 100 + 1;
    // If shooting outcome is equal to or smaller than ability, shot is made. Else, shot is missed
    if (shooting_outcome <= shooting_ability) {
        return true;
    }
    else {
        return false;
    }
}

/*********************************************************************
** Function: money_rack
** Description: Defines the money rack, fills the array with 'M's or 'X's
* depending on shot success rate.
** Parameters: score_array, money_rack_pos, shooting_ability
** Pre-Conditions: money_rack_pos is inputted by the user and function is called
* by populate_array.
** Post-Conditions: A single rack will be populated with only 'M's or 'X's
*********************************************************************/

void money_rack(char score_array[5][5], int money_rack_pos, int shooting_ability) {
    for (int i = 0; i < 5; i++) {
        // Runs shot success every iteration and sets index to hit or miss
        if (shot_success(shooting_ability) == true) {
            // Fills 'column' using using user defined money_rack_pos
            score_array[money_rack_pos][i] = 'M';
        }
        else {
            score_array[money_rack_pos][i] = 'X';
        }
    }
    return;
}

/*********************************************************************
** Function: populate_scores
** Description: Fills the array using 
** Parameters: score_array, money_rack_pos, shooting_ability
** Pre-Conditions: score_array must be created, money_rack_pos and
* shooting_ability must be called and returned.
** Post-Conditions: score_array is filled with characters.
*********************************************************************/

void populate_scores(char score_array[5][5], int money_rack_pos, int shooting_ability) {
    // Populates array by iterating shot success and setting element based on outcome
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Different filling method for last element of each rack, worth two points
            if (j == 4) {
                if (shot_success(shooting_ability) == true) {
                    score_array[i][j] = 'M';
                }
                else {
                    score_array[i][j] = 'X';
                }
            }
            else if (shot_success(shooting_ability) == true) {
                score_array[i][j] = 'O';
            }
            else {
                score_array[i][j] = 'X';
            }
        }
    }
    // Runs money_rack and repopulates rack. -1 due to difference in defined size and index size
    // ie. Keeping money_rack_pos to 3 will instead replace rack 4, instead of 3, as it starts indexing from 0 
    money_rack(score_array, money_rack_pos - 1, shooting_ability);
    return;
}

/*********************************************************************
** Function: run_game
** Description: Runs all previous functions to create a completed game.
** Parameters: None.
** Pre-Conditions: All functions must be called and vlaues returned.
** Post-Conditions: Winner is determined.
*********************************************************************/

void run_game() {
    char score_array[5][5];
    int player_1_total = 0;
    int player_2_total = 0;
    // Iterates game twice for two players
    for (int i = 0; i <= 1; i++) {
        int money_rack_pos = get_money_rack_pos();
        int shooting_ability = get_shooting_ability();
        shot_success(shooting_ability);
        populate_scores(score_array, money_rack_pos, shooting_ability);
        // Sets player score based on iteration
        if (i == 0) {
            cout << "Player 1: " << endl;
            player_1_total = print_scores(score_array);
        }
        else if (i == 1) {
            cout << "Player 2: " << endl;
            player_2_total = print_scores(score_array);
        }
    }
    // Comparisons to determine winner of game
    if (player_1_total > player_2_total) {
        cout << "Player 1 is the winner!";
    }
    else if (player_2_total > player_1_total) {
        cout << "Player 2 is the winner!";
    }
    else {
        cout << "It's a tie!";
    }
}

/*********************************************************************
** Function: main
** Description: Main function that randomizes time and handles replay function
* of the game.
** Parameters: None.
** Pre-Conditions: None.
** Post-Conditions: None.
*********************************************************************/

int main() {
    srand((unsigned int)time(NULL));
    // Runs everything within function once, then repeats if replay status is true.
    bool replay_status = false;
    int replay = -1;
    do {
        cout << "Welcome to the basketball shooting contest!" << endl;
        run_game();
        cout << endl;
        cout << "Do you want to play again? (1  - yes, 0 - no): ";
        cin >> replay;
        // Sets value of replay status depending on user input.
        while (true) {
            if (replay == 1) {
                replay_status = true;
                break;
            }
            else if (replay == 0) {
                cout << "Goodbye!";
                replay_status = false;
                break;
            }
            else {
                cout << "Error! Please enter a valid input." << endl;
                cout << "Do you want to play again? (1  - yes, 0 - no): ";
                cin >> replay;
                replay_status = true;
            }
        }
    } while (replay_status == true);
    return 0;
}