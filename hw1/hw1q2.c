#include <stdio.h>

int main()
{
	int valid_check, i , count = 0;
	int check=0;
	unsigned int oppisite_num = 0;
	unsigned long int num;
	unsigned long int temp;
	unsigned char c;
	printf("Enter an encoded word and I'll do my best:\n");
	valid_check= scanf(" %lu" ,&num);
	if (!valid_check)
	{
		printf("\nThere is nothing there :(");
		return 0;
	}
	temp = num;
	while (temp != 0) //calculating the length of the number 
	{
		temp = temp / 10;
		count = count + 1;
	}
	for (i = 0; i < count; i++) //creating a reverse number for the user's input number (without the zeros at the end)
	{
		temp = num % 10;
		oppisite_num = oppisite_num * 10 + temp;
		num = num / 10;
	}
	check = 0;
	while (oppisite_num > 96)
	{
		if (((oppisite_num % 1000) < 123 && (oppisite_num % 1000) > 99) || oppisite_num % 100 > 96)
		{
			if (check == 0)
				printf("The decoded word is: ");
			check++;
			if (oppisite_num % 100 > 96)
			{
				c = oppisite_num % 100;
				if (c % 2 == 0)
					printf("%c", (c - 32));
				else
					printf("%c", c); 
				oppisite_num = oppisite_num / 100;
			}
			else
			{
				c = oppisite_num % 1000;
				if (c % 2 == 0)
					printf("%c", (c - 32));
				else
					printf("%c", c);
				oppisite_num = oppisite_num / 1000;
			}
		}
		else 
			oppisite_num = oppisite_num / 10;
	}
	
	if (check == 0)
		printf("\nThere is nothing there :(");
	else
		printf("\nDone and even had time for coffee :)");
	return 0;
}