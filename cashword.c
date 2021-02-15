#include "cashword.h"

const int prize_values[] = {0, 0, 2, 4, 5, 10, 20, 100, 200, 1000, 50000};

// Possible optimization: Make letters a HashMap or simple 26-size char array

struct ListNode* cash_word(char * letters) {
    char word[MAX_WORD_LENGTH];
    int wholeWords = 0;
    
    int i, letterLength = strlen(letters);
    
    for(i = 0; i < letterLength; i++) {
        letters[i] = toupper(letters[i]);
    }
    
    struct ListNode* root = malloc (sizeof(struct ListNode*));
    root->next = NULL;
    struct ListNode* ptr = malloc (sizeof(struct ListNode*));
    
    // TODO: Add/fix validation for word scanned with fgets (namely, length)
    while(1) {
        printf("Type one word at a time, then press ENTER. Press ENTER again to quit.\n");
        fgets(word, MAX_WORD_LENGTH, stdin);
        
        int wordLength = strlen(word);
        
        // if(wordLength > MAX_WORD_LENGTH) {
        //     printf("\nERROR: Submitted word is too long. Must be no longer than 11 characters.\n");
        //     continue;
        // }
        
        if(word[0] == '\n') {
            break;
        } else {
            for(i = 0; i < wordLength; i++) {
                word[i] = toupper(word[i]);
            }
            
            if(valid_word(letters, word, root)) {
                if(wholeWords == 0) {
                    root->word = (char*) malloc (sizeof(char) * strlen(word));
                    strcpy(root->word, word);
                    root->next = ptr;
                } else {
                    ptr->word = (char*) malloc (sizeof(char) * strlen(word));
                    strcpy(ptr->word, word);
                    ptr->next = (struct ListNode*) malloc (sizeof(struct ListNode*));
                    ptr = ptr->next;
                }
                
                wholeWords++;
            }
            
            printf("\n");
        }
    }
    
    free(ptr);
    
    return root;
}

/**
 * Checks that word is valid based on letters input.
 * Returns 0 if word is NULL or contains characters not in letters.
 */
int valid_word(char * letters, char * word, struct ListNode* root) {
    if(!word) return 0;
    
    int i, j, isValid;
    int wordLength = strlen(word), letterLength = strlen(letters);
    
    // Check each letter in word
    for(i = 0; i < wordLength && isalpha(word[i]); i++) {
        isValid = 0;
        
        // Check that each letter in word is also in letters
        for(j = 0; j < letterLength; j++) {
            if(word[i] == letters[j]) {
                isValid = 1;
                break;
            }
        }
        
        if(!isValid) return 0;
    }
    
    // Check that word has not already appeared
    while(root != NULL && root->word != NULL) {
        if(strcmp(root->word, word) == 0) return 0;
        
        root = root->next;
    }
    
    return 1;
}

// Calculate prize value based on the number of words found
int prize_value(int wordsFound) {
    if(wordsFound > 11) {
        printf("ERROR: More than 11 matching words found.");
        return 0;
    }
    
    return prize_values[wordsFound];
}

// Count number of nodes in wordsFound, i.e. the number of matching words
int count_nodes(struct ListNode* wordsFound) {
    int totalNodes = 0;
    
    while(wordsFound && wordsFound->word) {
        totalNodes++;
        
        wordsFound = wordsFound->next;
    }
    
    return totalNodes;
}

// Print out each matching word
void print_nodes(struct ListNode* wordsFound) {
    while(wordsFound && wordsFound->word) {
        printf("%s", wordsFound->word);
        
        wordsFound = wordsFound->next;
    }
}

// Calculate prize value considering prize multiplier
int prize_mult(int wordsFound, int multiplier) {
    return prize_value(wordsFound) * multiplier;
}
