
#include <stdio.h>
int main()
{
	char check;
	char num1;
	int num_check = 0;
	int sum_digits = 0;
	int stop = 0;
	printf("Please enter the letter C for calculating CheckDigit and the letter V for validating an ID by its CheckDigit:\n");
	scanf(" %c", &check);
	if (check == 'C' || check == 'V')
	{
		if (check == 'C')
		{
			printf("\nCalculating CheckDigit, please enter 8 digits:\n");
			for (int i = 1; i < 9; i++)
			{
				if (scanf(" %c", &num1) == 1 && num1 >= '0' && num1 <= '9')
				{
					if (i % 2 == 0 && (num1 - '0') * 2 > 9)
						sum_digits = sum_digits + 1 + ((num1 - '0') * 2) % 10;

					if (i % 2 == 0 && (num1 - '0') * 2 < 9)
						sum_digits = sum_digits + (num1 - '0') * 2;

					if (i % 2 == 1)
						sum_digits = sum_digits + (num1 - '0');
				}
				else
				{
					printf("\nERROR"); stop = 1;
				}
			}
			if (stop != 1)
			{
				num_check = (10 - (sum_digits % 10)) % 10;
				printf("\nCheckDigit = %d", num_check);
			}
		}
		if (check == 'V')
		{
			printf("\nValidating ID, please enter 9 digits ID:\n");
			for (int i = 1; i < 10; i++)
			{
				if (scanf(" %c", &num1)== 1 && num1 >= '0' && num1 <= '9')
				{
					if (i % 2 == 0 && (num1 - '0') * 2 > 9)
						sum_digits = sum_digits + 1 + ((num1 - '0') * 2) % 10;

					if (i % 2 == 0 && (num1 - '0') * 2 < 9)
						sum_digits = sum_digits + (num1 - '0') * 2;

					if (i % 2 == 1 && i != 9)
						sum_digits = sum_digits + (num1 - '0');

					if (i == 9)
					{
						num_check = num1 - '0';
					}
				}
				else
				{
					printf("\nERROR"); stop = 1;
				}
			}
			if (stop != 1)
			{
				printf("\nYou have entered CheckDigit = %d", num_check);
				printf("\nCalculated CheckDigit = %d\n", (10 - (sum_digits % 10)) % 10);
				if (num_check == (10 - (sum_digits % 10)) % 10)
					printf("\nLegal ID :)");
				else
					printf("\nIlegal ID :(");
			}
		}
	}
	else
		printf("\nERROR");
	return 0;
}
