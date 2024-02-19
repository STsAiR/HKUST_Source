/*
* Exercise for Lesson 4 : Hangman
*
* It is the simple word game, Hangman.
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const int true = 1;
const int false = 0;

// The list of words that the hangman game can choose from
// You can always add your own words just for fun.
char words[][20] = {
    "hangman",
    "computer",
    "programming",
    "microsoft",
    "visual",
    "studio",
    "express",
    "learning"
};

// This function returns true if the given letter is within the given word;
// it returns false otherwise.
int isletterinword(char word[], char letter)
{


    // Task 2. Finish this function
    //
    // Use a for loop to look at each position of the input word
    //
    // At each position, if the input letter is equal to the letter in that
    // position in word, return true.
    //
    // If the letter cannot be found after the for loop, return false.
    //
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] == letter) {
            return true;
        }
    }

    return false;
}


// This function returns true if the secret word has been guessed correctly.
// Otherwise, it will return false.
int iswordcomplete(char secretword[], char rights[])
{
    int i, x, sum = 0;

    // Task 3. Finish this function
    //
    // Use a for loop to look at each position of the secret word
    //
    // If all letters in the secret word is in the rights array,
    // return true; otherwise, return false.
    //
    for (i = 0; i < strlen(secretword); i++) {
        for (x = 0; x < strlen(rights); x++) {
            if (secretword[i] == rights[x]) {
                sum = sum + 1;
            }
        }
    }

    if (sum == strlen(secretword)) {
        return false;
    }
    else {
        return true;
    }
}

// This function prints the hangman based on the number of wrong guesses the
// player has made so far.
void printhangman(int numofwrongs)
{
    // Line 1
    printf("\t  ______\n");

    // Line 2
    printf("\t  |     |\n");

    // Line 3
    printf("\t  |     +\n");

    // Line 4 - left arm, head and right arm
    printf("\t  |");
    if (numofwrongs > 0) printf("    \\");
    if (numofwrongs > 1) printf("O");
    if (numofwrongs > 2) printf("/");
    printf("\n");

    // Line 5 - body
    printf("\t  |");
    if (numofwrongs > 3) printf("     |");
    printf("\n");

    // Line 6 - left leg and right leg
    printf("\t  |");
    if (numofwrongs > 4) printf("    /");
    if (numofwrongs > 5) printf(" \\");
    printf("\n");

    // Line 7
    printf("\t  |\n");

    // Line 8
    printf("\t__|__\n");
}

// This function prints an array of letters as a list of letters separated by
// spaces.
void printletters(char letters[])
{
    int i;

    for (i = 0; i < strlen(letters); i++) {
        printf("%c ", letters[i]);
    }
}

// This function prints the screen of the game.
// If a letter in the secret word has been guessed correctly, the
// letter will be shown; otherwise, the letter will be shown as '_'.
void printscreen(char rights[], char wrongs[], char secretword[])
{
    int i;

    // Clear the screen
    for (i = 0; i < 25; i++)
        printf("\n");

    // Print the hangman
    printhangman(strlen(wrongs));
    printf("\n");

    // Print the correct and wrong guesses so far
    printf("Correct guesses: ");
    printletters(rights);
    printf("\n");
    printf("Wrong guesses: ");
    printletters(wrongs);
    printf("\n\n\n");

    // Print the secret word
    printf("\t");
    for (i = 0; i < strlen(secretword); i++) {
        if (isletterinword(rights, secretword[i])) {
            printf("%c ", secretword[i]);
        }
        else {
            printf("_ ");
        }
    }
    printf("\n\n");
}

int main()
{
    // This is the index of the secret word in the word list, which is defined
    // in the global variable words
    int secretwordindex;

    // This array stores the letters the player has guessed correctly so far
    char rights[20];

    // This array stores the letters the player has guessed incorrectly so far
    char wrongs[7];

    // This value is used to put the current guess from the player in the game loop
    char guess;


    // Task 1. Randomly pick a secret word
    //
    // 1. You need to randomize the random numbers using srand
    //
    srand(time(0));

    // 2. You then store a random number in secretwordindex, which has a range
    //    of 0 to (number of words) - 1
    //
    secretwordindex = rand() % 7;


    // Task 1. Initialize the arrays
    //
    // 1. Initialize the rights array to zeros (put '\0' to every item of the
    //    array)
    //
    for (int i = 0; i < 20; i++) {
        rights[i] = '\0';
    }
    // 2. Initialize the wrongs array to zeros (put '\0' to every item of the
    //    array)
    //
    for (int i = 0; i < 7; i++) {
        wrongs[i] = '\0';
    }

    // Task 3. Put the correct conditions in the while loop for these situations:
    //
    // 1. when the number of wrong guesses is bigger than or equal to 6, or
    //
    // 2. when all letters of the secret word have been guessed correctly
    //
    while (strlen(wrongs) < 6 && iswordcomplete(words[secretwordindex], rights)) {
        // Print the hangman screen
        printscreen(rights, wrongs, words[secretwordindex]);

        // Ask for the guess
        printf("\nPlease enter your guess: ");
        scanf(" %c", &guess);


        // Task 2. Put the guess in the corresponding arrays
        //
        // If the guess is in the secret, put the guess in the rights array
        // Otherwise, put the guess in the wrongs array
        //
        // Check whether or not the player's guess is inside the secret word
        if (isletterinword(words[secretwordindex], guess)) {
            // Store guess at the end of the rights array
            rights[strlen(rights)] = guess;
        }
        else {
            wrongs[strlen(wrongs)] = guess;
        }

    }

    // Print the final hangman screen 
    printscreen(rights, wrongs, words[secretwordindex]);


    // Task 3. Print a game over message
    //
    // The message should be different when the player wins or loses.
    //
    if (strlen(wrongs) < 6) {
        printf("You have won!\n");
    }
    else {
        printf("You have lost.\n");
    }

}
