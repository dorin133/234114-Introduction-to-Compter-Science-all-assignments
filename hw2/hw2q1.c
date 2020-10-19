#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/
#define MIN_4_DRAG1 4
#define MAX_6_DRAG3 6
#define DIVIDE_BY 5
#define FORBIDDEN_LETTER 's'
#define FLAG '!'


/*=========================================================================
  the main function: prints the required message for the user regarding the inpt he must give.
  then,scans each letter from the enemy's name in a do...while loop
  (because for the first letter there is no pervious one and function "ola_sequence"
  will fail). for every letter runs the opertion neccesary for each condition check
  for the dragon as described in the guideline (length, sum of ascii, ola sequence
  and the apearance of 's'). eventually, "dragon_choice" and "max_dragon" will 
  return the main function the value of the selected drgon.
  the message "Khalisi sent dragon.... into the battle!!! 
  will be printed according to that.
==========================================================================*/


// the progrm compares two adjacent chars in the enemy name.returns 1- a>b or 0- a<b
bool ola(char a, char b) {
bool dragB_ola = (a>b);
return dragB_ola;
}
//checks division in 5 for the sum of letters in ascii. 0- not divided, 1-divided 
int sum_ascii_to_5(int sum) {
	bool dragA_5;
	dragA_5 = (sum % DIVIDE_BY != 0);
	return dragA_5;
}
int max_dragon(int drag1, int drag2) {
	/*returns the dragon out of the two of which his value from 
	function "dragon_choice" is the greatest*/
	return drag1 * (drag1 > drag2) + drag2 * (drag2 > drag1);
}
/*the program runs for each dragon all of his criterias.
	in addition, drag c is multiplied by 3 and drag b is multiplied by 2 because
	if more than 1 dragon answers his criterias, the dragon to evntually be chosen is
	the one with the biggest alphabetic order.*/
int dragon_choice(int length, int count_not_s, int ola_sequence, int sum_ascii) {
	int dragA, dragB, dragC = 0;
	dragA = (length > MIN_4_DRAG1) || (sum_ascii_to_5(sum_ascii));
	dragB = (ola_sequence == length)*2;
	dragC = ((length < MAX_6_DRAG3) && (count_not_s == length))*3;
	return max_dragon(max_dragon(dragA, dragB), dragC);
}
int print_enter_enemy_name() {
	return printf("Please enter enemy name:\n");
}

int print_dragonA_sent() {
	return printf("\nKhalisi sent dragonA into the battle!!!\n");
}

int print_dragonB_sent() {
	return printf("\nKhalisi sent dragonB into the battle!!!\n");
}

int print_dragonC_sent() {
	return printf("\nKhalisi sent dragonC into the battle!!!\n");
}

int print_no_dragon_sent() {
	return printf("\nNO Dragon has been sent into the battle!!!\n");
}
int main()
{
	char letter, last_letter; 
	int choice; int sum_ascii = 0; int length = 0; int ola_sequence = 1; int count_not_s = 0;
	print_enter_enemy_name();
		scanf(" %c", &letter);
		last_letter = letter;
		do
		{
			sum_ascii += letter;
			length++;
			ola_sequence += ola(letter, last_letter);
			count_not_s += (letter != FORBIDDEN_LETTER);
			last_letter = letter;
		} while (scanf(" %c", &letter) == 1 && letter != FLAG);
        choice= dragon_choice(length, count_not_s, ola_sequence, sum_ascii);
		return ((choice == 3) && print_dragonC_sent()) || ((choice == 2) && print_dragonB_sent()) || ((choice == 1) && print_dragonA_sent())
			|| ((choice==0) && print_no_dragon_sent());
}