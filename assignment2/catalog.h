/*********************************************************************
** Program Filename: The Tune Finder
** Author: Dylan Sutardjo
** Date: 2/12/24
** Description: A program that takes information from a set list of playlists and songs to provide the user with information about the selected elements. Creates arrays of playlists that contain arrays of songs based on the file
** 				provided. The user can select what information that they would like to view, as well as search for a specific song. Certain songs are not allowed to be displayed if the user is underage.
** Input: Take integers from the user to select which function they would like carry out as well as integer for their age. Then when searching for song titles or for genres, the input must be EXACTTLY the same as the text in the
**		  file. Otherwise, the user will be reprompted.
** Output: The outputs will either be displayed in the terminal or the user will have the option to write it to a file of their choosing. Functions will output information about songs (title, artist, etc.) which all come from the
**		   file and the structs. When the length of all playlists is requested, the program will output the length in minutes of each playlist.
*********************************************************************/
#ifndef CATALOG_H
#define CATALOG_H
#include <iostream>
#include <fstream>

using namespace std;

//a struct to hold info of a Playlist
struct Playlist {
	string name;        //name of the playlist, one word
	int num_song;       //number of songs in the playlist
	struct Song *s;     //an array that holds all songs in the playlist
	float total_len;    //total length of the playlist
};

//a struct to hold info of a Song
struct Song {
	string name;		//name of the song, one word
	string artist;		//name of the artist, one word
	int year_release;	//the year of release
	float length;		//length of the song
	string genre;		//genre of the song, one word
	string res;		//"E" or "none" for restriction level
};

/**************************************************
 * Name: create_playlists()
 * Description: This function will dynamically allocate
				an array of playlists (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Playlist array of requested size is created and return
 ***********************************************/
Playlist* create_playlists(int);

/**************************************************
 * Name: populate_one_list()
 * Description: This function will fill a single playlist struct 
				with information that is read in from the file
 * Parameters:  Playlist* - pointer to the Playlist array
				int - index of the Playlist in the array to be filled 
				ifstream& - input file to get the Playlist information
 * Pre-conditions: Playlist array has been allocated; 
				 provided index is less than the array size
 * Post-conditions: a Playlist at provided index is populated
 ***********************************************/
void populate_one_list(Playlist*, int, ifstream &); 


/**************************************************
 * Name: create_songs()
 * Description: This function will dynamically allocate
				an array of songs (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Song array of requested size is created and return
 ***********************************************/
Song* create_songs(int);


/**************************************************
 * Name: populate_one_song()
 * Description: This function will fill a single song struct 
				with information that is read in from the file
 * Parameters:  Song* - pointer to the Song array
				int - index of the Song in the array to be filled 
				ifstream& - input file to get the Song information
 * Pre-conditions: Song array has been allocated; 
				 provided index is less than the array size
 * Post-conditions: a Song at provided index is populated
 ***********************************************/
void populate_one_song(Song*, int, ifstream &); 


/**************************************************
 * Name: delete_info()
 * Description: This function will  delete all the memory that was dynamically allocated
 * Parameters: Playlist* - the Playlist array
 * Pre-conditions: the provided Playlist array hasn't been freed yet
 * Post-conditions: the Playlist array, with all Songs inside, is freed
 ***********************************************/
void delete_info(Playlist*, int);


/**************************************************
 * Name: print_playlist_info
 * Description: Prints the title of playlist
 * Parameters: Playlist& - a reference to the playlist struct
 * Pre-conditions: Array has been initialized, elements in arrays have songs
 * Post-conditions: Outputs to console or file, does not modify the arrays
 ***********************************************/
void print_playlist_info(Playlist& playlist);


/**************************************************
 * Name: print_song_info()
 * Description: Prints the information of each song
 * Parameters: Song& - Reference to Song struct
 * Pre-conditions: Struct needs to be initialized. There must be correct values for each element of the song.
 * Post-conditions: Outputs to console of file, does not modify the arrays, correctly displays matching information from text file.
 ***********************************************/
void print_song_info(Song& song);


/**************************************************
 * Name: readSongsPerPlaylist()
 * Description: Reads the number of songs in each playlist.
 * Parameters: Playlist* - pointer to playlist array
 * 			   num_playlists - number of playlists in file
 * 			   ifstream& - reference to the input file
 * Pre-conditions: Pointer must point to valid array of structs 
 * Post-conditions: Memory is allocated for each playlist's array, output matches info in file 
 ***********************************************/
int readSongsPerPlaylist(Playlist* playlists, int num_playlists);


/**************************************************
 * Name: populate_all_playlists()
 * Description: Populates the arrays of playlists by reading information from multiple playlists
 * Parameters: Playlist* - pointer to playlist array
 * 			   num_playlists - number of playlists in file
 * 			   ifstream& - reference to the input file
 * Pre-conditions: Pointer must point to a valid array of playlists
 * Post-conditions: Playlist array will be have correct information about playlists from file
 ***********************************************/
void populate_all_playlists(Playlist* playlists, int num_playlists, ifstream& file);


/**************************************************
 * Name: display_all_songs()
 * Description: Option 1 on menu, displays information about all songs in file. If user is under 18 years old, does not print songs flagged as explicit.
 * Parameters: Playlist* - pointer to playlists array
 * 			   num_playlists - number of playlists in file
 * Pre-conditions: Pointer must point to valid array of playlists. Arrays must be populated with correct information.
 * Post-conditions: Information will be displayed in terminal or written to a file. No changes are mage to struct or memory.
 ***********************************************/
void display_all_songs(Playlist* playlists, int num_playlists);


/**************************************************
 * Name: search_song()
 * Description: Option 2 on menu, allows user to serach for specific song by title. Then displays all information about song in terminal or writes to file.
 * Parameters: Playlist* - pointer to playlists array
 * 			   num_playlists - number of playlists in file
 * Pre-conditions: Can take input. Pointer must point to valid array of playlists. Arrays must be populated with correct information.
 * Post-conditions: Information will be displayed in terminal or written to a file. No changes are mage to struct or memory.
 ***********************************************/
void search_song(Playlist* playlists, int num_playlists);


/**************************************************
 * Name: search_by_genre()
 * Description: Option 3 on menu, allows user to search for all songs of a certain genre. Then displays all information about song in terminal or writes to file.
 * Parameters: Playlist* - pointer to playlist array
 * 			   num_playlists - number of playlists in file
 * Pre-conditions: Pointer must point to valid array of playlists. Arrays must be populated with correct information.
 * Post-conditions: Information will be displayed in terminal or written to a file. No changes are mage to struct or memory. Multiple songs will be printed.
 ***********************************************/
void search_by_genre(Playlist* playlists, int num_playlists);


/**************************************************
 * Name: length_of_all_playlists()
 * Description: Option 4 on menu, displays the total length in minutes of each playlist. Can be displayed in the terminal or written to a file.
 * Parameters: Playlist* - pointer to playlist array
 * 			   num_playlists - number of playlists in file
 * Pre-conditions: Pointer must point to valid array of playlists. Arrays must be populated with correct information (specifically the length of each song).
 * Post-conditions: Correctly sums total length of songs in each playlist. Information will be displayed in terminal or written to a file. No changes are mage to struct or memory.
 ***********************************************/
void length_of_all_playlists(Playlist* playlists, int num_playlists);


/**************************************************
 * Name: quit()
 * Description: Option 5 on menu, quits out of the program
 * Parameters: N/a
 * Pre-conditions: All clean up has been done already
 * Post-conditions: Exits out of program
 ***********************************************/
void quit();

#endif // CATALOG_H