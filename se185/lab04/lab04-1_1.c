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
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab04-1_1.c -o lab04-1_1
// Run with ./lab04-1_1
/* This program outputs if a integer will divide into another integer with no remainder. */

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int i, j;

    //printf("Enter an integer: ")
    printf("Enter an integer: "); //Added a semicolon
    scanf("%d", &i);

    //printf("Enter another integer: );
    printf("Enter another integer: "); //Added a quotation mark
    //scanf("%d", &j)
    scanf("%d", &j); //Added a semicolon

    if (j % i == 0)
    {
        printf("%d divides %d\n", i, j);

    } else
    { //Added a curly brace 
        //pritf("%d does not divide %d\n", i, j);
        printf("%d does not divide %d\n", i, j); //Added 'n' in print
        printf("%d %% %d is %d\n", j, i, (j % i));
    }

    return 0;
}