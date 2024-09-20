/*-----------------------------------------------------------------------------
-					  		SE 185 Lab 08
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name: Alvin Thomas
- Section: 2
-	NetID: alvin
-	Date: 11/7/2023
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-								Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>
#include <stdlib.h>

/*-----------------------------------------------------------------------------
-								Defines
-----------------------------------------------------------------------------*/
/* Mathmatical constants */
#define PI 3.14159

/* 	Screen geometry
    Use ROWS and COLUMNS for the screen height and width (set by system)
    MAXIMUMS */
#define COLUMNS 100
#define ROWS 80

/* 	Character definitions taken from the ASCII table */
#define AVATAR 'A'
#define WALL '*'
#define EMPTY_SPACE ' '

/*	Number of samples taken to form an moving average for the gyroscope data
    Feel free to tweak this. */
#define NUM_SAMPLES 10


/*-----------------------------------------------------------------------------
-								Static Data
-----------------------------------------------------------------------------*/
/* 2D character array which the maze is mapped into */
char MAZE[COLUMNS][ROWS];


/*-----------------------------------------------------------------------------
-								Prototypes
-----------------------------------------------------------------------------*/
/*	POST: Generates a random maze structure into MAZE[][]
    You will want to use the rand() function and maybe use the output %100.
    You will have to use the argument to the command line to determine how
    difficult the maze is (how many maze characters are on the screen). */
void generate_maze(int difficulty);

/*	PRE: MAZE[][] has been initialized by generate_maze()
    POST: Draws the maze to the screen */
void draw_maze(void);

/*	PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
    POST: Draws character use to the screen and position x,y */
void draw_character(int x, int y, char use);

/*	PRE: -1.0 < mag < 1.0
    POST: Returns tilt magnitude scaled to -1.0 -> 1.0
    You may want to reuse the roll function written in previous labs. */
double calc_roll(double mag);

/* 	Updates the buffer with the new_item and returns the computed
    moving average of the updated buffer */
double m_avg(double buffer[], int avg_size, double new_item);


/*-----------------------------------------------------------------------------
-								Implementation
-----------------------------------------------------------------------------*/
/*	Main - Run with './ds4rd.exe -t -g -b' piped into STDIN */
void main(int argc, char* argv[])
{
int t, newt; 
double newX, newY, avgX, avgY, z;
double x[10000], y[10000]; 
int X = 10, Y = 0; 
int oldX, oldY; 
int flag = 1; 

  if (argc != 2 )
  {
      printw("You must enter the difficulty level on the command line.");
      refresh();
      return;
  }
  else
  {
    int difference; 
    sscanf(argv[1], "%d", &difference ); 
    /* 	Setup screen for Ncurses
        The initscr functionis used to setup the Ncurses environment
        The refreash function needs to be called to refresh the outputs
        to the screen */
    initscr();
    refresh();

    /* WEEK 2 Generate the Maze */
    generate_maze(difference); 
    draw_maze();
    /* Read gyroscope data and fill the buffer before continuing */
    for(int i = 0; i < NUM_SAMPLES; i++) 
    { 
       scanf("%d, %lf, %lf, %lf", &t, &newX, &newY, &z); 
        x[i] = newX; 
        y[i] = newY; 
    } 
    newt = t;
    /* Event loop */
    do
    {
        /* Read data, update average */
        scanf("%d, %lf, %lf, %lf", &t, &newX, &newY, &z); 
        avgX = m_avg(x, NUM_SAMPLES, newX); 
        avgY = m_avg(y, NUM_SAMPLES, newY); 
        /* Is it time to move?  if so, then move avatar */
        if(t - newt > 500){ 
        newt = t; 
        oldX = X; 
        oldY = Y; 
        if(avgX > .8){ 
            if(MAZE[Y][X-1] == EMPTY_SPACE && X > 0){ 
                X -= 1; 
                draw_character(X,Y,AVATAR); 
                draw_character(oldX,oldY,EMPTY_SPACE); 
        } 
    }
    else if(avgX < -.8){ 
    if(MAZE[Y][X+1] == EMPTY_SPACE && X < 80){ 
        X += 1; 
        draw_character(X,Y,AVATAR); 
        draw_character(oldX,oldY,EMPTY_SPACE); 
    } 
}
else{ 
if(MAZE[Y+1][X] == EMPTY_SPACE){ 
Y += 1; 
draw_character(X,Y,AVATAR); 
draw_character(oldX,oldY,EMPTY_SPACE); 
} 
draw_character(X,Y,AVATAR); 
} 
} 
if(MAZE[Y][X-1] == WALL && MAZE[Y][X+1] == WALL && MAZE[Y+1][X] == WALL){ 
flag = 0;
break;
}
else if(Y >= 80)
    break; 

}while(Y < ROWS-1); // Change this to end game at right time

    /* Print the win message */


    /* This function is used to cleanup the Ncurses environment.
    Without it, the characters printed to the screen will persist
    even after the progam terminates */
    endwin();

  }
if(flag)
    printf("YOU WIN!\n");
else
    printf("YOU LOSE!\n");
}

double m_avg(double buffer[], int avg_size, double new_item)
{
double sum = 0; 
for(int i = 0; i < avg_size - 1; i++){ 
buffer[i] = buffer[i+1]; 
sum += buffer[i]; 
} 
buffer[avg_size-1] = new_item; 
sum += new_item; 
return (sum/avg_size); 
}


/* 	PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
    POST: Draws character use to the screen and position x,y
    THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
    DO NOT NEED TO CHANGE THIS FUNCTION. */
void draw_character(int x, int y, char use)
{
    mvaddch(y,x,use);
    refresh();
}

void generate_maze(int difficulty){ 
srand(difficulty); 
for(int i = 0; i < ROWS;i++)
    for(int j = 0; j < COLUMNS;j++){
    int random = rand() % 100; 
    if(random < difficulty)
        MAZE[i][j] = WALL; 
    else 
        MAZE[i][j] = EMPTY_SPACE; 
}}

void draw_maze(void){ 
for(int i = 0; i < ROWS;i++)
    for(int j = 0; j < COLUMNS;j++)
        draw_character(i,j,MAZE[j][i]); 
} 