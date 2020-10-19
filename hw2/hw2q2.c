#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/



/*-------------------------------------------------------------------------
  The main program. (describe what your program does here):
  the program prints the requirments for the user's input as described
  in the guideline. later, scans the user's inputs (personal number of all soldiers 
  and the commanders demand).
  the program uses external function to sort the soldiers to platoons and
  fulfill all the possible reuirements of the commander.
  it uses switch...case to activate each function for the right demand (1-4) 
  and prints the necessary output.
 -------------------------------------------------------------------------*/


void print_warriors_details() {
	printf("Enter warriors id and demand at the end:\n\n");
}

void print_army_size(int size) {
	printf("The army size is: %d\n", size);
}

void print_biggest_platoon_and_size(int index, int size) {
	printf("The biggest platoon index is: %d and its size is: %d\n", index, size);
}

void print_active_platoons_and_avg(int size, double avg) {
	printf("There are %d active platoons \n\nThe avg size of a platoon is: %.2f\n", size, avg);
}

void print_show_army() {
	printf("Show army!\n\n");
}

void print_number(int num) {
	printf("%d", num);
}

void print_enter() {
	printf("\n");
}

void print_star() {
	printf("*");
}

void print_space() {
	printf(" ");
}
//returns the biggest platoon's index.
int index_biggest_platoon(int platoons[10]) { 	
	int max = platoons[0]; int index=0;
	for (int i = 1; i < 10; i++)
	{
		max = platoons[i] * (platoons[i] >= max) + max * (platoons[i] < max);
		index = i * (platoons[i] == max) + index * (platoons[i] != max);
	}
	return index;
}
//returns the biggest platoon's size.
int size_biggest_platoon(int platoons[10]) {
	int max = platoons[0]; int index=0;
	for (int i = 1; i < 10; i++) {
		max = platoons[i] * (platoons[i] >= max) + max * (platoons[i] < max);
		index = i * (platoons[i] == max) + index * (platoons[i] != max);
	}
	return max;
}
//returns the amount of active platoons (more than 1 soldier).
int active_platoons(int platoons[10]) {
	int active_num = 0;
	for (int i = 0; i < 10; i++)
	{
		active_num += (platoons[i] >= 1);
	}
	return active_num;
}
//returns the size of th army (all platoons combined)
int army_size(int platoons[10]) {
	int size = 0;
	for (int i = 0; i < 10; i++)
	{
		size += platoons[i];
	}
	return size;
}
//return the average size of all active platoons (in double).
double avg_platoons(int platoons[10]) {
	return (double)army_size(platoons) / (double)active_platoons(platoons);
}
//prints the asterisks for the program as described in the guideline.
void print_line_of_asterisks(int platoons[10]) {
	while (active_platoons(platoons) != 0)
	{
		for (int i = 0; i < 10; i++)
		{
			if (platoons[i] >= 1) {
				print_star();
				--platoons[i];
			}
			else
				print_space();
		}
		print_enter();
	}
}
void print_platoons() {
	printf("0123456789");
	print_enter();
}
//sorts every soldier to the right platoon.
void sort_soldier(int platoons[10], int soldier_num) {
    int sum_digits=0;
	while (soldier_num > 0) {
		sum_digits += soldier_num % 10;
		soldier_num /= 10;
    }
	platoons[sum_digits % 10] += 1;
}
int main()
{
	int soldier_num, demand; int platoons[10] = { 0 };
	print_warriors_details();
	while (scanf(" %d", &soldier_num)==1 && soldier_num>99) {
		sort_soldier(platoons, soldier_num);
	}
	demand = soldier_num;
	switch (demand)
	{
	case 1: print_army_size(army_size(platoons)); break;
	case 2: print_biggest_platoon_and_size(index_biggest_platoon(platoons), size_biggest_platoon(platoons)); break;
	case 3: print_active_platoons_and_avg(active_platoons(platoons), avg_platoons(platoons)); break;
	case 4:print_show_army();
		   print_platoons();
		   print_line_of_asterisks(platoons); break;
	}
	return 0;
}