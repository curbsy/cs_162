/***************************************************************************************************************************
 ** Program Filename: war.cpp
 ** Author: Makenzie Brian
 ** Date: October 9, 2015
 ** Description: Plays a version of war with random numbers
 ** Input: int rounds (number of rounds to play)
 ** Output: winner of the game and number of victories for each player
 **************************************************************************************************************************/

#include<iostream>
#include<cstdlib>

using namespace std;

class player {
	public:
		int victories;
		int card;
		int random();
		player();                   /* constructor */
	private:
};


/*************************************************************************************************************************
 ** Function: player
 ** Description: constructor that initializes victories to zero
 ** Parameters: None
 ** Pre-Conditions: variable victories must exist
 ** Post-Conditions: victories is initialized to zero
 ************************************************************************************************************************/
player::player() {
	victories = 0;
}


/**************************************************************************************************************************
 ** Function: random
 ** Description: gives a random number between 1 and 52
 ** Parameters: int card
 ** Pre-Conditions: variable must exist, must include proper library
 ** Post-Conditions: card contains a random number
 *************************************************************************************************************************/
int player::random() {
	card = rand() % 52 + 1;
	return card;
}


/************************************************************************************************************************
 ** Function: main
 ** Description: determines which number is higher and which player wins
 ** Parameters: None
 ** Pre-Conditions: variables and functions must be declared
 ** Post-Conditions: a winner is chosen and displayed
 ************************************************************************************************************************/
int main() {
	int rounds;
	player player_one;
	player player_two;
	int card_one = 0;
	int card_two = 0;

	cout << "How many rounds would you like to play?" << endl;
	cin >> rounds;

	for( int i=0; i<rounds; i++) {
		card_one = player_one.random();
		card_two = player_two.random();
		
		//cout << "card1: " << card_one << endl;
		//cout << "card2: " << card_two << endl;

		if( card_one > card_two) {
			player_one.victories++;
		}
		else if( card_one < card_two) {
			player_two.victories++;
		}
	}

	cout << "Player 1 had " << player_one.victories << " victories." << endl;
	cout << "Player 2 had " << player_two.victories << " victories." << endl;

	if( player_one.victories > player_two.victories) {
		cout << "The winner is Player 1!" << endl;
	}
	else if( player_one.victories < player_two.victories) {
		cout << "The winner is Player 2!" << endl;
	}
	else{
		cout << "The match was a tie." << endl;
	}

	return 0;
}

