/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 52
#define WORDS_ARRAY_SIZE 100
#define MAX_STR_LEN 50
#define SMALL_LETTER_KEY 'z' - 'a' + 1
#define ZERO_LENGTH 0
#define MALLOC_FAIL -1
#define SMALL_a 'a'
#define SMALL_z 'z'
#define CAPITAL_a 'A'

char encrypt_char(unsigned char key[KEY_SIZE], char ch);
int read_words(char* words[], int size, int max_str_len);
void encrypt_words(char* words[], int num_words, unsigned char key[KEY_SIZE]);
void release_memory(char* words[], int num_words);

char encrypt_char(unsigned char key[KEY_SIZE], char ch) {
	int index;
	if (ch >= SMALL_a && ch <= SMALL_z)
		index = ch - SMALL_a + SMALL_LETTER_KEY;
	else
		index = ch - CAPITAL_a;
	ch = key[index];
	return ch;
}

int read_words(char* words[], int size, int max_str_len) {
	int count = ZERO_LENGTH; char* arr = NULL;
	char word[MAX_STR_LEN];
	while (scanf("%s", word) != EOF) {
		if (strlen(word)+1 < (unsigned)max_str_len && count < size)
			arr = (char*)malloc(sizeof(char) * (strlen(word) + 1));
		if (arr == NULL)
			return MALLOC_FAIL;
		strcpy(arr, word);
		words[count] = arr;
		count++;
	}
	return count;
}

void encrypt_words(char* words[], int num_words, unsigned char key[KEY_SIZE]) {
	for (int  i = 0; i < num_words; i++){
		for (int j = 0; (unsigned)j < strlen(words[i]); j++) {
			words[i][j]=encrypt_char(key, *(words[i] + j));
		}
	}
}

void release_memory(char* words[], int num_words) {
	for (int i = 0; i < num_words; i++) {
		free(words[i]);
	}
}

void print_words(char* words[], int num_words)
{
	int i;
	for (i = 0; i < num_words; i++) {
		printf("%s\n", words[i]);
	}
}


int main()
{
	unsigned char key[KEY_SIZE] = {

		'>', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '~', 'S', 'D',
		'F', 'G', '*', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', '+', 'M',
		'm','b','n','v','z','c','@','q','r','u','i','e','r',
		't','o','p','w','$','j','g','d','%','s','f','h','k'
	};
	int num_words = 0, i;
	char* words[WORDS_ARRAY_SIZE];

	for (i = 0; i < WORDS_ARRAY_SIZE; i++) {
		words[i] = NULL;
	}

	num_words = read_words(words, WORDS_ARRAY_SIZE, MAX_STR_LEN);
	if (num_words == -1)
	{
		printf("Failed to read words.\n");
		return 0;
	}
	encrypt_words(words, num_words, key);
	print_words(words, num_words);
	release_memory(words, num_words);
	return 0;
}