#include <stdio.h>
#include <stdbool.h>

/*-------------------------------------------------------------------------
	Constants and definitions:
-------------------------------------------------------------------------*/
#define N 11
#define INVLD_INPUT 1
#define VLD_INPUT 0
#define X 'X'
#define O 'O'
#define EMPTY '_'

/*-------------------------------------------------------------------------
	Function declaration
-------------------------------------------------------------------------*/
void print_welcome();
void print_enter_board_size();
void print_board(char board[N][N], int n);
void print_player_turn(int player_index);
void print_error();
void print_winner(int player_index);
void print_tie();
void set_board(char board[N][N], int n);
bool valid_move(char board[N][N], int moves_indx, int input1, int input2, int n);
void determine_player_turn(int moves_indx);
void make_a_move(char board[N][N], int moves_i_j[N * N][2], int moves_indx, int input_i, int input_j, int n);
void make_an_undo(char board[N][N], int moves_i_j[N * N][2], int moves_indx, int input_i, int n);
int check_identical(int row_col[N], char symbol);
bool check_row_col(char board[N][N], int n, char symbol);
bool check_if_lost(char board[N][N], int n, int moves_indx);
bool check_if_tie(char board[N][N], int n);
int start_and_scan_size();
int make_valid_turn(char board[N][N], int moves_i_j[N * N][2], int moves_indx, int n);

/*-------------------------------------------------------------------------
	Implementation
-------------------------------------------------------------------------*/

//print welcome message
//1 lines
void print_welcome()
{
	printf("*** Welcome to AVOIDANCE TIC-TAC-TOE game ***\n\n");
}

//print message to enter board size
//1 lines
void print_enter_board_size()
{
	printf("Please enter board size (1 to %d):\n", N);
}

