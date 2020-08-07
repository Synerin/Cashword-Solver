#include "cashword.h"

// Possibly optimization: Make letters a HashMap or simple 26-size char array

int cash_word(char * letters) {
    char word[MAX_WORD_LENGTH];
    int wholeWords = 0;
    
    int i, letterLength = strlen(letters);
    
    for(i = 0; i < letterLength; i++) {
        letters[i] = toupper(letters[i]);
    }
    
    // TODO: Add/fix validation for word scanned with fgets (namely, length)
    while(1) {
        printf("\nType one word at a time, then press ENTER. Press ENTER again to quit.\n");
        fgets(word, MAX_WORD_LENGTH, stdin);
        
        int wordLength = strlen(word);
        
        // if(wordLength > MAX_WORD_LENGTH) {
        //     printf("\nERROR: Submitted word is too long. Must be no longer than 12 characters.\n");
        //     continue;
        // }
        
        if(word[0] == '\n') {
            break;
        } else {
            for(i = 0; i < wordLength; i++) {
                word[i] = toupper(word[i]);
            }
            
            if(valid_word(letters, word)) {
                wholeWords++;
            }
        }
    }
    
    return wholeWords;
}

/**
 * Checks that word is valid based on letters input.
 * Returns 0 if word is NULL or contains characters not in letters.
 */
int valid_word(char * letters, char * word) {
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
    
    return 1;
}

// Calculate prize value based on the number of words found
int prize_value(int wordsFound) {
    int prize = 0;
    
    switch(wordsFound) {
        case(0):
        case(1):
            break;
        case(2):
            prize = 2;
            break;
        case(3):
            prize = 4;
            break;
        case(4):
            prize = 5;
            break;
        case(5):
            prize = 10;
            break;
        case(6):
            prize = 20;
            break;
        case(7):
            prize = 100;
            break;
        case(8):
            prize = 200;
            break;
        case(9):
            prize = 1000;
            break;
        case(10):
            prize = 50000;
            break;
        default:
            printf("ERROR: Invalid number of words found: %d.", wordsFound);
            prize = NULL;
    }
    
    return prize;
}

// Calculate prize value considering prize multiplier
int prize_mult(int wordsFound, int multiplier) {
    return prize_value(wordsFound) * multiplier;
}
