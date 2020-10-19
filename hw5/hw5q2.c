#include <stdio.h>
#include <stdlib.h>

#define N 4
#define INDEX_min 1

void PrintWelcomeMessage()
{
	printf("Please enter road matrix:\n");
}

void PrintSourceCityMessage()
{
	printf("Please enter source city:\n");
}

void PrintDestinationCityMessage()
{
	printf("Please enter destination city:\n");
}

void PrintSpace()
{
	printf(" ");
}

void PrintNumber(int num)
{
	printf("%d", num);
}

int shortest_road_in_row(int roads[N][N], int row) {
	int min = 0;
	for (int j = 0; j < N; j++) {
		if (j == row || roads[row][j]==-1)
			continue;
		if (min == 0)
			min = roads[row][j];
		if (roads[row][j] < min) {
			min = roads[row][j];
		}
	}
	return min;
}


int shortest_path(int roads[N][N], int source, int dest, int path1[], int source_cpy, int dest_cpy)
{
	if (dest == source) 
		return -1;
	if (roads[source][dest]>roads[source_cpy][dest_cpy] && roads[source_cpy][dest_cpy]>0)
	{
		else {
			path1[dest_cpy] = roads[source_cpy][dest_cpy];
			shortest_path(roads, source, dest, path1, dest_cpy, 0);
		}
	}
	else {
		if (dest_cpy < N)
			shortest_path(roads, source, dest, path1, source_cpy, dest_cpy + 1);
		else
			return 0;
	}
	
	int* path2 = (int*)malloc(N * sizeof(int));


}
int shortest_path(int roads[N][N], int source, int dest, int helper[N-1][N]) {
	int helper[N - 1][N - 1];
	int count = 0;
	int min = roads[source][dest];
	if (source == dest)
		return helper;
	for (int i = 0; i < N; i++) {
		if (roads[source][i] == 0 || roads[source][i] == -1) {
			continue;
		}
		for (int j = 0; j < N-1; j++) {
			roads[j][source] = 0;
		}

		int res = shortest_path(roads, i, dest, helper[][i]) +roads[source][i];
	}
}