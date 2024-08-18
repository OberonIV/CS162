#include "manager.h"

using namespace std;

Manager::Manager(){
	this->num_airports = 0;
	this->a_arr = nullptr;
}

Manager::~Manager() {
	delete[] a_arr;
}

void Manager::populate(ifstream& fin) {
	//Your code goes here:
	// Error handling if file does not exist
	if (!fin.is_open()){
		cout << "Error: Could not open the file." << endl;
		return;
	} 
	// Gets number of airports
	fin >> num_airports;
	// Creates array based on num_airports
	a_arr = new Airport[num_airports];
	// Populates airports with flights
	for(int i = 0; i < num_airports; i++){
		a_arr[i].populate_airport(fin);
	}
}

int Manager::init(){
	// Initializes
	ifstream fin("airport.txt");
	//Error opening file?:
	//Your code goes here:
	if (!fin.is_open()){
		cout << "Error opening file." << endl;
	}
	// Calls populate
	Manager::populate(fin);
	
	fin.close();
	
	return 1;
}

void Manager::print_menu(){
	// Prints menu choice
	cout << endl;
	cout << "1. View all Airports & Flights info" << endl;
	cout << "2. Check flight info" << endl;
	cout << "3. Add a new flight" << endl;
	cout << "4. Cancel a flight" << endl;
	cout << "5. Take off a flight" << endl;
	cout << "6. Print airport stats" << endl;
	cout << "7. Quit" << endl;

	cout << "Your choice: ";
}

int Manager::get_menu_choice() {
	int choice = 0;
	Manager::print_menu();
	// Gets choice from user
	cin >> choice;
	while(true){
		// Error handling if not valid
		if(cin.fail()){
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid Input. Please enter a valid input." << endl;
		}
		else{
			break;
		}
	}
	//Don't forget error handling!!!
	return choice;
}

void Manager::print_all(){
	//Your code goes here:
	// Prints airports, which in turns prints files
	for(int i = 0; i < num_airports; i++){
		a_arr[i].print_airport();
	}
	return; 
}

void Manager::check_flight_control() {
	//Your code goes here:
	string flight_num;
	cout << "Enter flight number: ";
	cin >> flight_num;
	
	bool flight_found = false;
	// Logic for searching for airport name
	for(int i = 0; i < num_airports; i++){
		for(int j = 0; j < a_arr[i].get_num_flights(); i++){
			if(a_arr[i].get_flight_num(j) == flight_num){
				// Prints if flight is found
				cout << endl;
				cout << "Flight found!" << endl;
				
				get_flight(i,j).print_flight();
				
				flight_found = true;
				break;
			}
		}
		if (flight_found){
			break;
		}
	}
	// Error if flight does not exist/not found
	if(flight_found = false){
			cout << "Flight not found. Please try again." << endl;
		}
	return; 
}

int Manager::get_airport_choice(int& airport_choice){
	// Prints all airports
	cout << "Available Airports:" << endl;

	for(int i = 0; i < num_airports; i++){
		cout <<  i + 1 << ": " << a_arr[i].get_name() << endl;
	}
	// Gets airport choice
	cout << "Choose an airport: ";
	cin >> airport_choice;
	// Error handling
	if(airport_choice < 1 || airport_choice > num_airports){
		cout << "Invalid choice. Please enter a number between 1 and " << num_airports << endl;
		return 0;
	}
	// Errors if airport is at capacity
	if(a_arr[airport_choice - 1].get_num_flights() >= a_arr[airport_choice - 1].get_cap()){
		cout << "Airport is full." << endl;
		return 0;
	}
	
	return airport_choice;
}


int Manager::get_flight_choice(int& flight_choice, int airport_choice){
	a_arr[airport_choice - 1].print_airport();
	// Gets flight choice
	cout << "Choose a flight: ";
	cin >> flight_choice;
	// Error handling
	if(flight_choice < 1 || flight_choice > a_arr[airport_choice - 1].get_num_flights()){
		cout << "Invalid choice. Please enter a number between 1 and " << num_airports << endl;
		return 0;
	}	
	
	return flight_choice;
}


void Manager::add_flight_control() {
	//Your code goes here:
	int airport_choice;
	string flight_num;
	string dest;
	int num_pilots;
	// Gets all user input
	airport_choice = get_airport_choice(airport_choice);
	cout << "Enter the flight number: ";
	cin >> flight_num;
	
	string curr_loc = a_arr[airport_choice - 1].get_name();
	
	cout << "Enter the destination: ";
	cin >> dest;
	
	cout << "Enter the number of pilots: ";
	cin >> num_pilots;
	
	Flight new_flight(num_pilots);
	// Gets pilot names
	for(int i = 0; i < num_pilots; i++){
		string pilot_name;
		cout << "Enter the name of the pilot " << i + 1 << ": ";
		cin >> pilot_name;
		new_flight.set_pilot_name(i, pilot_name);
	}
	// Sets all data
	new_flight.set_flight_num(flight_num);
	new_flight.set_curr_loc(curr_loc);
	new_flight.set_dest(dest);
	a_arr[airport_choice - 1].add_a_flight(new_flight);
	
	cout << "New flight added successfully to " << a_arr[airport_choice - 1].get_name() << endl;
	return; 
}

