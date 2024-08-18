#include "catalog.h"
#include <string>

using namespace std;

// Read # of songs in each playlist. maybe works
int readSongsPerPlaylist(Playlist* playlists, int num_playlists, ifstream& file) {	// ifstream& refrences the txt file, 
	int total_songs = 0;    // Variable to store the number of total songs in each playlist

	for (int i = 0; i < num_playlists; ++i) {   // Loop through each playlist
		file >> playlists[i].name >> playlists[i].num_song; // Reads the playlist title and number of songs
		playlists[i].s = create_songs(playlists[i].num_song);   // Creates an array of songs for playlist

		for (int j = 0; j < playlists[i].num_song; ++j) {   // Loop through each song in playlist
			populate_one_song(playlists[i].s, j, file); // Uses the function to populate the current song with the correct information
			total_songs++;  // Increase total number of songs
		}
	}
	return total_songs; // Returns total number of songs in each playlist
}

// Function to dynamically allocate memory for an array of Playlist structs
Playlist* create_playlists(int num_playlists) {	// int num_playlists will be pulled from the readNumberOfPlaylist function
    Playlist* playlists = new Playlist[num_playlists];  // Allocates memory fo an array of Song structs
	return playlists;   // Returns the pointer to the allocated array
}

// Function to dynamically allocate memory for an array of Song structs
Song* create_songs(int size) {  // Number of songs is the parameter here
	return new Song[size];  // Allocates memory for an array of Songs
}

// Function to create songs
void populate_one_song(Song* songs, int index, ifstream& file) {    // Read and store the information of songs in the array
	file >> songs[index].name;  // Takes the info from the file
	file >> songs[index].artist;    // Index represents the position in the array of Song that the information is being read from
	file >> songs[index].year_release;
	file >> songs[index].length;
	file >> songs[index].genre;
	file >> songs[index].res;
}

// Function to populate one playlist with songs in the Playlist array
void populate_one_list(Playlist* playlists, int index, ifstream& file) { // Takes a pointer to the array of Playlist struts
	file >> playlists[index].name >> playlists[index].num_song;	// Read and store the playlist name and number of songs in each playlist
	playlists[index].s = create_songs(playlists[index].num_song);   // Create an dynamic array of songs for the current playlist based on number of songs in playlist

	for (int i = 0; i < playlists[index].num_song; ++i) {	// This will popualte the individual songs in the playlist
		populate_one_song(playlists[index].s, i, file); // Uses the function to populate a song
	}
}

// Function to populate each playlist
void populate_all_playlists(Playlist* playlists, int num_playlist, ifstream& file) {
	for (int i = 0; i < num_playlist; ++i) {    // Runs for number of playlists in file
		populate_one_list(playlists, i, file);  // Uses the function to populate a playlist
	}
}

