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
#include <math.h>

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab04-1_4.c -o lab04-1_4
// Run with ./lab04-1_4
/* This program calculates the energy of one photon
 * of user-inputted wave-length of light */

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    //double speed_of_light!;
    double speed_of_light; //Removed '!'
    //double wave-length;
    double wave_length; //Replaced - with _
    //double ~length_in_meters;
    double length_in_meters; //Removed '~'
    //double plank const;
    //double 0energy;
    double energy0; //Moved '0' to end of variable name

    //plank const = 6.62606957 * pow(10, -34); // Planck's constant
    const double plank = 6.62606957 * pow(10, -34); // Moved const and initialized variable
    //speed_of_light! = 2.99792458 * pow(10, 8); // Constant for the speed of light
    speed_of_light = 2.99792458 * pow(10,8); //Removed '!'
    //wave-length = 0;
    wave_length = 0; //Replaced '-' with '_'
    //~length_in_meters = 0;
    length_in_meters = 0; //Removed '~'
    //0energy = 0;
    energy0 = 0; 

    printf("Welcome! This program will give the energy, in Joules,\n");
    printf("of 1 photon with a certain wave-length.\n");
    printf("Please input a wave-length of light in nano-meters.\n");
    printf("Please do not enter a negative, or zero, wave-length.\n");

    //scanf("%lf", &wave-length);
    scanf("%lf", &wave_length); //Replaced '-' with '_'

    //if (wave-length > 0.0)
    if (wave_length > 0.0) //Replaced '-' with '_' 
    {
        //~length_in_meters = wave-length / pow(10, 9); // Converting nano-meters to meters
        length_in_meters = wave_length / pow(10,9); //Removed '~' and replaced '-' with '_'
        //0energy = (plank const * speed_of_light!) / ~length_in_meters; // Calculating the energy of 1 photon
        energy0 = (plank * speed_of_light) / length_in_meters; //Moved 0 to end of variable name, removed 'const', '!' and '~'
        /*printf("A photon with a wave-length of %08.3lf nano-meters, carries "
               "\napproximately %030.25lf joules of energy.", wave-length, 0energy);*/
        printf("A photon with a wave_length of %08.3lf nano-meters, carries "
               "\napproximately %030.25lf joules of energy.", wave_length, energy0); //Replaced '-' with '_' and moved 0 to end of variable name 

    } else
    {
        printf("Sorry, you put in an invalid number.");
        printf("Please rerun the program and try again.");
    }

    return 0;
}