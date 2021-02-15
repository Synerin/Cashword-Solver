#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORD_LENGTH 11 // The length of the Cashword grid

// ListNode structure for word tracking
struct ListNode {
    char* word;
    struct ListNode* next;
};

// Functions
struct ListNode* cash_word(char* letters);
int valid_word(char* letters, char* word, struct ListNode* root);
int prize_value(int wordsFound);
int prize_mult(int wordsFound, int multiplier);
int count_nodes(struct ListNode* wordsFound);
void print_nodes(struct ListNode* wordsFound);
