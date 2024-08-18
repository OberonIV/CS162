#include "flight.h"

using namespace std;
//Constructor
Flight::Flight() : flight_num(""), curr_loc(""), dest(""), num_pilots(0), pilots(nullptr) {

}
//Destructor
Flight::~Flight(void){
	delete[] pilots; 
}

void Flight::populate_flight(ifstream& fin) {
	//Your code goes here:
	fin >> flight_num >> curr_loc >> dest >> num_pilots;
	
	pilots = new string[num_pilots];
	
	for(int i = 0; i < num_pilots; i++){
		fin >> pilots[i];
	}
	return;
}

void Flight::print_flight() const{
	//Your code goes here:
	// Prints all data to console
	cout << endl;
	cout << "Flight Number: " << flight_num << endl;
	cout << "Current Airport: " << curr_loc << endl;
	cout << "Destination: " << dest << endl;
	cout << "Number of pilots: " << num_pilots << endl;
	cout << "Pilots: " << endl;
	for(int i = 0; i < num_pilots; i++){
		cout << pilots[i] << " ";
	}
	cout << endl;
	return;
}
// Accessors
string Flight::get_flight_num() const{
	return this->flight_num;
}

string Flight::get_curr_loc() const{
	return this->curr_loc;
}

string Flight::get_dest() const{
	return this->dest;
}

int Flight::get_num_pilots() const{
	return this->num_pilots;
}

string* Flight::get_pilots() const{
	return this->pilots;
}

// Mutators
void Flight::set_flight_num(string flight_num){
	this->flight_num = flight_num;
	return;
}

void Flight::set_curr_loc(string curr_loc){
	this->curr_loc = curr_loc;
	return;
}

void Flight::set_dest(string dest){
	this->dest = dest;
	return;
}

void Flight::set_num_pilots(int num_pilots){
	this->num_pilots = num_pilots;
	return;
}

void Flight::set_pilots(string* new_pilots){
	// Clears memory
	delete[] this->pilots;
	// Creates new array
    this->pilots = new string[this->num_pilots];
    for (int i = 0; i < this->num_pilots; i++) {
		// Sets pilot based on num_pilots
        this->pilots[i] = new_pilots[i];
    }
}

void Flight::set_pilot_name(int idx, string& name){
	//If not exists, creates new array
	if (!pilots) {
        pilots = new string[num_pilots];
    }
	// If within valid index, sets pilot name to array
    if (idx >= 0 && idx < num_pilots) {
        pilots[idx] = name;
    } else {
        cout << "Invalid index for pilot name." << endl;
    }
}

// Assignment operator overload
Flight& Flight::operator=(const Flight&other){
	if (this != &other){
		delete [] this->pilots;

		this->flight_num = other.flight_num;
		this->curr_loc = other.curr_loc;
		this->dest = other.dest;
		this->num_pilots = other.num_pilots;

		if(other.pilots){
			this->pilots = new string[this->num_pilots];
			for(int i = 0; i < this->num_pilots; i++){
				this->pilots[i] = other.pilots[i];
			}
		}
		else{
			this->pilots = nullptr;
		}
	}
	return *this;
}
// Copy constructor
Flight::Flight(const Flight &other){
	this->flight_num = other.flight_num;
	this->curr_loc = other.curr_loc;
	this->dest = other.dest;
	this->num_pilots = other.num_pilots;

	this->pilots = new string[this->num_pilots];
	for(int i = 0; i < this->num_pilots; i++){
		this->pilots[i] = other.pilots[i];
	}
}

void Flight::flight_to_file(ofstream& fout){
	// Prints all data to file
	fout << flight_num << " " << curr_loc << " " << dest << " " << num_pilots;
	if(pilots){
		for(int i = 0; i < num_pilots; i++){
			fout << " " << pilots[i];
		}
	}
	fout << endl;
}