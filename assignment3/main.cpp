/****************************************************** 
** Program: flight_manager.cpp 
** Author: Carl Jeffri Resurrecion
** Date: 2/20/2024 
** Description: A program that will manage various airports and its flights. The program utilizes object oriented programming and 
** the big three (Destructors, CC, and AOO) to achieve its functions: List all flights, find a certain flight, add a new flight, cancel flights,
** take off flights, and print airport statistics. 
** Input: The user will input their menu choice, and integers to select Airports and Flights, as well as strings to input flight and pilot names.
** Output: The program will print all functions to the console as well as modifying the provided text file.
******************************************************/
#include <iostream>
#include "manager.h"

using namespace std;

int main()
{
	Manager m;
	m.run();
	return 0;
}
