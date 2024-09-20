/*----------------------------------------------------------------------------
- SE 185: Midterm Project -
- List the names of all team members, their roles, and their participation
1- Alejandro Perez  - Role: Quiz Creator and debugger - Participation: 50%
(Use this line to describe your contribution to the project)
2- Alvin Thomas - Role: Quiz Creator and debugger - Participation: 50%
(Use this line to describe your contribution to the project)
3-
4-
5-
-
-----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
- Includes
-
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*----------------------------------------------------------------------------
- Functions Prototypes
-
-----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
- Notes -
-----------------------------------------------------------------------------*/
// Compile with gcc midtermProject.c -o proj
/*----------------------------------------------------------------------------
- Implementation
-
-----------------------------------------------------------------------------*/
int main(void)
{
	int seed;
	int quizChoice;
	int quizComplete = 0;
	int quizAttempts = 0;
	int totalQuizattempts = 0;
	int currentQuizScore = 0;
	int scores = 0;
	int totalQuizScoresavg = 0; 
	char continueQuiz;
	char userCharInput;
	char userStringInput[20] ;

	printf("Welcome! There are three quizzes.\nQuiz 1\nQuiz 2\nQuiz 3\n");
	printf("Enter a lucky number between 1 and 9 to get a quiz!\n");
    scanf("%d", &seed);
	srand(seed);
	quizChoice = (rand()%3)+1; 

	while(1){
//Quiz 1
if(quizChoice == 1){
	while(quizComplete !=1){
		printf("This is Quiz 1\n");
		printf("\nQuestion 1\nThis is a True or False question\nType T for True and F for False\n");
		printf("True or False:\n Boolean data type can have 5 values.\n");
		printf("Answer: ");
		scanf(" %c", &userCharInput);
		if(userCharInput == 'F' || userCharInput == 'f') {
			printf("Correct!\n");
			currentQuizScore+=5; 
		}else 
			printf("Wrong!\n");
		printf("\nQuestion 2\n"); //Question 2 multiple choice
		printf("Which is a floating data type?\n A. int\n B. short\n C. double\n D. long\n");
		printf("Answer: ");
		scanf(" %c", &userCharInput);
		if(userCharInput == 'C' || userCharInput == 'c'){
			printf("Correct!\n");
			currentQuizScore = currentQuizScore + 5;
		}else
			printf("Wrong!\n");
		printf("\nQuestion 3\n");
		printf("This is a fill in the blank question\n");
		printf("The ______() function is used to generate pseudo random numbers in C\n");
		printf("Answer: ");
		scanf("%s", userStringInput);
if (strcmp("rand", userStringInput) == 0) {
			printf("Correct!\n");
			currentQuizScore = currentQuizScore + 5;
		} else
			printf("Wrong!\n");
quizAttempts++;
		scores+= currentQuizScore;
		totalQuizattempts++;
		totalQuizScoresavg+= currentQuizScore;
		
if(currentQuizScore == 15) {
			printf("You got all questions right\n");
			printf("It took you %d tries with an average score of %.2lf%%\n", quizAttempts, ((100.0*scores)/(15.0*quizAttempts)));
			quizComplete = 1;
		}else  
			printf("You failed the Quiz. Try again\n");
		currentQuizScore = 0;
	}
	scores = 0;
	quizAttempts = 0;
	quizChoice = 0;

//Quiz 2
}else if(quizChoice == 2){ 
		while(quizComplete !=1){
		printf("This is Quiz 2\n");
		printf("\nQuestion1\nThis is a True or False question\nType F for False and T for True\n");
		printf("True or False:\n123jumps is a valid variable name.\n");
		printf("Answer: ");
		scanf(" %c", &userCharInput);
		if(userCharInput == 'F' || userCharInput == 'f') {
			printf("Correct!\n");
			currentQuizScore += 5; 
		}else
			printf("Wrong!\n");
		printf("\nQuestion 2\n"); //Question 2 multiple choice
		printf("Which is not a logical operator?\n A. !\n B. =\n C. &&\n D. ||\n");
		printf("Answer: ");
		scanf(" %c", &userCharInput);
		if(userCharInput == 'B' || userCharInput =='b'){
			printf("Correct!\n");
			currentQuizScore += 5;
		}else
			printf("Wrong!\n");
		printf("\nQuestion 3\n"); //Question 3 fill in the blank
		printf("This is a fill in the blank question\n");
		printf("The ______() function is used to print output in C\n");
		printf("Answer: ");
		scanf("%s", userStringInput);
		if (strcmp("printf", userStringInput) == 0) {
			printf("Correct!\n");
			currentQuizScore += 5;
		}else
			printf("Wrong!\n");
		quizAttempts++;
		scores += currentQuizScore;
		totalQuizattempts++;
		totalQuizScoresavg+= currentQuizScore;

		if(currentQuizScore == 15){
			printf("You got all questions right\n");
			printf("It took you %d tries with an average score of %.2f%%\n", quizAttempts, ((100.0*scores)/(15.0*quizAttempts)));
			quizComplete = 1;
		}else 
			printf("You failed the Quiz. Try again\n");
		currentQuizScore = 0;
        }
	scores = 0;
	quizAttempts = 0;
	quizChoice = 0;
	}
//Quiz 3
else{
while(quizComplete != 1){
		printf("This is Quiz 3\n");
		printf("\nQuestion1\n This is a True or False question\nType F for False and T for True\n");
		printf("True or False:\n The data type short can be used to store phone numbers.\n");
		printf("Answer: ");
		scanf(" %c", &userCharInput);
		if (userCharInput == 'F' || userCharInput == 'f') {
			printf("Correct!\n");
			currentQuizScore+=5; 
		}else
			printf("Wrong!\n");
		printf("\nQuestion 2\n"); //Question 2 multiple choice
		printf("Which cannot be a variable name in C?\n A. true\n B. hello\n C. goodbye\n D. life\n");
		printf("Answer: ");
		scanf(" %c", &userCharInput);
		if(userCharInput == 'A'){
			printf("Correct!\n");
			currentQuizScore+=5;
		}else
			printf("Wrong!\n");
		printf("\nQuestion 3\n"); //Question 3 fill in the blanks
		printf("This is a fill in the blank question\n");
		printf("The ______ datatype is used to store true or false values in C\n");
		printf("Answer: ");
		scanf("%s", userStringInput);
		if (strcmp("bool", userStringInput) == 0) {
			printf("Correct!\n");
			currentQuizScore+=5;
		}else
			printf("Wrong!\n");
		quizAttempts++;
		scores +=currentQuizScore;
		totalQuizattempts++;
		totalQuizScoresavg+=currentQuizScore;
		
		if(currentQuizScore == 15){
			printf("You got all questions right\n");
			printf("It took you %d tries with an average score of %.2lf%%\n", quizAttempts, ((100.0*scores)/(15.0*quizAttempts)));
			quizComplete = 1;
		}else
			printf("You failed the Quiz. Try again\n");
		currentQuizScore = 0;
	}
	scores = 0;
	quizAttempts = 0;
	quizChoice = 0;
}
//Asks the user if they want to take another quiz or quit the program. When they choose to quit it gives the average quiz score and number of attempts.
printf("Would you like to take another quiz? Input Y or N:\n");
scanf(" %c", &continueQuiz);
if(continueQuiz == 'Y' || continueQuiz == 'y'){
	printf("Enter a lucky number between 1 and 9 to get a quiz!\n");
    scanf("%d", &seed);
	srand(seed);
	quizChoice = rand()%3+1;
	continueQuiz='n';
	quizComplete = 0;
}else{
	printf("You took %d quizzes with an average score of %.2lf%%.", totalQuizattempts, ((100.0*totalQuizScoresavg)/(15.0*totalQuizattempts)));
	break;
}}
return 0;
}
/* Put your functions here, and be sure to put prototypes above. */