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
#include <string>

using namespace std;

int main(){
	srand(time(NULL));
	Queue q1;
	Queue q2;
	Stack losted;

	Creature *p1;
	Creature *p2;

	string nickname;
	int pick, team1Numb, team2Numb, viewStack;

	cout << "Enter number of creatures for team 1: "<< endl;
	cin >> team1Numb;
	cout << "Enter number of creatures for team 2: "<< endl;
	cin >> team2Numb;


	for(int i=0; i<team1Numb;i++){
		cout<<"Pick creature 1: Barbarian(1), Reptile(2), Blue guy(3),";
		cout<< " Gollum(4), Hydra(5)" <<endl;
		cin >> pick; 

		if(pick==1){	
			p1 = new Barbarian;
		}
		if(pick==2){
			p1 = new ReptilePeople;
		}
		if(pick==3){
			p1 = new BlueMen;
		}
		if(pick==4){
			p1 = new Gollum;
		}
		if(pick==5){
			p1 = new Hydra;
		}
		cout <<"Enter nickname: ";
		cin >> nickname;
		q1.addInit(p1, 1, nickname);
	}
	q1.display();
	cout<<endl;


	for(int i=0; i<team2Numb;i++){
		cout<<"Pick creature 1: Barbarian(1), Reptile(2), Blue guy(3),";
		cout<< " Gollum(4), Hydra(5)" <<endl;
		cin >> pick; 

		if(pick==1){	
			p2 = new Barbarian;
		}
		if(pick==2){
			p2 = new ReptilePeople;
		}
		if(pick==3){
			p2 = new BlueMen;
		}
		if(pick==4){
			p2 = new Gollum;
		}
		if(pick==5){
			p2 = new Hydra;
		}
		cout <<"Enter nickname: ";
		cin >> nickname;
		q2.addInit(p2, 2, nickname);
	}
	q2.display();
	cout<<endl;

	p1 = q1.first();
	p2 = q2.first();

	while(!(q1.check() || q2.check())){ 
		cout<<endl;
		p1 -> attack();
	
		p2 -> defense();	

		p2 -> strength(p1 -> attackStrength);
		if(p2 -> strengthPoints <= 0){
			if(!q2.check()){
				losted.add(p2, 2, 1);
				q2.del(p2);
				q2.display();
			}	
			if(!q2.check()){
				p2 = q2.first();
			}
			q1.add(p1,1);
			q1.del(p1);
			if(!q1.check()){
				p1 = q1.first();
			}
		}
		cout<<endl;


		p2 -> attack();
	
		p1 -> defense();	
	
		p1 -> strength(p2 -> attackStrength);

		if(p1 -> strengthPoints <= 0){
			if(!q1.check()){
				losted.add(p1, 1, 2);
				q1.del(p1);
				q1.display();
			}	
			if(!q1.check()){
				p1 = q1.first();
			}
			q2.add(p2,2);
			q2.del(p2);
			if(!q2.check()){
				p2 = q2.first();
			}
		}
		cout<<endl;
	}
	
	if(q2.check()){
		while(!q1.check()){
			losted.add(p1,1,0);
			q1.del(p1);
			if(!q1.check()){
				p1 = q1.first();
			}
		}
	}

	if(q1.check()){
		while(!q2.check()){
			losted.add(p2,2,0);
			q2.del(p2);
			if(!q2.check()){
				p2 = q2.first();
			}
		}
	}

	int tot;
	tot = team1Numb + team2Numb;
	
	if(tot>3){
		losted.winners();
	}
	else{
		losted.winners2();
	}
	cout<<endl;
	cout<<"Enter 1 if you want to see the losers."<<endl;
	cin>>viewStack;
	if(viewStack == 1){
		losted.display();
	}
	return 0;
}


