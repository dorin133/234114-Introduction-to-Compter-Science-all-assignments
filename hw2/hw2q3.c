#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/
#define INVALID_INPUT 1
#define N 25


/*-------------------------------------------------------------------------
  The main program. (describe what your program does here):
  the main program scans the inputs of the user 
  (size, first matrix, second matrix and selcted operatio (+ or *).
  then, calls the fuction "which_operaion" to determine + or *, and runs 
  the calculations of the selected operation in functions
  "multiply_matrix" or adds the two indexs. this opertaion
  takes places inside 2 for loops to eventually recieve the value 
  for each of the rsult matrix's values.
  for invalid inputs- the program will print a message as required 
  in the guideline.
 -------------------------------------------------------------------------*/



void print_enter_matrix_size() {
	printf("Please enter the matrix size:\n");
}

void print_enter_first_matrix() {
	printf("Please enter the first matrix:\n");
}

void print_enter_second_matrix() {
	printf("Please enter the second matrix:\n");
}

void print_invalid_input() {
	printf("Invalid input.");
}

void print_enter_required_operation() {
	printf("Please enter the required operation:\n");
}

void print_number(int number) {
	printf("%d ", number);
}

void print_enter() {
	printf("\n");
}
//the program returns 1- '*' operaion or '+' operation 0- invalid opertaion.
bool valid_operation(char c) { 
	return (c == '*') || (c == '+');
}
//the program returns 1- '*' operaion or 0- '+' operation.
bool which_operation(char c) {
	return (c == '*');
}

/* returns the multipication value for a row in matrix1
	with a column from matrix2*/
long int multiply_matrix(int matrix1[N][N], int matrix2[N][N], int n, int i_row, int j_column)
{
    long int num_multiply = 0; int row; int column;
	for (int j = 0; j < n; j++)
	{
		row = matrix1[i_row][j];
		column = matrix2[j][j_column];
		num_multiply += column * row;
	}
	return num_multiply;
}
//inserts input to the two matrixes givn by the user
void scanf_matrixes(int matrix1[N][N], int matrix2[N][N], int n) {
	for (int k = 0; k < 2; k++) {
		if (k == 0)
			print_enter_first_matrix();
		else
			print_enter_second_matrix();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (k == 0) {
					if (scanf(" %d", &matrix1[i][j]) != 1) {
						print_invalid_input();
						exit(INVALID_INPUT);
					}
				}
				if (k == 1) {
					if (scanf(" %d", &matrix2[i][j]) != 1) {
						print_invalid_input();
							exit(INVALID_INPUT);
					}
				}
			}
		}
	}
}
		
	int scanf_size() {
	int n;
	print_enter_matrix_size();
	if (scanf (" %d", &n) != 1) {
		print_invalid_input();
		exit(INVALID_INPUT);
	}
	return n;
}
char scanf_operation() {
	char c;
	print_enter_required_operation();
	if (scanf(" %c", &c) != 1) {
		print_invalid_input();
		exit(INVALID_INPUT);
	}
	return c;
}

int main()
{
	int matrix1[N][N]; int matrix2[N][N]; long int result[N][N]; int n; char c;
	n = scanf_size();
	scanf_matrixes(matrix1,matrix2, n);
	c = scanf_operation();
	if (valid_operation(c))
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				result[i][j] = (which_operation(c)) * (multiply_matrix(matrix1,matrix2, n, i, j)) + (!which_operation(c)) * (matrix1[i][j] + matrix2[i][j]);
				print_number(result[i][j]);
			}
			print_enter();
		}
	}
	else 
		print_invalid_input();
	return 0;
}
