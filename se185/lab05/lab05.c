/*----------------------------------------------------------------------------
-		         SE 185: Lab 05 - Conditionals (What's up?)	    	         -
-	Name: Alvin Thomas																	 -
- 	Section: 2																 -
-	NetID: alvin																     -
-	Date: 9/26/2023																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
int close_to (double tolerance, double point, double value);
double magnitude(double x, double y, double z);
void orientation(double gx, double gy, double gz);
/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab05.c -o lab05
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -a -g -b | ./lab05

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int flag;
int main(int argc, char *argv[])
{
    int triangle, circle, x_button, square;
    double ax, ay, az, gx, gy, gz;
    double acceleration;

    while (1)
    {
        scanf("%lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d",
              &ax, &ay, &az, &gx, &gy, &gz, &triangle, &circle, &x_button, &square);

        /* printf for observing values scanned in from ds4rd.exe,
         * be sure to comment or remove in final program */
        // printf("Echoing output: %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d \n",
            // ax, ay, az, gx, gy, gz, triangle, circle, x_button, square);
        acceleration = magnitude(ax,ay,az);
        if(close_to(0.2,0.1,acceleration))
        orientation(gx,gy,gz);
        /* It would be wise (mainly save time) if you copy your code to calculate
         * the magnitude from lab03-1.c. You will also need to copy your
         * prototypes and functions to the appropriate sections in this program. */

        //printf("The acceleration's current magnitude is: %lf\n", magnitude(ax, ay, az));
        if(triangle==1)
        break;
    }

    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */

int close_to(double tolerance, double point, double value)
{if((value <= (point+tolerance)) && (value >= (point-tolerance)))
    return 1;
else
    return 0;
}

double magnitude(double x, double y, double z) //magnitude function from lab03-1
{return sqrt(x*x+y*y+z*z);}

void orientation(double gx, double gy, double gz)
{int a,b;
if(close_to(0.2,1,gy))
    {if(flag!=1)
    {printf("TOP\n");
    flag = 1;}}
else if(close_to(0.2,-1,gy))
    {if(flag!=2) 
    {printf("BOTTOM\n");
    flag = 2;}}
else if(close_to(0.2,-1,gx)) 
   {if(flag!=3) 
    {printf("LEFT\n");
     flag = 3;}}
else if(close_to(0.2,1,gx))
    {if(flag!=4)
    {printf("RIGHT\n");
    flag = 4;}}
else if(close_to(0.2,-1,gz))
    {if(flag!=5)
    {printf("FRONT\n");
    flag = 5;}}
else if(close_to(0.2,1,gz))
    {if(flag!=6)
    {printf("BACK\n");
    flag = 6;}}
}