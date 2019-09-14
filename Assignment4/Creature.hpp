/*******************************************************************
** Program Filename: Creature.hpp
** Author: Makenzie Brian
** Date: November 6, 2015
** Description: Parent class for barbarian, gollum, etc.
** Input: stuff
** Output: things
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
		string name;
		string nickname;
		int damage;
	public:
		int defenseStrength;
		int strengthPoints;
		int attackStrength;
		virtual void attack() = 0;
		virtual void defense() = 0;
		int dice(int sides);
		void strength(int attStr);
		friend class Queue;
		friend class Stack;	
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
	damage = 0;
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


struct node{
	Creature *info;
	node *next;
	int team;
};



class Queue{
	private:
		node *rear;
		node *front;
		int size;
	public:
		Queue();
		void add(Creature *pick, int team);
		void addInit(Creature * pick, int team, string nickname);
		void del(Creature *pick);
		void display();
		bool check();
		Creature* first();
};



/*******************************************************************
** Function: Queue
** Description: constructor
** Parameters: none
** Pre-Conditions: variables must exist
** Post-Conditions: varaibles initialized
*******************************************************************/
Queue::Queue(){
	size = 0;
	rear = NULL;
	front = NULL;
}


/*******************************************************************
** Function: add
** Description: adds creature to queue
** Parameters: creature*, int
** Pre-Conditions: there must be a queue
** Post-Conditions: creature is added to queue
*******************************************************************/
void Queue::add(Creature *pick, int team){
	node *temp = new node;
	temp -> info = pick;
	temp -> team = team;
	temp -> next = NULL;
	if(front == NULL){
		front = temp;
	}
	else{
		rear -> next = temp;
	}
	rear = temp;
		cout <<endl<<"Creature Strength: "<<temp->info->strengthPoints<<endl;
	if(temp->info->damage>0){
		temp -> info -> strengthPoints += temp->info->damage*0.5;
		cout<< "Adjusted Strength: "<<temp->info->strengthPoints<<endl;
	}
	size++;
}


/*******************************************************************
** Function: addInit
** Description: adds first creature to queue
** Parameters: crature*, int, string
** Pre-Conditions: there must be a queue
** Post-Conditions: there will be a cretaure in the queue
*******************************************************************/
void Queue::addInit(Creature *pick, int team, string nickname){
	node *temp = new node;
	temp -> info = pick;
	temp -> team = team;
	temp -> info -> nickname = nickname;
	temp -> next = NULL;
	if(front == NULL){
		front = temp;
	}
	else{
		rear -> next = temp;
	}
	rear = temp;
	size++;
}


/*****************************************************************
** Function: del
** Description: deletes a creature from the queue
** Parameters: creature*
** Pre-Conditions: there must be craetures in the queue
** Post-Conditions: a creatre will be deleted from the queue
*******************************************************************/
void Queue::del(Creature *pick){
	node *temp = new node;
	if (front == NULL){
		cout << "Queue is empty, dumbbutt."<< endl;
	}
	else{
		temp = front;
		//cout<< temp->info->name<< " has lost."<<endl;
		front = front -> next;
		delete temp;
	}
	size--;
}


/*******************************************************************
** Function: display
** Description: displays queue
** Parameters: none
** Pre-Conditions: there must be a queue
** Post-Conditions: queue will be displayed
*******************************************************************/
void Queue::display(){
	node *p = front;
	if(size == 0){
		cout << "Queue is empty. Don't be a butt." <<endl;
	}
	else{
		while(p != NULL){
			cout<<endl;
			cout<<"There is a "<<p->info->name;
			cout<<" called "<< p->info->nickname<<endl;
			p = p -> next;
		}
	}

}


/*******************************************************************
** Function: first
** Description: makes creature class passable to queue
** Parameters: none
** Pre-Conditions: creature and queue must exist
** Post-Conditions: creature pointer can be used in queue
*******************************************************************/
Creature* Queue::first(){
	node *temp = new node;
	temp = front;
	return temp -> info;
}


/*******************************************************************
** Function: check
** Description: checks if queue is empty
** Parameters: none
** Pre-Conditions: queue must exist
** Post-Conditions: returns bool for emptyness for queue
*******************************************************************/
bool Queue::check(){
	if(size == 0){
		return true;
	}
	else{
		return false;
	}
}



