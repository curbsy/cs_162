/******************************************************************
** Program Filename: Hydra.hpp
** Author: Makenzie Brian
** Date: November 6, 2015
** Description:
** Input:
** Output:
******************************************************************/

#ifndef HYDRA_HPP
#define HYDRA_HPP

#include "Creature.hpp"
#include <iostream>
#include <string>

using namespace std;

class Hydra: public Creature{
	private:
		int heads;
	public:
		Hydra();
		void attack();
		void defense();
};

/******************************************************************
** Function: Hydra()
** Description: constructor
** Parameters: none
** Pre-Conditions: functions and variables must exist
** Post-Conditions: there is a hydra
******************************************************************/
Hydra::Hydra():Creature(){
	name = "Hydra";
	armor = 3;
	heads = 1;
	attackStrength = 0;
	strengthPoints = 12;
}


/******************************************************************
** Function: attack()
** Description: calcs attack strength
** Parameters: none
** Pre-Conditions: function and variable must exist
** Post-Conditions: gives attack strength
******************************************************************/
void Hydra::attack(){
	for(int i =0; i<heads; i++){
		attackStrength += dice(6);
	}
	cout<<"Hydra attack strength: "<<attackStrength<<endl;
}


/******************************************************************
** Function: defense()
** Description: calcs defense strength
** Parameters: none
** Pre-Conditions: function and variables must exist
** Post-Comditions: gives defense strength
******************************************************************/
void Hydra::defense(){
	defenseStrength = dice(6);
	cout<<"Hydra defense strength: "<<defenseStrength<<endl;
}   


#endif