// Function to display all songs with regard to age
// Function is long because there are a lot of checks that need to be made in order to ensure that the output is correct for the age given. There are also a lot of lines for considering user input error.
void display_all_songs(Playlist* playlists, int num_playlists) {
    int user_age;

    while (true) {  // Get the users' age
        cout << "Enter your age: ";
        cin >> user_age;

        // Check for invalid input
        if (cin.fail() || user_age < 0 || user_age > 120) { // Checks if the input fails, Minimum and maximum age of user
            cin.clear(); // Clear the error flag so it can be checked again
            cin.ignore(1000, '\n'); // Ignores up to 1000 characteres or until a new line. Discards the invalid input
            cout << "Invalid age. Please enter a valid age.\n";
        } else {    // If the input is valid
            break; // Break out of loop and proceed to next step
        }
    }

    int displayChoice;

    while (true) {  // Ask how user would like to display information
        cout << "How would you like the information displayed?" << endl;
        cout << "1. Print to screen" << endl;
        cout << "2. Print to file" << endl;
        cout << "Your Choice: ";

        cin >> displayChoice;

        if (cin.fail() || (displayChoice != 1 && displayChoice != 2)) { // If the user input is not 1 or 2, the function fails
            cin.clear();    // Clears the error flag so that it can be checked again
            cin.ignore(1000, '\n'); // Ignores up to 1000 characteres or until a new line. Discards the invalid input
            cout << "Invalid choice. Please enter either '1' or '2'.\n";
        } else {    // If the input is valid
            break;  // Break out of loop and proceed to next step
        }
    }

    if (displayChoice == 2) {   // Process songs into a file if choice is 2
        string filename;
        cout << "Please provide desired filename: ";
        cin >> filename;    // User input will be set to filename variable

        ofstream outFile(filename.c_str()); // Open file for writing, filename.c_str converts string style for ofstream
        if (!outFile.is_open()) {   // Checks if the file is open already, if so, print error
            cerr << "Cannot open file " << filename << " for writing." << endl;
            return;
        }

        for (int i = 0; i < num_playlists; ++i) {   // Loops for each playlist
            outFile << "\nPlaylist: " << playlists[i].name << endl;

            for (int j = 0; j < playlists[i].num_song; ++j) {   // Loop through each song in the playlist
                Song song = playlists[i].s[j];  // For current song:
                // Check if song is restricted
                if (song.res == "E" && user_age <= 17) { // Skip explicit songs for users 18 or below by checking both res is E and that user age is above 18
                    continue;
                }
                // Output to file using outFile
                outFile << "  Name: " << song.name << endl;
                outFile << "  Artist: " << song.artist << endl;
                outFile << "  Year Released: " << song.year_release << endl;
                outFile << "  Length: " << song.length << " minutes" << endl;
                outFile << "  Genre: " << song.genre << endl;
                outFile << "  Restriction: " << song.res << endl;
                outFile << "-------------------------------" << endl;
            }
        }

        outFile.close();    // Closes file so it can be open with other functions
        cout << "Appended requested information to file." << endl;
    } else {    // Display on screen
        for (int i = 0; i < num_playlists; ++i) {   // Loops for each playlist
            cout << "\nPlaylist: " << playlists[i].name << endl;
            for (int j = 0; j < playlists[i].num_song; ++j) {   // Loops for every song in playlist
                Song song = playlists[i].s[j];  // For current song:
                if (song.res == "E" && user_age <= 17) {    // Skip explicit songs for users 18 or below
                    continue;
                }

                // Uses print to screen function
                print_song_info(song);
            }
        }
    }
}

// Function to search for specific song
// Function is long because the function needs to search through through the arrays. The printing normally can be split to another function, however in for this one it needs a different format.
void search_song(Playlist* playlists, int num_playlists) {
    string song_name; // Temporary variable for the search function
    cout << "Enter the name of the song: ";
    cin >> song_name;

    bool song_found = false;    // Initializes the the variable to false
    int displayChoice;  // Declare displayChoice here

    while (true) { // Asks user how they want info to be dispalyed
        cout << "How would you like the information displayed?" << endl;
        cout << "1. Print to screen" << endl;
        cout << "2. Print to file" << endl;
        cout << "Your Choice: ";

        cin >> displayChoice; 

        if (cin.fail() || (displayChoice != 1 && displayChoice != 2)) { // If the user input is not 1 or 2, the function fails
            cin.clear();    // Clear the error flag so it can be checked again
            cin.ignore(1000, '\n'); // Ignores up to 1000 characteres or until a new line. Discards the invalid input
            cout << "Invalid choice. Please enter either '1' or '2'.\n";
        } else {
            break;
        }
    }

    if (displayChoice == 2) {
        string filename;
        cout << "Please provide desired filename: ";
        cin >> filename;    // Takes user input as file name

        ofstream outFile(filename.c_str()); // Open file for writing
        if (!outFile.is_open()) {
            cerr << "Cannot open file " << filename << " for writing." << endl;
            return;
        }

        for (int i = 0; i < num_playlists; ++i) {
            for (int j = 0; j < playlists[i].num_song; ++j) {
                if (playlists[i].s[j].name == song_name) {
                    outFile << "\nHere is the info of the song:" << endl;
                    outFile << "-------------------------------" << endl;

                    // Output information directly to file
                    outFile << "  Name: " << playlists[i].s[j].name << endl;
                    outFile << "  Artist: " << playlists[i].s[j].artist << endl;
                    outFile << "  Year Released: " << playlists[i].s[j].year_release << endl;
                    outFile << "  Length: " << playlists[i].s[j].length << " minutes" << endl;
                    outFile << "  Genre: " << playlists[i].s[j].genre << endl;
                    outFile << "  Restriction: " << playlists[i].s[j].res << endl;
                    outFile << "-------------------------------" << endl;

                    song_found = true;  // Song_found bool is now true
                    break;
                }
            }
        }

        outFile.close();    // Close file for later use
        if (song_found) {
            cout << "Appended requested information to file." << endl;
        } else {
            cout << "Song not found." << endl;
        }
    } else {    // If user input for choice is not 2, will display to terminal
        // Display on screen
        for (int i = 0; i < num_playlists; ++i) {
            for (int j = 0; j < playlists[i].num_song; ++j) {
                if (playlists[i].s[j].name == song_name) {
                    cout << "\nHere is the info of the song:" << endl;
                    cout << "-------------------------------" << endl;

                    // Output information directly to console
                    cout << "  Name: " << playlists[i].s[j].name << endl;
                    cout << "  Artist: " << playlists[i].s[j].artist << endl;
                    cout << "  Year Released: " << playlists[i].s[j].year_release << endl;
                    cout << "  Length: " << playlists[i].s[j].length << " minutes" << endl;
                    cout << "  Genre: " << playlists[i].s[j].genre << endl;
                    cout << "  Restriction: " << playlists[i].s[j].res << endl;
                    cout << "-------------------------------" << endl;

                    song_found = true;  // song_found bool is now true
                    break;
                }
            }
        }

        if (!song_found) {  // Function will not work if song_found is not true
            cout << "Song not found." << endl;
        }
    }
}

