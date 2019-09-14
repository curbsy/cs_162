/*******************************************************************
** Program Filename: ShoppingCartMain.cpp
** Author: Makenzie Brian
** Date: October 23, 2015
** Description: main function for Item.hpp and List.hpp
** Input:
** Output:
*******************************************************************/


#include "Item.hpp"
#include "List.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
	List elListo;
	int x;

	while(1){
		cout << "(1)Add an item. (2)Remove an item. (3)Print list.";
		cout << "(4)Exit." << endl;
		cin >> x;

		if(x == 1){
			elListo.addItem();
		}
		else if(x == 2){
			string nombre;
			elListo.removeItem(nombre);
		}
		else if(x == 3){
			elListo.printList();
		}
		else if(x == 4){
			break;
		}
	}

	return 0;
}
