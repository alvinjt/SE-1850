/*----------------------------------------------------------------------------
-		        SE 185: Lab 02 - Solving Simple Problems in C	    	 	 -
-	Name: Alvin Thomas																	 -
- 	Section: 2																 -
-	NetID: alvin																     -
-	Date: 9/12/2023																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int integer_result;
    double decimal_result;

    integer_result = 77 / 5;
    printf("The value of 77/5 is %d, using integer math.\n", integer_result); //Replaced %lf with %d which is used for integers

    integer_result = 2 + 3;
    printf("The value of 2+3 is %d.\n",integer_result); //Typed integer_result to be printted

    decimal_result = 1.0 / 22.0;
    printf("The value 1.0/22.0 is %lf.\n", decimal_result); //Replaced %d which is used for integers with %lf which is used for double 

    return 0;
}