//print the board
//7 lines
void print_board(char board[N][N], int n)
{
	printf("\nCurrent board:\n");
	for (int i = 0; i < n; i++)
	{
		printf("|");
		for (int j = 0; j < n; j++)
		{
			printf("%c|", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//print a request for player with index "player_index" to move
//1 lines
void print_player_turn(int player_index)
{
	printf("\nPlayer ** %d **, enter next move:\n", player_index);
}

//print error message
//1 lines
void print_error()
{
	printf("Illegal move!!!, please try again:\n");
}

//print the winner
//1 lines
void print_winner(int player_index)
{
	printf("Player %d Wins! Hooray!\n", player_index);
}

//print message to announce there is a tie (no one wins)
//1 lines
void print_tie()
{
	printf("It's a tie!\n");
}
//set the board to empty ( '_' )
//8 lines
void set_board(char board[N][N], int n) {
	printf("\nCurrent board:\n"); 
	for (int i = 0; i < n; i++) {
		printf("|");
		for (int j = 0; j < n; j++)
		{
			board[i][j] = EMPTY;
			printf("%c|", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
//verify the input of a player's move is valid. 1-invalid 0-valid. 
//10 lines.
bool valid_move(char board[N][N], int moves_indx, int input1, int input2, int n) {
	bool check = INVLD_INPUT;
	if (input1 <= 0) { //verification for undo
		if ((0 - input1) > moves_indx || (0 - input1) % 2 != 1 || input1 == 0) 
			print_error();
		else
			check = VLD_INPUT;
	}
	if (input1 > 0) { //verification for a regular move
		if (input1 > n || input2 > n || board[input1 - 1][input2 - 1] == X || board[input1 - 1][input2 - 1] == O)
			print_error();
		else
			check = VLD_INPUT;
	}
	return check;
}
//print message for the right player to make a move.
//3 lines.
void determine_player_turn(int moves_indx) {
	if (moves_indx % 2 == 0)
		print_player_turn(1);
	else
		print_player_turn(2);
}
//add X or O to board according to the user's input of cordinators.
//6 lines.
void make_a_move(char board[N][N], int moves_i_j[N * N][2], int moves_indx, int input_i, int input_j, int n) {
	moves_i_j[moves_indx][0] = input_i;
	moves_i_j[moves_indx][1] = input_j;
	if (moves_indx % 2 == 0)
		board[input_i -1][input_j -1] = X;
	else
		board[input_i -1][input_j -1] = O;
	print_board(board, n);
}
//make an undo move.
//6 lines.
void make_an_undo(char board[N][N], int moves_i_j[N * N][2], int moves_indx, int input_i, int n) {
	int undo = input_i;
	for (int k = (0 - undo); k >= 0; k--)
	{
		board[moves_i_j[moves_indx-k][0]-1][moves_i_j[moves_indx - k][1]-1] = EMPTY;
		moves_i_j[moves_indx - k][0] = 0;
		moves_i_j[moves_indx - k][1] = 0;
	}
	print_board(board, n);
}
//check if all row is the same symbol (X or O)
//4 lines
int check_identical(int row_col[N], char symbol) {
	int index = 0;
	while (row_col[index] == symbol) {
		index++;
	}
	return index;
}
//return 1 if the current player lost in a row or a column order. else, return 0.
//10 lines.
bool check_row_col(char board[N][N], int n, char symbol) {
	bool lost = 0; int row[N]; int col[N]; int index = 0;
	while (index < n) {
		for (int j = 0; j < n; j++) {
			row[j] = board[index][j];
			col[j] = board[j][index];
		}
		if (check_identical(row, symbol) == n || check_identical(col, symbol) == n)
			lost = 1;
		index++;
	}
	return (lost);
}
//return 1 if the current player lost in a sub or main diagonal order. else, return 0.
//8 lines.
bool check_diagonals(char board[N][N], int n, char symbol) {
	int count_main_diag = 0; int count_sub_diag = 0; int size = n-1;
	for (int i = 0; i < n-1; i++) {
		if (board[i][i] == board[i + 1][i + 1] && board[i][i] == symbol)
			count_main_diag++;
		if (board[size][i] == board[size-1][i+1] && board[i][size] == symbol)
			count_sub_diag++;
		size--;
	}
	return (count_sub_diag == n - 1 || count_main_diag == n - 1);
}
//return 1 if the current player made a move that made him lose the game. else, return 0.
//2 lines.
bool check_if_lost(char board[N][N], int n, int moves_indx) {
	char symbol = (moves_indx % 2 == 1) ? X : O;
	return (check_row_col(board, n, symbol) || check_diagonals(board, n, symbol));
}
//return 1 if the current player made a move that made the game a tie. else, return 0
//6 lines
bool check_if_tie(char board[N][N], int n) {
	int count_empty_sqr = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == EMPTY)
				count_empty_sqr++;
		}
	}
	return (count_empty_sqr == 0);
}
int start_and_scan_size() {
	int n;
	print_welcome();
	print_enter_board_size();
	scanf(" %d", &n);
	return n;
}
//recieve inputs from user until valid. make a player's turn (regular or undo). return index of the next move.
//12 lines.
int make_valid_turn(char board[N][N], int moves_i_j[N * N][2], int moves_indx, int n) {
	int input_i = 0; int input_j = 0;
	determine_player_turn(moves_indx);
	do {
		scanf(" %d", &input_i);
		if (input_i >= 0)
		scanf(" %d", &input_j);
	} while (valid_move(board, moves_indx, input_i, input_j, n) == INVLD_INPUT);
	if (input_i < 0) {
		make_an_undo(board, moves_i_j, moves_indx, input_i, n);
		moves_indx += input_i;
	}
	else {		
		make_a_move(board, moves_i_j, moves_indx, input_i, input_j, n);
		moves_indx++;
	}
	return moves_indx;
}
/*print welcome message and scan the size (n) of the board game. 
set the board to empty and while the current player didnt lose, 
allow the next player to make a turn according to the game's regulations.
finally, print the winner or a tie. */
// 10 lines.
int main() {
	int n; int moves_indx = 0; int moves_i_j[N * N][2] = { {0} };
	char board[N][N]; 
	n = start_and_scan_size();
	set_board(board, n);
	while (check_if_lost(board, n, moves_indx) != 1 && check_if_tie(board, n) != 1) {
		moves_indx = make_valid_turn(board, moves_i_j, moves_indx, n);
	}
	if (check_if_tie(board, n) == 1 && check_if_lost(board, n, moves_indx) != 1)
		print_tie();
	else
		print_winner((moves_indx % 2) + 1);
	return 0;
}









