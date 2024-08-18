#ifndef ADVENTURER_H
#define ADVENTURER_H
#include <iostream>
using namespace std;

class Adventurer{
public:
/*********************************************************************
** Function: Adventurer()
** Description: Adventurer constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Adventurer is created
*********************************************************************/
	Adventurer();
/*********************************************************************
** Function: is_alive
** Description: Checks if the adventurer is alive
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns alive status
*********************************************************************/
	bool is_alive;
/*********************************************************************
** Function: has_gold
** Description: Checks if the adventurer has_gold
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns gold status
*********************************************************************/
	bool has_gold;
/*********************************************************************
** Function: killed_wumpus
** Description: Checks if the adventurer has killed the wumpus
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns wumpus status
*********************************************************************/
	bool killed_wumpus;
/*********************************************************************
** Function: current_x
** Description: Checks the adventures current_x
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns x status
*********************************************************************/
	int current_x;
/*********************************************************************
** Function: current_y
** Description: Checks the adventures current_y
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns y status
*********************************************************************/
	int current_y;
/*********************************************************************
** Function: initial_x
** Description: Checks the adventures initial_x
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns x status
*********************************************************************/
	int initial_x;
/*********************************************************************
** Function: initial_y
** Description: Checks the adventures initial_y
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns y status
*********************************************************************/
	int initial_y;
/*********************************************************************
** Function: in_pool
** Description: Checks if the adventureris in a pool
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns pool status
*********************************************************************/
	bool in_pool;
/*********************************************************************
** Function: oxygen
** Description: Checks adventurer oxygen level
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns oxygen status
*********************************************************************/
	int oxygen;
/*********************************************************************
** Function: has_armour
** Description: Checks if the adventurer has armour
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns armour status
*********************************************************************/
	bool has_armour;
/*********************************************************************
** Function: armour_hit
** Description: Checks adventurers armour hit points
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns armour_hit status
*********************************************************************/
	int armour_hit;
};
#endif