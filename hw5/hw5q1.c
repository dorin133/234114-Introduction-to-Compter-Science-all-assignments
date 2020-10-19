#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void PrintWellcomeMessage()
{
	printf("Please enter a number:\n");
}

void PrintIsPalindrome()
{
	printf("It's a palindrome!");
}
void PrintIsNotPalindrome()
{
	printf("It's not a palindrome!");
}
int length(int polindrom) {
	int count = 0;
	while (polindrom !=0) {
		polindrom /= 10;
		count++;
	}
	return count;
}

int power(int count) {
	int pow = 1;
	for (int i = 0; i < count; i++)
	{
		pow *= 10;
	}
	return pow;
}

bool if_polindrom(int polindrom) {
	int num1, num2; int count = 0; int count_zero = 1;
	if (count == length(polindrom) / 2 || count == (length(polindrom) - 1) / 2)
		return true;
	while ((polindrom/power(count_zero) % 10 == 0 && (polindrom / power(length(polindrom) -count_zero-1)) % power(count_zero) == 0)) {
		count_zero++;
	}
	num1 = polindrom / power(length(polindrom)-1);
	num2 = polindrom % 10;
	if (num1 == num2) {
		count++;
		if (count_zero>1) 
			return if_polindrom((polindrom % power(length(polindrom)- count_zero)) / power(count_zero));
		return if_polindrom((polindrom % power(length(polindrom)-1)) / 10);
	}
	else
		return false;
}
int main() {
	int poli=0;
	PrintWellcomeMessage();
	scanf("%d", &poli);
	if (if_polindrom(poli) == true)
		PrintIsPalindrome();
	else
		PrintIsNotPalindrome();
}