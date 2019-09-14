/*********************************************************************
** Program Filename: List.hpp
** Author: Makenzie Brian
** Date: October 23, 2015
** Description: Shopping list for Item.hpp objects
** Input: Items, names
** Output: a list of items
*********************************************************************/

#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include <string.h>

using namespace std;

class List {
	public:
		List();
		void addItem();
		void removeItem(string name);
		void printList();
		bool searchList();
		~List();


	private:
		int size;
		Item *list;
		int capacity;
};


List::List(){
	list = new Item[10];
	capacity = 10;
	size = 0;
}


/*******************************************************************
** Function: searchList
** Description: searches through the list and assigns name to new item if not already in list
** Parameters: none
** Pre-Conditions: items must be in array
** Post-Conditions: returns value of bool, name is assigned if needed
*******************************************************************/
bool List::searchList(){
	bool value;
	string n;
	cout << "Enter name of item" << endl;
	cin >> n;
	for(int i=0; i<size; i++) {
		if(list[i].getItemName().compare(n) != 0) {
			value = 0;
		}
		else{
			value = 1;
			break;
		}
	}
	if(value == 0){
			list[size].setItemName(n);
	}
	return value;
}


/*******************************************************************
** Function: addItem
** Description: adds item to list, adds more memory if needed
** Parameters: none
** Pre-Conditions: array must exist
** Post-Conditions: item is added or amount is changed
*******************************************************************/
void List::addItem(){
	if(size == capacity){
		Item *temp;
		temp = new Item[capacity +10];
		for(int j=0; j<capacity; j++) {
			temp[j] = list[j];
 			
		}
		capacity += 10;
		delete list; 
		list = temp;
	}
	bool value = searchList();

	list[size].add(value);
	if(value == 1){
		int tempo;
		cin >> tempo;
		list[size].setNumberToBuy(tempo);
	}
	size += 1;
	
}


/*******************************************************************
** Function: removeItem
** Description: removes item from array
** Parameters: string name
** Pre-Conditions: array, and items must exist
** Post-Conditions: item is removed if it is in the array
*******************************************************************/
void List::removeItem(string name){
	bool thing;
	int temp;
	cout << "Enter a name" << endl;
	cin >> name;
	for(int j=0; j<size; j++) {
		if(list[j].getItemName().compare(name) == 0){
			thing = 0;
			//cout << "thing = " << thing << endl;
			temp = j;
			break;
		}
		else{
			thing = 1;
			//cout << "thing =" << thing << endl;

		}
	}	
	if(thing ==0){	
		for(int k=temp; k<size-1; k++){
			list[k] = list[k+1];
			//cout << "attempting to remove" << endl;
			}
		
		size -= 1;
		}
	else if(thing == 1){
			cout << "There is no item with that name." << endl;
	}
	
}


/*******************************************************************
** Function: printList
** Description: displays all items and info from list
** Parameters: none
** Pre-Conditions: items and list must exist
** Post-Conditions: displays info and total
*******************************************************************/
void List::printList(){
	double total;
	for(int i=0; i<size; i++){
		list[i].printItem();
		total += (list[i].getUnitPrice() * list[i].getNumberToBuy());
	}
	cout << "Total is " << total << endl;
}


List::~List(){
	delete [] list;
}

#endif
