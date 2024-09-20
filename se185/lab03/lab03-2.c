/*----------------------------------------------------------------------------
-		    SE 185: Lab 03 - Introduction to the DS4 and Functions	    	 -
-	Name: Alvin Thomas																	 -
- 	Section: 2																 -
-	NetID: alvin																     -
-	Date: 9/16/2023																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab03-2.c -o lab03-2
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -b | ./lab03-2

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int triangle;
    int circle;
    int x;
    int square;
    while (1)
    {
        scanf("%d, %d, %d, %d", &triangle, &circle, &x, &square);
        printf("Number of buttons being pressed: %d\n", buttons(triangle, circle, x, square));
        fflush(stdout);
    }

    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */
int buttons(int triangle, int circle, int x, int square)
{   int numButtons = triangle + circle + x + square;
    return numButtons;
}