// Function to search by genre
// Function is long because the displaying of information is different and cannot be reduced to a single function that loops, there are little changes.
void search_by_genre(Playlist* playlists, int num_playlists) {
    string search_genre;

    while (true) {  // Asks user to type in genre name until valid one is inputted
        cout << "Enter the genre you want: ";
        cin >> search_genre;

        bool found = false; // bool variable found, is set to false

        for (int i = 0; i < num_playlists; ++i) {   // Nested loops that looks through the playlists and songs until a genre name matches the input
            for (int j = 0; j < playlists[i].num_song; ++j) {
                if (playlists[i].s[j].genre == search_genre) {
                    found = true;   // Set bool variable to true if song matches
                    break;  // Break out of inner loop if match found
                }
            }
            if (found) {
                break;  // Need to break out of outer loop if match found
            }
        }
        if (found) {
            break;  // Need to break out of input loop if match found
        } else {
            cout << "Genre not found. Please enter a valid genre.\n";
        }
    }

    int displayChoice;

    while (true) {
        cout << "How would you like the information displayed?" << endl;
        cout << "1. Print to screen" << endl;
        cout << "2. Print to file" << endl;
        cout << "Your Choice: ";
        
        cin >> displayChoice;

        if (cin.fail() || (displayChoice != 1 && displayChoice != 2)) { // If the user input is not 1 or 2, the function fails
            cin.clear();    // Clear the error flag so it can be checked again
            cin.ignore(1000, '\n'); // Ignores up to 1000 characteres or until a new line. Discards the invalid input
            cout << "Invalid choice. Please enter either '1' or '2'.\n";
        } else {
            break;
        }
    }

    if (displayChoice == 2) {   // Process songs into a file if choice is 2
        string filename;
        cout << "Please provide desired filename: ";
        cin >> filename;    // User input will be set to filename variable

        ofstream outFile(filename.c_str(), ios::app); // Open file for writing, filename.c_str converts string style for ofstream
        if (!outFile.is_open()) {   // Checks if the file is open already, if so, print error
            cerr << "Cannot open file " << filename << " for writing." << endl;
            return;
        }

        for (int i = 0; i < num_playlists; ++i) {   // Loop through each song in the playlist
            for (int j = 0; j < playlists[i].num_song; ++j) {   // For current song
                if (playlists[i].s[j].genre == search_genre) {
                    outFile << "\nPlaylist: " << playlists[i].name << endl;
                    outFile << "  Name: " << playlists[i].s[j].name << endl;
                    outFile << "  Artist: " << playlists[i].s[j].artist << endl;
                    outFile << "  Year Released: " << playlists[i].s[j].year_release << endl;
                    outFile << "  Length: " << playlists[i].s[j].length << " minutes" << endl;
                    outFile << "  Genre: " << playlists[i].s[j].genre << endl;
                    outFile << "  Restriction: " << playlists[i].s[j].res << endl;
                    outFile << "-------------------------------" << endl;
                }
            }
        }

        outFile.close();    // Close file for other use
        cout << "Appended requested information to file." << endl;
    } else {
        // Output to terminal
        for (int i = 0; i < num_playlists; ++i) {
            for (int j = 0; j < playlists[i].num_song; ++j) {
                if (playlists[i].s[j].genre == search_genre) {
                    cout << "\nPlaylist: " << playlists[i].name << endl;
                    cout << "  Name: " << playlists[i].s[j].name << endl;
                    cout << "  Artist: " << playlists[i].s[j].artist << endl;
                    cout << "  Year Released: " << playlists[i].s[j].year_release << endl;
                    cout << "  Length: " << playlists[i].s[j].length << " minutes" << endl;
                    cout << "  Genre: " << playlists[i].s[j].genre << endl;
                    cout << "  Restriction: " << playlists[i].s[j].res << endl;
                    cout << "-------------------------------" << endl;
                }
            }
        }
    }
}

