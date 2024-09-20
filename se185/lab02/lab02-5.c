/*----------------------------------------------------------------------------
-		        SE 185: Lab 02 - Solving Simple Problems in C	    	 	 -
-	Name: Alvin Thomas																	 -
- 	Section: 2																 -
-	NetID: alvin																     -
-	Date: 9/5/2023																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>   // Google this header file to learn more! :)

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    double a, b, c;
    double filler;

    /* Put your code after this line */
    printf("Enter the value of a: ");
    scanf("%lf", &a);
    printf("Enter the value of b: ");
    scanf("%lf", &b);


    /* This next line will calculate the square root of whatever value is
     * inside the parenthesis and assigns it to the variable filler. */
    filler = sqrt((a*a)+(b*b));
    c=filler;
    printf("c = %lf",c);
    return 0;
}