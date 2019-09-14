/*****************************************************************
** Program Filename: BlueMen.hpp
** Author: Makenzie Brian
** Date: November 6, 2015
** Descripiton:
** Input:
** Output:
*****************************************************************/

#ifndef BLUEMEN_hpp
#define BLUEMEN_HPP

#include "Creature.hpp"
#include <iostream>
#include <string>

using namespace std;

class BlueMen: public Creature{
	public:
		BlueMen();
		void attack();
		void defense();

};

/******************************************************************
** Function: BlueMen()
** Description: constructor
** Parameters: none
** Pre-Conditions: must have creature
** Post-Conditions: there is a blue man
******************************************************************/
BlueMen::BlueMen():Creature(){
	armor = 3;
	strengthPoints = 12;
	heads = 0;
}


/******************************************************************
** Function: attack()
** Description: calcs attack strength
** Parameters: none
** Pre-Conditions: functions and variables must exist 
** Post-Conditions: gives attack strength
******************************************************************/
void BlueMen::attack(){
	attackStrength = dice(10);
	attackStrength += dice(10);
}


/******************************************************************
** Function: defense()
** Description: calcs defense strength
** Parameters: none
** Pre-Conditions: function and variables must exist
** Post-Conditions: gives defense strength
******************************************************************/
void BlueMen::defense(){
	defenseStrength = dice(6);
	defenseStrength += dice(6);
	defenseStrength += dice(6);
}

#endif