// Function to display length of all playlists
// Function is long because it displays very different information from the other functions and needs unique formatting for printing.
void length_of_all_playlists(Playlist* playlists, int num_playlists) {
    int displayChoice;  // Declare displayChoice here

    while (true) {  // Asks user how they want info to be dispalyed
        cout << "How would you like the information displayed?" << endl;
        cout << "1. Print to screen" << endl;
        cout << "2. Print to file" << endl;
        cout << "Your Choice: ";

        cin >> displayChoice;

        if (cin.fail() || (displayChoice != 1 && displayChoice != 2)) { // If the user input is not 1 or 2, the function fails
            cin.clear();    // Clear the error flag so it can be checked again
            cin.ignore(1000, '\n'); // Ignores up to 1000 characteres or until a new line. Discards the invalid input
            cout << "Invalid choice. Please enter either '1' or '2'.\n";
        } else {
            break;
        }
    }

    if (displayChoice == 2) {   // Process for printing to file
        string filename;
        cout << "Please provide desired filename: ";
        cin >> filename;    // Takes filename from input

        ofstream outFile(filename.c_str()); // Open file for writing
        if (!outFile.is_open()) {   // If file is open already, error
            cerr << "Cannot open file " << filename << " for writing." << endl;
            return;
        }

        for (int i = 0; i < num_playlists; ++i) {   // Loop for each playlist
            float playlist_length = 0.0;    // Variable is float, same as text file

            for (int j = 0; j < playlists[i].num_song; ++j) {   // Loop for each song
                playlist_length += playlists[i].s[j].length; // Calculate total lengths
            }

            outFile << playlists[i].name << ": " << playlist_length << " minutes" << endl;  // Output total length to file
        }

        outFile.close();
        cout << "Appended requested information to file." << endl;
    } else {
        // Display on screen
        for (int i = 0; i < num_playlists; ++i) {   // Loop for each playlist
            float playlist_length = 0.0;

            for (int j = 0; j < playlists[i].num_song; ++j) {   // Loop for each song
                playlist_length += playlists[i].s[j].length; // Accumulate song lengths
            }

            cout << playlists[i].name << ": " << playlist_length << " minutes" << endl; // Output total length to terminal
        }
    }
}

// Function to print information of a playlist
void print_playlist_info(Playlist& playlist) {
    cout << "PLaylist: " << playlist.name << endl;
    cout << "-------------------------------" << endl;
    for (int i = 0; i < playlist.num_song; ++i) {   // Loops for number of songs in the playlist
        print_song_info(playlist.s[i]); // Reuse the print_song_info function
    }
}

// Function to print information of a song
 void print_song_info(Song& song) { // Prints song information based on reference to Song struct
    cout << "  Name: " << song.name << endl;
    cout << "  Artist: " << song.artist << endl;
    cout << "  Year Released: " << song.year_release << endl;
    cout << "  Length: " << song.length << " minutes" << endl;
    cout << "  Genre: " << song.genre << endl;
    cout << "  Restriction: " << song.res << endl;
    cout << "-------------------------------" << endl;
} 

// Function to delete memory
void delete_info(Playlist* playlists, int num_playlists) {
	for (int i = 0; i < num_playlists; ++i) {   // Loop through each playlist created
		delete[] playlists[i].s;    // Delete dynamically allocated array of songs for each playlist
	}
	delete[] playlists; // Delete dynamically allocated array of palylists
}

// Function to quit
void quit() {
	cout << "Goodbye!" << endl;
	exit(0);
}