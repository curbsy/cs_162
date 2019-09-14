/*****************************************************************
** Program Filename: Barbarian.hpp
** Author: Makenzie Brian
** Date: November 6, 2015
** Description:
** Input:
** Output:
****************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Creature.hpp"
#include <iostream>
#include <string>

using namespace std;

class Barbarian: public Creature{
	public:
		Barbarian();
		void attack();
		void defense();		

};


/******************************************************************
** Function: Barbarian()
** Decription: constructor
** Parameters: none
** Pre-Conditions: must have creature
** Post-Conditions: there will be a barbarian
******************************************************************/
Barbarian::Barbarian():Creature(){
	name = "Barbarian";
	armor = 0;
	strengthPoints = 12;
	heads = 0;
}



/******************************************************************
** Function: attack()
** Decription: calcs attack strength
** Parameters: none
** Pre-Conditions: functions and variables must exist
** Post-Conditions: gives atatck strength
******************************************************************/
void Barbarian::attack(){
	attackStrength = dice(6);
	attackStrength += dice(6);
	cout<< "Barbarian attack strength: " <<  attackStrength << endl;

}


/******************************************************************
** Function: defense()
** Decription: calcs defense strength
** Parameters: none
** Pre-Conditions: functions and variables must exist
** Post-Conditions: gives defense strength
******************************************************************/
void Barbarian::defense(){
	defenseStrength = dice(6);
	defenseStrength += dice(6);
	cout<< "Barbarian defense strength: " <<defenseStrength << endl;

}

#endif
