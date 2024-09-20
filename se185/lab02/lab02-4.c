#include <stdio.h>
#include <math.h>
int main()
{
    int a=6427+1725;
    int b=(6971*3925) - 95;
    double c=79+12/5;
    double d=3640.0/107.9;
    int e=(22/3)*3;
    int f=22/(3*3);
    double g=22/(3*3);
    double h=22/3*3;
    double i=(22.0/3)*3.0;
    int j=22.0/(3*3.0);
    double k=22.0/3.0*3.0;
    printf("6427+1725 = %d \n(6971 * 3925) - 95 = %d \n79+12/5 = %.2lf \n3640.0/107.9 = %.2lf \n(22/3)*3 = %d \n22/(3*3) = %d \n22/(3*3) = %.2lf \n22/3*3 = %.2lf \n(22.0/3)*3.0 = %.2lf \n22.0/3.0*3.0 = %.2lf\n", a, b, c, d, e, f, g, h, i, j, k);   
    double l=(23.567*23.567)/(4*M_PI);
    double m=14*0.3048;
    double n=(76-32)/1.8;
    printf("Area of a circle with circumference 23.567 = %lf\n", l);
    printf("14 ft. = %lf m\n", m);
    printf("76 Farenheit = %lf Celsius\n", n);
    return 0;
}