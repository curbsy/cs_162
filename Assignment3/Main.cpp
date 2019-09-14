/****************************************************************
** Program Filename: Main.cpp
** Author: Makenzie Brian
** Date: November 6, 2015
** Description:
** Input:
** Output:
****************************************************************/

#include "Creature.hpp"
#include "Barbarian.hpp"
#include "ReptilePeople.hpp"
#include "BlueMen.hpp"
#include "Hydra.hpp"
#include "Gollum.hpp"
#include <iostream>
#include <time.h>

using namespace std;

int main(){
	srand(time(NULL));
	Creature *p1;
	Creature *p2;
	int x;

	cout<<"Pick creature 1: Barbarian(1), Reptile(2), Blue guy(3),";
	cout<< " Gollum(4), Hydra(5)" <<endl;
	cin >> x; 

	if(x==1){	
		p1 = new Barbarian;
	}
	if(x==2){
		p1 = new ReptilePeople;
	}
	if(x==3){
		p1 = new BlueMen;
	}
	if(x==4){
		p1 = new Gollum;
	}
	if(x==5){
		p1 = new Hydra;
	}


	cout<<"Pick creature 2: Barbarian(1), Reptile(2), Blue guy(3),";
	cout<< " Gollum(4), Hydra(5)" <<endl;
	cin >> x; 

	if(x==1){	
		p2 = new Barbarian;
	}
	if(x==2){
		p2 = new ReptilePeople;
	}
	if(x==3){
		p2 = new BlueMen;
	}
	if(x==4){
		p2 = new Gollum;
	}
	if(x==5){
		p2 = new Hydra;
	}


	while(p1 -> strengthPoints !=0 && p2 -> strengthPoints !=0){ 
		cout<<endl;
		p1 -> attack();
	
		p2 -> defense();	

		p2 -> strength(p1 -> attackStrength);

		cout<<endl;
		p2 -> attack();
	
		p1 -> defense();	
	
		p1 -> strength(p2 -> attackStrength);
	}
	
	if(p1 -> strengthPoints == 0){
		cout<<"Creature 1 is dead"<<endl;
	}
	else {
		cout <<"Creature 2 is dead"<<endl;
	}



}


