/*----------------------------------------------------------------------------
-		                    SE 185: Lab 06 - Bop-It!	    	             -
-	Name: Alvin Thomas																	 -
- 	Section: 2																 -
-	NetID: alvin																     -
-	Date: 10/3/2023																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
-	                            Notes                                        -
-----------------------------------------------------------------------------*/
// Compile with gcc lab06.c -o lab06
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -b | ./lab06

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main()
{int t=0, triangle=0, circle=0, x=0, square=0, timeCheck=0, timeCount=2500, count=0, flag=0;
srand(time(NULL)); /* This will ensure a random game each time. */
printf("This is a Bop-It Game! \nPlease press the Circle Button to begin!\n");
while(triangle==0 && circle==0 && x==0 && square==0){
    scanf("%d, %d, %d, %d, %d", &t, &triangle, &circle, &x, &square);}
flag=circle;
while(flag){
    timeCheck=t;
    int n=rand()%4+1;
    if(n==1)
        printf("Press the triangle button!\n");
    else if(n==2)
        printf("Press the circle button!\n");
    else if(n=3)
        printf("Press the cross button\n");
    else
        printf("Press the square button\n");
    while(timeCheck + 250 > t){
        scanf("%d, %d, %d, %d, %d", &t, &triangle, &circle, &x, &square);}
        printf("You have %d milliseconds to respond!\n", timeCount);
        timeCheck=t;
        while(timeCheck+timeCount>=t){
            scanf("%d, %d, %d, %d, %d", &t, &triangle, &circle, &x, &square);
            if(!((triangle+circle+x+square)==0)){
                if(n==1 && triangle==1 && circle==0 && x==0 && square==0){
                    timeCount-=100;
                    count++;
                    break;}
                else if(n==2 && circle==1 && triangle==0 && x==0 && square==0){
                    timeCount-=100;
                    count++;
                    break;}
                else if(n==3 && x==1 && triangle==0 && circle==0 && square==0){
                    timeCount-=100;
                    count++;
                    break;}
                else if(n==4 && square==1 && triangle==0 && circle==0 && x==0){
                    timeCount-=100;
                    count++;
                    break;}
                else{printf("Wrong button! :(\nYou lose!\n");
                    flag=0; break;}}}
    if(timeCheck+timeCount<t){
        printf("You ran out of time. :(\nThanks for playing!\n");
        break;}}
printf("You made it through %d rounds!", count);
return 0;
}