// Lab 09 DS4Talker Skeleton Code       
/*Answer: I used posx and posy variables to determine the position of the pointer on the screen. If the input from the DualShock 4 controller's joystick exceeds 100, then the pointer moves in the specified direction,
by doing pos-1 or pos+1 and then passing that value to the draw_character function*/

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses/ncurses.h>
#define WORDLENGTH 11
#define MAXWORDS 100
#define DEBUGM 1   // Set this to 0 to disable debug output

// Reads words from the file into WL and trims the whitespace off of the end
// DO NOT MODIFY THIS FUNCTION
int read_words(char* WL[MAXWORDS], char* file_name);

void draw_character(int x, int y, char use);
// modifies str to trim white space off the right side
// DO NOT MODIFY THIS FUNCTION
void trimws(char* str);

int main(int argc, char* argv[]) {
	char* wordlist[MAXWORDS];
	int wordSizes[200];
	int wordcount;
	int i;
	int time, tri, cir, cross, square, rjpress, ljpress, options, share, rt, lt, rb, lb, ljx, ljy, rjx, rjy; //Integers used to store data from the DS4 controller
	int pos = 0;
	int posx = 1;
	int tNew = 0;
	int sentencePos = 0;
	int sentencePos1 = 0;
	int flag = 1;
	int flag2 = 0; //An integer flag which becomes 1 if the circle button is pressed
	char word[50];
	wordcount = read_words(wordlist, argv[1]);

	
	if (DEBUGM) {
		printf("Read %d words from %s \n", wordcount, argv[1]);
		for (i = 0; i < wordcount; i++) {
			printf("%s,", wordlist[i]);

		}
		printf("\n");
	}

	// most of your code goes here. Do not forget to include the ncurses library	
	initscr();
    refresh();
	int p = 0;

	for(int j = 0; j < 4; j++)
	{
		for(int y = 0; y < 16; y++)
		{
			mvprintw(y, j * 15, "%15s", wordlist[p]);
			refresh();
			p++;
		}
		
	}
	for(int j = 0; j < 12; j++)
	{
			mvprintw(j, 4 * 15, "%15s", wordlist[p]);
			refresh();
			p++;
	}
	mvprintw(18, 0, "Triangle = Add word with space, Square = Add word without space, X = Remove characters, Circle = Capitalize the first letter of the next word");
	mvprintw(20, 0, "Sentence:");
	refresh();
	
	p = 0;
	while(flag)
	{
		scanf("    %d, %d,%d,%d,%d, %d,%d,%d,%d,%d,%d,%d,%d,  %d,   %d,  %d,   %d", &time, &tri, &cir, &cross, &square, &rjpress, &ljpress, &options, &share, &rt, &lt, &rb, &lb, &ljx, &ljy, &rjx, &rjy); //Scans in values from the DS4 controller
		if(time > tNew)
		{
			if(ljy < -100 && pos > 0) //To make the pointer move up
			{
				pos--;
				p--;
				draw_character(posx * 15 + 1, pos + 1, ' ');
				draw_character(posx * 15 + 1, pos - 1, ' ');
				draw_character(posx * 15 + 1, pos, '<');
			}
			else if(ljy > 100 && pos < 15) //To make the pointer move down
			{
				pos++;
				p++;
				draw_character(posx * 15 + 1, pos + 1, ' ');
				draw_character(posx * 15 + 1, pos - 1, ' ');
				draw_character(posx * 15 + 1, pos, '<');
			}
			if(ljx < -100 && posx > 1) //To make the pointer move left
			{
				posx--;
				p -= 16;
				draw_character((posx + 1) * 15 + 1, pos, ' ');
				draw_character((posx - 1) * 15 + 1, pos, ' ');
				draw_character(posx * 15 + 1, pos, '<');
			}
			else if(ljx > 100 && posx < 5) //To make the pointer move right
			{
				posx++;
				p += 16;
				draw_character((posx + 1) * 15 + 1, pos, ' ');
				draw_character((posx - 1) * 15 + 1, pos, ' ');
				draw_character(posx * 15 + 1, pos, '<');
			}
	
			if(tri == 1) //To print a word with a space
			{
				if(sentencePos == 0) //Checks whether it is the first word
				{	if(flag2==1) //Checks whether circle button was pressed just before
					{
					strcpy(word,wordlist[p]);
					word[0] = toupper(word[0]); //Capitalizes the first letter of the word
					mvprintw(21, 0, " %s", word);
					wordSizes[sentencePos] = strlen(wordlist[p]) + 1;
					sentencePos1 += wordSizes[sentencePos];
					sentencePos++;
					flag2 = 0;
					}
					else{
					mvprintw(21, 0, " %s", wordlist[p]);
					wordSizes[sentencePos] = strlen(wordlist[p]) + 1;
					sentencePos1 += wordSizes[sentencePos];
					sentencePos++;

				}}
				else
				{
					if(flag2==1){ //Checks whether circle button was pressed just before
					strcpy(word,wordlist[p]);
					word[0] = toupper(word[0]); //Capitalizes the first letter of the word
					mvprintw(21, sentencePos1, " %s", word);
					wordSizes[sentencePos] = strlen(wordlist[p]) + 1;
					sentencePos1 += wordSizes[sentencePos];
					sentencePos++;
					flag2 = 0;
					}
					else{
					mvprintw(21, sentencePos1, " %s", wordlist[p]);
					wordSizes[sentencePos] = strlen(wordlist[p]) + 1;
					sentencePos1 += wordSizes[sentencePos];
					sentencePos++;
				}}
					
				refresh();
			}
			if(square == 1) //To print a word without a space
			{
				if(sentencePos == 0)
				{	if(flag2==1) //Checks whether circle button was pressed just before
				{
					strcpy(word,wordlist[p]);
					word[0]= toupper(word[0]); //Capitalizes the first letter of the word
					mvprintw(21, 0, " %s", word);
					wordSizes[sentencePos] = strlen(wordlist[p]);
					sentencePos1 += wordSizes[sentencePos] + 1;
					sentencePos++;
					flag2 = 0;
				}
					else{
					mvprintw(21, 0, " %s", wordlist[p]);
					wordSizes[sentencePos] = strlen(wordlist[p]);
					sentencePos1 += wordSizes[sentencePos] + 1;
					sentencePos++;
				}}
				else
				{	if(flag2==1) //Checks whether circle button was pressed just before
				{
					strcpy(word,wordlist[p]);
					word[0] = toupper(word[0]); //Capitalizes the first letter of the word
					mvprintw(21, sentencePos1, "%s", word);
					wordSizes[sentencePos] = strlen(wordlist[p]);
					sentencePos1 += wordSizes[sentencePos];
					sentencePos++;
					flag2 = 0;
				}
					else{
					mvprintw(21, sentencePos1, "%s", wordlist[p]);
					wordSizes[sentencePos] = strlen(wordlist[p]);
					sentencePos1 += wordSizes[sentencePos];
					sentencePos++;
				}}
					
				refresh();
			}
			
			if(cross == 1) //To delete the previous word
			{
				sentencePos--;
				for(int l = 0; l < wordSizes[sentencePos]; l++)
				{
					sentencePos1--;
					mvprintw(21, sentencePos1, " ");	
				}				
				wordSizes[sentencePos] = 0;	
				refresh();
			}

			if(cir ==1) //To capitalize the first letter of the next word
				flag2 = 1;

			if(rjpress == 1) //To clear the sentence completely
				for(int l = 0; l < 200; l++)
				{
					wordSizes[l] = 0;
					sentencePos = 0;
					sentencePos1 = 0;
					mvprintw(21, l, " ");
					refresh();
				}
			tNew = time + 250;
		}
		if(sentencePos1 >= 80)
			flag = 0;
	}
	endwin();
	return 0;
}

// DO NOT MODIFY THIS FUNCTION!
void trimws(char* str) {
	int length = strlen(str);
	int x;
	if (length == 0) return;
	x = length - 1;
	while (isspace(str[x]) && (x >= 0)) {
		str[x] = '\0';
		x -= 1;
	}
}


// DO NOT MODIFY THIS FUNCTION!
int read_words(char* WL[MAXWORDS], char* file_name)
{
	int numread = 0;
	char line[WORDLENGTH];
	char *p;
	FILE* fp = fopen(file_name, "r");
	while (!feof(fp)) {
		p = fgets(line, WORDLENGTH, fp);
		if (p != NULL) 
		{
			trimws(line);
			WL[numread] = (char *)malloc(strlen(line) + 1);
			strcpy(WL[numread], line);
			numread++;
		}
	}
	fclose(fp);
	return numread;
}

void draw_character(int x, int y, char use) //The function used to draw the avatar from lab 8
{
    mvaddch(y,x,use);
    refresh();
}