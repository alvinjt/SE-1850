/*----------------------------------------------------------------------------
-		                 SE 185: Lab 04 - Debugging Code	    	         -
-	Name: Alvin Thomas																	 -
- 	Section: 2																 -
-	NetID: alvin																     -
-	Date: 9/26/2023																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>

#include <time.h>

/*----------------------------------------------------------------------------- //Added a *
-                                Prototypes                                   -
------------------------------------------------------------------------------*/
char ask_to_play(int times_played);

int select_random_number();

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab04-3.c -o lab04-3
// Run with ./lab04-3
/* This program will play a simple Guessing Game with the computer. */

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/ //Added a /
int main(int argc, char *argv[])
{
    char prompt = '-';
    int played = 0, computer_guess = 0;

    prompt = ask_to_play(played);
    played = 1;

    while (prompt == 'y')     /* This line does not contain an error */
    {
        computer_guess = select_random_number();
        run_game(computer_guess);
        //prompt = ask_to_play(playd);
        prompt = ask_to_play(played); //Changed playd to played
    }
    //} //Removed curly brace

    printf("\n\nThanks for playing!\n");

    return 0;
}

/**
 * Asks the player if they want to play the Guessing Game.
 *
 * @param played_before - Whether the player has played a round of the game before or not.
 * @return - Whether the player wants to play again or not.
 */
char ask_to_play(int played_before)
{
    char yes_or_no;

    if (!played_before)    /* This line does not contain an error */
    {
        printf("Do you want to play a game? "
               "Enter 'y' to play, anything else not to play. :(\n  -> ");
        //scanf(" %c", yes_or_no);
        scanf(" %c", &yes_or_no); //Added a & before the variable name
    } else
    {
        scanf(" %c", &yes_or_no);
    }

    printf("%c", yes_or_no);

    return yes_or_no;
}

/**
 * Generates a random number between 1 to 100, inclusive.
 *
 * @return - A number between 1 and 100, inclusive.
 */
int select_random_number()
{
    srand(time(NULL));
    return rand() % 100;
}

/**
 * Starts the Guessing Game for you to play!
 *
 * @param computer_number - The randomly generated number to be used for the game.
 */
//void run_game(int computer_number)
int run_game(int computer_number) //Change void to int
{
    int number = 0;
    int correct = 0; //Initialized variable correct

    printf("\n\nYou are guessing a number. The options are 1 through 100.\n\n");
    printf("What is your guess on what number I will select?\n  -> ");
    //scanf("%c", &number);
    scanf("%d", &number); //Changed %c to %d
    while (!correct)    /* This line does not contain an error */
    {
        if (number < 1 || number > 100)
        {
            printf("\nYour number is not within the correct range of numbers. Guess again\n  -> ");
        //} else if (number = computer_number)
        } else if (number == computer_number) //Changed = to ==
        {
            printf("\nThe number was %d!\n", computer_number);
            printf("\nYou guessed the number correctly!\n\n"
                   "Do you want to play again? ('y' for yes)\n  -> ");
            correct = 1;
        //} else if (number < computer_number);
        } else if (number < computer_number) //Removed semicolon
        {
            printf("\nYou guessed too low. Enter another guess.\n  -> ");
        } else
        {
            printf("\n You guessed too high. Enter another guess.\n  -> ");
        }

        scanf("%d", &number);
    }
    return 0; //Added a return 0 statement
}