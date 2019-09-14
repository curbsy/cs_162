/*********************************************************************
** Program Filename: Item.hpp
** Author: Makenzie Brian
** Date: October 23, 2015
** Description:
** Input:
** Output:
*********************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
#include <iostream>

using namespace std;

class Item {
	private:
		string itemName;
		string unit;
		double unitPrice;
		int numberToBuy;
	public:
		Item();
		string getItemName();
		string getUnit();
		double getUnitPrice();
		int getNumberToBuy();
		void setItemName(string name);
		void setUnit(string unitType);
		void setUnitPrice(double price);
		void setNumberToBuy(int number);
		void printItem();
		void add(bool value);
};

/****************************************************************
** Function: Item
** Description: default constructor
** Parameters: none
** Pre-Conditions: variables must exist
** Post-Conditions: variables initialized to zero
****************************************************************/
Item::Item(){
	unitPrice = 0;
	numberToBuy = 0;
}



/****************************************************************
** Function: getItemName
** Description: accessor
** Parameters: none
** Pre-Conditions: must hold a value
** Post-Conditions: value will be passed
****************************************************************/
string Item::getItemName(){
	return itemName;
}


/****************************************************************
** Function: getUnit
** Description: accessor
** Parameters: none
** Pre-Conditions: must hold a value
** Post-Conditions: value will be passed
****************************************************************/
string Item::getUnit(){
	return unit;	
}


/****************************************************************
** Function: getUnitPrice
** Description: accessor
** Parameters: none
** Pre-Conditions: must hold a value
** Post-Conditions: value will be passed
****************************************************************/
double Item::getUnitPrice(){
	return unitPrice;
}



/****************************************************************
** Function: getNumberToBuy
** Description: accessor
** Parameters: none
** Pre-Conditions: must hold a value
** Post-Conditions: returns a value
****************************************************************/
int Item::getNumberToBuy(){
	return numberToBuy;
}



/****************************************************************
** Function: setItemName
** Description: mutator
** Parameters: string name
** Pre-Conditions: variable must exist
** Post-Conditions: variable will be set
****************************************************************/
void Item::setItemName(string name){
	itemName = name;
}



/****************************************************************
** Function: setUnit
** Description: mutator
** Parameters: string unitType
** Pre-Conditions: variable must exist
** Post-Conditions: variable will be set
****************************************************************/
void Item::setUnit(string unitType){
	unit = unitType;
}



/****************************************************************
** Function: setUnitPrice
** Description: mutator
** Parameters: double price
** Pre-Conditions: variable must exist
** Post-Conditions: variable will be set
****************************************************************/
void Item::setUnitPrice(double price){
	unitPrice = price;
}


/****************************************************************
** Function: setNumberToBuy
** Description: mutator
** Parameters: int number
** Pre-Conditions: variable must exist
** Post-Conditions: variable will be set
****************************************************************/
void Item::setNumberToBuy(int number){
	numberToBuy = number;
}



/****************************************************************
** Function: printItem
** Description: displays item info
** Parameters: none
** Pre-Conditions: variables must be set
** Post-Conditions: values will be displayed
****************************************************************/
void Item::printItem(){
	cout << "Name: " << itemName << endl;
	cout << "Unit: " << unit << endl;
	cout << "Unit Price: " << unitPrice << endl;
	cout << "Buying: " << numberToBuy << endl;
	cout << "Extended price: " << (numberToBuy * unitPrice) << endl;
}



/****************************************************************
** Function: add
** Description: part of adding item to list
** Parameters: bool value
** Pre-Conditions: variables must exist
** Post-Conditions: item values will be set or number will bbe changed
****************************************************************/
void Item::add(bool value){	
	if(value == 0){
		
		cout << "Enter unit" << endl;		
		cin >> unit;
		cout << "Enter unit price" << endl;
		cin >> unitPrice;
		cout << "Enter number to buy" << endl;
		cin >> numberToBuy;

	}
	else  if(value == 1){
		cout << "This item is already in the list. Please enter the new desired quantity" << endl;

	}	

}

#endif




