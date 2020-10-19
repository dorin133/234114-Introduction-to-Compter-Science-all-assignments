#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXIMAL_AIRLINES 10
#define DEST 6
#define DIM 2
#define VLD_INPUT 1
#define INVLD_INPUT 0
#define STOP 0


char* destinations[] = { "Miami", "Rio", "Moscow", "Shanghai", "Barcelona", "Melbourne" };

int fillPricesTable(double flightsPrices[][DEST], int n, double* dollarRate);

void compute(double flightsPrices[][DEST], int length,
	double* max, double* min, int* bestAirLine);

void bestPrice(double flightsPrices[][DEST], int length,
	double bestPrices[DEST][DIM], double dollarRate);

void printBestPrices(double bestPrices[DEST][DIM]);

void printMinMaxAvg(double max, double min, int bestAirLine);

void errorPrice(int row);

void errorDollar();


int main()
{
	int num_of_airlines = 0, bestAirLine = 0;
	double prices[MAXIMAL_AIRLINES][DEST];
	double max = 0, min = 0, dollarRate = 0;
	double bestPrices[DEST][DIM];

	num_of_airlines = fillPricesTable(prices, MAXIMAL_AIRLINES, &dollarRate);
	compute(prices, num_of_airlines, &max, &min, &bestAirLine);
	bestPrice(prices, num_of_airlines, bestPrices, dollarRate);


	return 0;
}




void printBestPrices(double bestPrices[DEST][DIM]) {
	for (int i = 0; i < DEST; i++) {
		printf("Best offer for %s is ", destinations[i]);
		printf("Airline # %d price: %.2f shekels\n", (int)(bestPrices[i][0]), bestPrices[i][1]);
	}
}

void printMinMaxAvg(double max, double min, int bestAirLine) {
	printf("Maximal price: %.2f\nMinimal price: %.2f\nBest Airline: %d\n", max, min, bestAirLine);

}

void errorPrice(int row) {
	printf("ERROR: invalid price in airline # %d\n", row);
}

void errorDollar() {
	printf("ERROR: invalid dollar rate, try again!\n");
}

double valid_dollar(double* dollarRate) {
	bool check;
	check = scanf(" %lf", dollarRate);
	while (*dollarRate <= 0 || check == INVLD_INPUT) {
		errorDollar();
		check = scanf(" %lf", dollarRate);
	}
	return *dollarRate;
}

bool valid_price(int row, int col, double flightsPrices[][DEST], double price) {
	if (price <= 0) {
		errorPrice(row);
		return INVLD_INPUT;
	}
	else {
		flightsPrices[row][col] = price;
		return VLD_INPUT;
	}	
}

int fillPricesTable(double flightsPrices[][DEST], int n, double* dollarRate) {
	double price; int length=0;
	valid_dollar(dollarRate);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < DEST; j++) {
			if (scanf(" %lf", &price) != EOF) {
				if (valid_price(i, j, flightsPrices, price) == INVLD_INPUT)
					exit(INVLD_INPUT);
				length = i + 1;
			}
			else
				return length;
		}
	}
	return length;
}

void compute(double flightsPrices[][DEST], int length,
	double* max, double* min, int* bestAirLine) {
	int sum = 0; int temp_sum = 0;
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < DEST; j++) {
				if (i == 0 && j == 0) //set min
					*min = flightsPrices[0][0];
				if (*max < flightsPrices[i][j])
					*max = flightsPrices[i][j];
				if (*min > flightsPrices[i][j])
					*min = flightsPrices[i][j];
				temp_sum += flightsPrices[i][j];
			}
			if (i == 0) //set min sum
				sum = temp_sum;
			if (temp_sum < sum) {
				sum = temp_sum;
				*bestAirLine = i;
			}
			temp_sum = 0;
		}
		printMinMaxAvg(*max, *min, *bestAirLine);
}

void bestPrice(double flightsPrices[][DEST], int length,
	double bestPrices[DEST][DIM], double dollarRate) {
	double min=0; int min_i = 0;
		for (int j = 0; j < DEST; j++) {
			for (int i = 0; i < length; i++) {
				if (i == 0) { //set min for every internal loop iteration
					min = flightsPrices[0][j];
					min_i = i;
				}

				if (min > flightsPrices[i][j]) {
					min = flightsPrices[i][j];
					min_i = i;
				}
			}
					bestPrices[j][1] = min * dollarRate;
					bestPrices[j][0] = min_i;
		}
		printBestPrices(bestPrices);
}