void Manager::cancel_flight_control() {
	//Your code goes here:
	int flight_choice; 
	int airport_choice;
		// Prints all airports
	cout << "Available Airports:" << endl;

	for(int i = 0; i < num_airports; i++){
		cout <<  i + 1 << ": " << a_arr[i].get_name() << endl;
	}
	// Gets airport choice
	cout << "Choose an airport: ";
	cin >> airport_choice;
	// Error handling

	if(airport_choice < 1 || airport_choice > num_airports){
		cout << "Invalid choice. Please enter a number between 1 and " << num_airports << endl;
		return;
	}
	
	flight_choice = get_flight_choice(flight_choice, airport_choice);
	
	Flight canceled_flight = a_arr[airport_choice - 1].get_flight(flight_choice -1);
	
	a_arr[airport_choice - 1].remove_a_flight(flight_choice - 1);
	
	cout << "Flight Cancelled" << endl;
	return;
}

void Manager::take_off_control() {
	//Your code goes here:
	int flight_choice; 
	int airport_choice;
	// Gets all user choices
	airport_choice = get_airport_choice(airport_choice);
	
	flight_choice = get_flight_choice(flight_choice, airport_choice);
	
	flight_choice--;
	
	Flight taken_flight = a_arr[airport_choice - 1].get_flight(flight_choice);
	
	a_arr[airport_choice - 1].remove_a_flight(flight_choice);
	
	bool found_dest = false;
	// Take off logic
	for (int i = 0; i < num_airports; i++) {
       if (a_arr[i].get_name() == taken_flight.get_dest()) {
           if (a_arr[i].get_num_flights() < a_arr[i].get_cap()) {
               taken_flight.set_curr_loc(a_arr[i].get_name());
               a_arr[i].add_a_flight(taken_flight);
                
               cout << "Take off successful." << endl;
			} else {
               cout << "Destination airport is at full capacity." << endl;
               a_arr[airport_choice - 1].add_a_flight(taken_flight);
            }
            found_dest = true;  // Set found_dest to true when destination airport is found
            break;
        }
    }
    
    if (!found_dest) {
        cout << "Destination airport not found." << endl;
        a_arr[airport_choice - 1].add_a_flight(taken_flight);
    }
    return; 
}

void Manager::stats_control() {
	//Your code goes here:
	cout << "Airport Stats: " << endl;
	// Logic for printing stats
	for(int i = 0; i < num_airports; i++){
		cout << a_arr[i].get_name() << endl;
		cout << "Capactity: " << a_arr[i].get_cap();
		cout << endl;
		int flight_count = 0;
		string curr_airport_name = a_arr[i].get_name();
		
		for(int j = 0; j < num_airports; j++){
			for(int k = 0; k < a_arr[j].get_num_flights(); k++){
				if(a_arr[j].get_dest(k) == curr_airport_name){
					flight_count++;
				}
			}
		}
		cout << "Listed as destination: " << flight_count << " flights" << endl;
		cout << endl;
	}
	return; 
}

Flight& Manager::get_flight(int airport_index, int flight_index){
	return a_arr[airport_index].get_flight(flight_index);
}

void Manager::run() {
	cout << endl;
	cout << "Welcome to Flight Manager!!" << endl;
	if (Manager::init() != 1)
		return;

	int choice = -1;
	while (choice != 7)
	{
		choice = Manager::get_menu_choice();
		//print all
		if (choice == 1) 
			Manager::print_all();

		//flight info
		else if (choice == 2){
			Manager::check_flight_control();
		}
		//add a new flight
		else if (choice == 3) {
			Manager::add_flight_control();
		}
		//cancel a flight
		else if (choice == 4) {
			Manager::cancel_flight_control();
		}
		//take off a flight
		if (choice == 5){
			Manager::take_off_control();
		}
		//airport stats
		else if (choice == 6) {
			Manager::stats_control();
		}
	}
	save_to_file();
	cout << "Bye!" << endl << endl;

	return;
}

void Manager::save_to_file(){
	// Saves all data to file
	ofstream fout("airport.txt");
	
	if(!fout.is_open()){
		cout << "Error! Could not open file." << endl;
		return;
	}
	
	fout << num_airports << endl;
	
	for(int i = 0; i < num_airports; i++){
		a_arr[i].airport_to_file(fout);
	}
	
	fout.close();
}