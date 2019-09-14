/*****************************************************************
** Program Filename: ReptilePeople.hpp
** Author: Makenzie Brian
** Date: November 6, 2015
** Description:
** Input:
** Output:
*****************************************************************/

#ifndef REPTILEPEOPLE_HPP
#define REPTILEPEOPLE_HPP

#include "Creature.hpp"
#include <iostream>
#include <string>

using namespace std;

class ReptilePeople: public Creature{
	public:
		ReptilePeople();
		void attack();
		void defense();

};

/********************************************************************
** Function: ReptilePeople()
** Description: constructor
** Parameters: none
** Pre-Conditions: must have creature
** Post-Conditions: reptiley is creature
********************************************************************/

ReptilePeople::ReptilePeople():Creature(){
	name = "Reptile Guy";
	armor = 7;
	strengthPoints = 18;
	heads = 0;
}




/********************************************************************
** Function: attack()
** Description: calcs attack strength
** Parameters: none
** Pre-Conditions: variable and function must exist
** Post-Conditions: gives attack strength
********************************************************************/
void ReptilePeople::attack(){
	attackStrength = dice(6);
	attackStrength += dice(6);
	attackStrength += dice(6);
	cout<<"Reptile thing attack strength: "<< attackStrength<<endl;

}



/********************************************************************
** Function: defense()
** Description: calcs defense strength
** Parameters: none
** Pre-Conditions: functions and vatiables must exist
** Post-Conditions: gives defense strength
********************************************************************/
void ReptilePeople::defense(){
	defenseStrength = dice(6);
	cout<<"Reptile thing defense strength: "<<defenseStrength<<endl;
}


#endif
