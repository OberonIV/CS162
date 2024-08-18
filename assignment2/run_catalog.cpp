#include "catalog.h"
#include <string>

using namespace std;

// Function for menu option picking, will return whatever choice the user makes
char menu() {
    char choice;

    while (true) {  // Function is always true and will loop infinetly until exit function is picked
        cout << "\nWhich option would you like to choose?" << endl;
        cout << "1. Display all songs" << endl;
        cout << "2. Play/search for a song" << endl;
        cout << "3. Search songs by genre" << endl;
        cout << "4. Length of all playlists" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail() || (choice < '1' || choice > '5')) { // cin.fail will check if the input enters fail state. Checks if entered char is an number
            cin.clear();    // Clears the error state of the input
            cin.ignore(1000, '\n'); // Discards the invalid input up to the newline character. 
            cout << "Invalid choice. Please enter a character between '1' and '5'." << endl;
        } else {
            break;  // If no conditions are true, leave loop
        }
    }

    return choice;
}

// Function to process user's choice. Will call corresponding function.
void processUserChoice(Playlist* playlists, int num_playlists, int choice) {    // this is too long because switch needs a break after each case
    if (choice == '1') { // Uses ' ' so that it error handles other variable types
        display_all_songs(playlists, num_playlists);
    } else if (choice == '2') {
        search_song(playlists, num_playlists);
    } else if (choice == '3') {
        search_by_genre(playlists, num_playlists);
    } else if (choice == '4') {
        length_of_all_playlists(playlists, num_playlists);
    } else if (choice == '5') {
        quit();
    } else {
        cout << "Invalid choice. Please try again." << endl;
    }
}

// Main function to run catalog program
int main() {
    string file_path = "songs_playlist.txt";    // Sets file_path to file name, will use file_path instead of typing file name
    int num_playlists;  // num_playlist is defined
    char choice;

    ifstream file(file_path);   // Open file to read number of playlists from first line
    file >> num_playlists;  // Set that to num_playlists integer

    if (!file.is_open()) {  // Checks if file is open
        cerr << "Cannot open file " << file_path << endl;   // Error if already opened
        return -1;  // Returns -1 so that the program knows that it did not complete the function. Complete if return is 0
    }

    Playlist* playlists = create_playlists(num_playlists);
    populate_all_playlists(playlists, num_playlists, file);

    do {
        choice = menu();    // Takes choice from menu() function
        processUserChoice(playlists, num_playlists, choice);    // Runs processUserChoice() function
    } while (choice != '5');    // As long as choice is not 5, function loops

    delete_info(playlists, num_playlists);  // Clear allocated memory

    return 0;
}
