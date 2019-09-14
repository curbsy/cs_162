/****************************************************************************************************************
 ** Program Filename: buttercup.cpp
 ** Author: Makenzie Brian
 ** Date: October 9, 2015
 ** Description: chooses the champion from n suitors by eliminating every third suitor
 ** Input: Number of suitors
 ** Output: Position of champion
 ***************************************************************************************************************/
#include<iostream>
#include<vector>

using namespace std;


/***************************************************************************************************************
 ** Function: determine
 ** Description: determines which suitor will win out of n suitors
 ** Parameters: int people
 ** Pre-Conditions: number of people must be passed
 ** Post-Conditions: a champion will be selected
 ***************************************************************************************************************/
int determine( int people) {
	int champion;
	int i = 2;
	vector<int> elVectoro;
	
	for(int j=1; j<=people; j++) {
		elVectoro.push_back(j);
	}

	while(elVectoro.size() > 1) {
		cout << i << endl;
		elVectoro.erase(elVectoro.begin() + i);
		i = (i + 2) % elVectoro.size();               /*if position is farther than size, returns to beginning*/
	}

	champion = elVectoro.at(0);

	return champion;	
}


/***************************************************************************************************************
 ** Function: main
 ** Description: Takes in number of suitors, gives winner
 ** Parameters: None
 ** Pre-Conditions: Function must be declared
 ** Post-Conditions: The winner is given
 ***************************************************************************************************************/
int main() {
	int suitors;
	int winner;

	cout << "How many suitors are there?" << endl;
	cin >> suitors;

	winner  = determine( suitors);

	cout << "The winner is suitor number " << winner << endl;

	return 0;
}

