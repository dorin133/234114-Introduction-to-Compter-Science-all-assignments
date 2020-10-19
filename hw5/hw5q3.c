#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void PrintLength()
{
	printf("Please enter length:\n");
}

void PrintArray()
{
	printf("Please enter array:\n");
}

void PrintSum()
{
	printf("Please enter sum:\n");
}

void PrintExist()
{
	printf("Such elements do exist.");
}

void PrintDoNotExist()
{
	printf("Such elements do not exist.");
}


void swap(int* num1, int* num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

bool sort_and_solve(int a[], int length, int sum) {
	int max = 0; int index = 0; 
	int right_pointer = length - 1;
	int left_pointer = 0;
	if (left_pointer == right_pointer)
		return false;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if (a[j] > max) {
				max = a[j];
				index = j;
			}
			swap(&a[length - i - 1], &a[index]);
		}
	}
	while (right_pointer!=1) {
		for (int i = left_pointer+1; i < right_pointer; i++)
		{
			if (a[i] + a[left_pointer] + a[right_pointer] == sum) 
				return true;
			if (a[i] + a[left_pointer] + a[right_pointer] > sum)
				break;
		}
		if (right_pointer - left_pointer > 1 || a[left_pointer+1] + a[right_pointer] < sum) {
			left_pointer++;
		}
		else {
			left_pointer = 0;
			right_pointer--;
		}

	}
		return false;
}

int main() {
	int sum = 0; int length = 0; 
	PrintLength();
	scanf(" %d", &length);
	int *a = malloc(length * sizeof(int));
	PrintArray();
	for (int i = 0; i < length; i++)
	{
		scanf(" %d", &a[i]);
	}
	PrintSum();
	scanf(" %d", &sum);
	if (sort_and_solve(a, length, sum)==true)
		PrintExist();
	else
		PrintDoNotExist();
}