class Stack{
	private:
		node *head;
		int pteam1;
		int pteam2;
	public:
		Stack();
		void add(Creature *pick, int team, int pt);
		void display();
		void winners();
		void winners2();
		bool check();
};



/*****************************************************************
** Function: Stack
** Description: constructor
** Parameters: none
** Pre-Conditions: variables must exist
** Post-Conditions: variables are initalized
*******************************************************************/
Stack::Stack(){
	head = NULL;
	pteam1 = 0;
	pteam2 = 0;
}


/*******************************************************************
** Function: add
** Description: adds creature to stack
** Parameters: creature*, int, int
** Pre-Conditions: stack must exist
** Post-Conditions: creature is added to stack
*******************************************************************/
void Stack::add(Creature *pick, int team, int pt){
	node *temp = new node;
	temp -> info = pick;
	temp -> team = team;
	if(check()){
		head = temp;
		temp -> next = NULL;
	}
	else{
		if(head != NULL){
			temp -> next = head;
		}
		head = temp;
	}
	if(pt == 1){
		pteam1++;
	}
	if(pt == 2){
		pteam2++;
	}

}


/*******************************************************************
** Function: display
** Description: displays contents of stack
** Parameters: none
** Pre-Conditions: stack must exist
** Post-Conditions: stack will be displayed
*******************************************************************/
void Stack::display(){
	node *p = head;
	if(head == NULL){
		cout<< "STHAWP I'M EMPTY."<<endl;
	}
	else{
		while(p != NULL){
			cout<<endl;
			cout<<"There is a "<<p->info->name;
			cout<<" called "<< p->info->nickname<<endl;
			p = p -> next;
		}
	}
}


/*******************************************************************
** Function: winners
** Description: displays top 3 winners
** Parameters: none
** Pre-Conditions: rounds must have finished
** Post-Conditions: 3 winners are displayed, and winning teams
*******************************************************************/
void Stack::winners(){
	int winner;
	node *stuff = head;
	cout << endl << "Winners are: "<<endl;


	for(int i=0; i<3; i++){
		cout<<"There is a "<<stuff->info->name;
		cout<<" called "<<stuff->info->nickname;
		cout<<" from team "<< stuff->team<<endl;
		
		if(stuff != NULL){
			stuff = stuff -> next;
		}
	}

	if(pteam1 > pteam2){
		cout<<"Team1 wins with "<< pteam1<< " points."<<endl;
	}
	if(pteam1 < pteam2){
		cout<<"Team2 wins with "<< pteam2<< " points."<<endl;
	}
	if(pteam1 == pteam2){
		cout<< "There is a tie. Both teams win and you lose because now you have to play again." <<endl;		
	}
}


/*******************************************************************
** Function: winners2
** Description: displays winners for only 2 players
** Parameters: none
** Pre-Conditions: rounds must have finished
** Post-Conditions: 2 players displayed as winners technically
*******************************************************************/
void Stack::winners2(){
	int winner;
	node *stuff = head;
	cout << endl << "Winners are: "<<endl;


	for(int i=0; i<2; i++){
		cout<<"There is a "<<stuff->info->name;
		cout<<" called "<<stuff->info->nickname;
		cout<<" from team "<< stuff->team<<endl;
		
		if(stuff != NULL){
			stuff = stuff -> next;
		}
	}

	if(pteam1 > pteam2){
		cout<<"Team1 wins with "<< pteam1<< " points."<<endl;
	}
	if(pteam1 < pteam2){
		cout<<"Team2 wins with "<< pteam2<< " points."<<endl;
	}
	if(pteam1 == pteam2){
		cout<< "There is a tie. Both teams win and you lose because now you have to play again." <<endl;		
	}
}




/*******************************************************************
** Function: check
** Description: checks if stack is empty
** Parameters: none
** Pre-Conditions: stack must exist
** Post-Conditions: bool of emptyness is returned
*******************************************************************/
bool Stack::check(){
	if(head == NULL){
		return true;
	}
	else{
		return false;
	}
}



#endif
