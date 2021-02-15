/**
 * Cashword Solver by Jason Davis.
 * A program to quickly output any winnings from a Cashword lottery card.
 * The winning letters are submitted as the command line argument,
 * and the words on the puzzle are scanned one-by-one.
 */
#include "cashword.h"

int main(int argc, char * argv[]) {
    if(argc < 2) {
        printf("ERROR. Command line argument not provided.");
        return 0;
    }
    
    char * letters = argv[1];
    struct ListNode* wordsFound = cash_word(letters);
    int numWords = count_nodes(wordsFound);
    
    int i, words = 0;
    
    printf("\n\aThis CASHWORD Puzzle has %d matching word(s):\n", numWords);
    print_nodes(wordsFound);
    printf("\nPrize value for this Cashword Puzzle: $%d", prize_value(numWords));
    
    free(wordsFound);
    
    return 0;
}
