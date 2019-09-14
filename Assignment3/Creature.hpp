/*******************************************************************
** Program Filename: Creature.hpp
** Author: Makenzie Brian
** Date: November 6, 2015
** Description:
** Input:
** Output:
*******************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Creature{
	protected:
		int armor;
		int heads;
	public:
		int defenseStrength;
		int strengthPoints;
		int attackStrength;
		virtual void attack() = 0;
		virtual void defense() = 0;
		int dice(int sides);
		void strength(int attStr);
	
};




/*******************************************************************
** Function: Creature()
** Description: acts as die
** Parameters: int
** Pre-Conditions: given sides of die
** Post-Conditions: gives rand based on sides
*******************************************************************/

int Creature::dice(int sides){
	return rand() % sides + 1;
}


/*******************************************************************
** Function: strength()
** Description: calcs strength
** Parameters: int
** Pre-Conditions: given attack strength of opponent
** Post-Conditions: gives new strength 
*******************************************************************/
void Creature::strength(int attStr){
	int damage = 0;
	damage = attStr - defenseStrength - armor;
	
	if(damage > 0){
		cout << "Damage: " << damage<<endl;
		strengthPoints -= damage;
	}
	else{
		cout<<"No actual damage"<<endl;
	}
	if(strengthPoints < 0){
		strengthPoints = 0;
		if (heads !=0){
			int head = (rand() % 10);
			if (head == 1){
				heads++;
				armor = 3*heads;
				cout << "There are now "<<heads;
				cout <<  " heads" << endl;
			}
		}
	}

	cout << "Strength: " << strengthPoints << endl;
}


#endif
