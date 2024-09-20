/*----------------------------------------------------------------------------
-		    SE 185: Lab 03 - Introduction to the DS4 and Functions	    	 -
-	Name: Alvin Thomas																	 -
- 	Section: 2																 -
-	NetID: alvin															     -
-	Date: 9/12/2023																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
double magnitude(double x, double y, double z);

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab03-1.c

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
    int t;
    double ax, ay, az;

    while (1)
    {
        scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);

        /* CODE SECTION 0 */
        printf("Echoing output: %08.3lf, %07.4lf, %07.4lf, %07.4lf\n", t/1000.0, ax, ay, az);
        


        /* 	CODE SECTION 1 */
        printf("At %d ms, the acceleration's magnitude was: %lf\n", t, magnitude(ax, ay, az));


        /* 	CODE SECTION 2 */
        
            printf("At %d minutes, %d seconds, and %d milliseconds it was: %lf\n",
            minutes(t), seconds(t), milliseconds(t), magnitude(ax, ay, az));
        
    }

    return 0;
}

/* Put your functions here */
int minutes(int t)
{   
    int m = t/60000;    
    return m;    
}
int seconds(int t)
{   
    int s = (t%60000)/1000;
    return s;
}
int milliseconds (int t)
{
    int ms = t%1000;
    return ms;
}
/*
 * Calculates and returns the magnitude of three given values.
 *
 * @param x - The x-axis scanned values from the DS4 controller.
 * @param y - The y-axis scanned values from the DS4 controller.
 * @param z - The z-axis scanned values from the DS4 controller.
 * @return - The magnitude of the given values.
 */
double magnitude(double x, double y, double z)
{
    // Step 8, uncomment and modify the next line
    return sqrt(x*x+y*y+z*z);
}