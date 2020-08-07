#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORD_LENGTH 11 // The length of the Cashword grid

int cash_word(char * letters);
int valid_word(char * letters, char * word);
int prize_value(int wordsFound);
int prize_mult(int wordsFound, int multiplier);
