/**********************************************************************************************************************
 ** Program Filename: matrix.cpp
 ** Author: Makenzie Brian
 ** Date: October 9, 2015
 ** Description: uses matix multplication on a 2x3 and a 3x2 matrix to make a 2x2 matrix
 ** Input: 6 doubles for each matrix
 ** Output: 4 doubles in a matrix
 *********************************************************************************************************************/


#include <iostream>

using namespace std;


/*********************************************************************************************************************
 ** Function: matrix_mult
 ** Description: Multiplies a 2x3 and a 3x2 matrix (row by column)
 ** Parameters: 3 arrays of doubles of size 2x3, 3x2, and 2x2
 ** Pre-Conditions: matricies 1 and 2 must have values assigned
 ** Post-Conditions: matrix_out will be the multiplication of the two matricies
 *********************************************************************************************************************/
void matrix_mult( double matrix_one[2][3], double matrix_two[3][2], double matrix_out[2][2] ) {
	/*rows and columns that must match are described below*/

	for( int p=0; p<2; p++) {                               /*defines rows for matrix_out and rows for matrix_one*/
		for( int m=0; m<2; m++) {                       /*defines columns for matrix_out and columns for matrix_two*/
			for( int n=0; n<3; n++) {               /*defines columns for matrix_one and rows for matrix_two*/
					matrix_out[p][m] += matrix_one[p][n] * matrix_two[n][m];
			}
		}
	}

}


/*******************************************************************************************************************
 ** Function: main.cpp
 ** Description: This is the main function it will take inputs and print outouts for the matrix_mult function
 ** Parameters: None
 ** Pre-Conditions: functions, arrays, and variables must exist
 ** Post-Conditions: arrays will be multiplied as matricies and all matricies will be displayed
 ******************************************************************************************************************/
int main() {
	double array_one[2][3];
	double array_two[3][2];	
	double array_out[2][2];

	cout << "Please enter 6 numbers for matrix 1." << endl;

	for( int i=0; i<2; i++) {
		for( int j=0; j<3; j++) {
		cin >> array_one[i][j];
		}
	}

	cout << "Please enter 6 numbers for matrix 2." << endl;

	for( int k=0; k<3; k++) {
		for( int l=0; l<2; l++) {
		cin >> array_two[k][l];
		}
	}

	matrix_mult( array_one, array_two, array_out );
	
	cout << "Matrix 1 was: { "; 
	for( int q=0; q<2; q++) {
		cout << "{ ";
		for( int j=0; j<3; j++) {
			cout << "{" << array_one[q][j] << "}";
		}
		cout << " }";
	}
	cout << " }" << endl;


	cout << "Matrix 2 was: { ";
	for( int i=0; i<3; i++) {
		cout << "{ ";
		for( int j=0; j<2; j++) {
			cout << "{" << array_two[i][j] << "}";
		}
		cout << " }";
	}
	cout << " }" << endl;


	cout << "The matrix product was: { ";
	for( int i=0; i<2; i++) {
		cout << "{ ";
		for( int j=0; j<2; j++) {
			cout << "{" << array_out[i][j] << "}";
		}
		cout << " }";
	}
	cout << " }" << endl;



	return 0;	
}
