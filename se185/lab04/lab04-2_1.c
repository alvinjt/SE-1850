/*----------------------------------------------------------------------------
-		                 SE 185: Lab 04 - Debugging Code	    	         -
-	Name: Alvin Thomas																	 -
- 	Section: 2																 -
-	NetID: alvin																     -
-	Date: 9/19/2023																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
int is_odd(int number);

int is_even(int number);

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab04-2_1.c -o lab04-2_1
// Run with ./lab04-2_1
/* This program accepts a user input and determines
 * if the integer is an odd or an even number */

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    //int input == 0;
    int input = 0; //Replaced '==' with '='

    printf("Please input an integer: ");
    scanf("%d", &input);

    //if (is_odd(input) = 1)
    if (is_odd(input) != 0) //Replaced '=' with '!=' and '1' with '0'
    {
        printf("%d is an odd number!\n", input);
    }

    //if (is_even(input) = 1)
    if (is_even(input) == 1) //Replaced '=' with '==' and 1 with 0
    {
        printf("%d is an even number!\n", input);
    }

    return 0;
}

/**
 * Determines whether the given number is even.
 *
 * @param number - The number in question of even status.
 * @return - True if the given number was even.
 */
int is_even(int number)
{
    return !(number % 2);
}

/**
 * Determines whether the given number is odd.
 *
 * @param number - The number in question of odd status.
 * @return - True if the given number was odd.
 */
int is_odd(int number)
{
    return number % 2;
}