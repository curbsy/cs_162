/*****************************************************************
** Program Filename: Gollum.hpp
** Author: Makenzie Brian
** Date: November 6, 2015
** Desription:
** Input:
** Output:
*****************************************************************/

#ifndef GOLLUM_HPP
#define GOLLUM_HPP

#include "Creature.hpp"
#include <iostream>
#include <string>

using namespace std;

class Gollum: public Creature{
	public:	
		Gollum();
		void attack();
		void defense();

};

/*****************************************************************
** Function: Gollum()
** Description: constructor
** Parameters: none
** Pre-Conditions: must have creature
** Post-Conditions: makes a gollum
******************************************************************/
Gollum::Gollum():Creature(){
	armor = 3;
	heads = 0;
	strengthPoints = 8;
}



/*****************************************************************
** Function: attack()
** Description: calcs attack strength
** Parameters: none
** Pre-Conditions: functions and variables must exist
** Post-Conditions: gives attack strength
******************************************************************/
void Gollum::attack(){
	int chance = rand() % 20;
	if(chance == 1){
		attackStrength = dice(6);
		attackStrength += dice(6);
		attackStrength += dice(6);
	}
	else{		
	attackStrength = dice(6);
	}
	cout<<"Gollum attack strength: "<< attackStrength<<endl;
}



/*****************************************************************
** Function: defense()
** Description: calcs defense strength
** Parameters: none
** Pre-Conditions: functions and variables must exist
** Post-Conditions: gives defense strength
******************************************************************/
void Gollum::defense(){
	defenseStrength = dice(6);
	cout<<"Gollum defense strength: "<<defenseStrength<<endl;
}

#endif

