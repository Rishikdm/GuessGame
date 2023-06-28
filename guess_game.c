/*	Algorithm and C program for mini game - "Guess Game", secure programming.
* 
* Algorithm
*	
*	1. Start the program.
*	2. Declare function game, containing main code of Guess Game and function check, to check if guess is true.
*	3. Start main function.
*	4. Call function game.
*	5. Start the game function.
*	6. Declare constant integer 'maxattempts' and set it's value.
*	7. Declare integer variables answer, guess, and character variables input.
*	8. Start loop
*	9. Define value of answer as zero and guess.
*	10. Display Welcome and other related message.
*	11. Prompt for input from user and display number of attempts.
*	12. Read the input using fgets and store it in input variable.
*	13. Validate the input variable, if invalid, display error message and end the program.
*	14. Convert and store char variable input into integer variable answer using atoi.
*	15. Check if answer is real number, if not, display error message and prompt to enter again.
*	16. To check if answer is correct, call function check by call by reference.
*	17. Start check function.
*	18. Check if answer is equal to guess, if yes then return true.
*	19. To provide hint, check if answer is greater then guess, if yes then display high, else low.
*	20. Return false.
*	21. If check function is true, display congratulation message and return.
*	22. If check functin returns false and total attempts is less than maxattempts then continue.
*	23. Else display message for incorrect answer showing the guess value.
*	24. Display message if user wants to play again.
*	25. Read the message using fgets, validate it.
*	26. If input value is false, display error.
*	27. If input value is no, then exit the program.
*	28. If input value is yes, then iterate loop.
*	29. End the program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <stdbool.h>

//Function declaration
bool check(int guess, int answer);	//checks if answer entered is equal to guess or not, and provide hints according it.
void game(void);	//main game program.

//start of main function.
int main(void) {
	srand((unsigned int)time(0));	
	game();
	return 0;
}	//main function ends here.

//start of function game.
void game() {

	const int maxattempt = 10;
	int answer, ans, guess;
	char input[10];

	do
	{
		answer = 0;
		guess = 1 + rand() % 100;	//random number generator in 1-100.

		//Display Game information.
		puts("\n\tWelcome to Guess Game!!\n");
		puts("Guess random numbers between 1 to 100.");
		puts("You will be provided with ten attempts to guess the correct Answer.");

		for (int i = 0; i < maxattempt; i++) {
			
		
			printf("Enter the guess ( %d Attempts left ) :\t", maxattempt - i);
			
			
			if (fgets(input, sizeof(input), stdin) == NULL) {	//check of input array is valid.
				puts("Input error, exiting the program ");
				return;
			}


			answer = atoi(input);	//char to int conversion

			if (answer == 0) {	//check if variable is real number / is digit.
				
				puts("Invalid entry. Enter a number");
				i--;
				continue;
			}

			if (check(guess, answer)) {	//check function, call by reference
				printf("\t\tCongratulations!!\n\t\tYour Won.\n\t\tVictory by %d attempts.\n", maxattempt - i);
				break;
			}
			else if ( i < maxattempt) {
				continue;
			}
			else
			{
				printf("Incorrect answer, Guess is %d.\n", guess);
			}
		}

			puts("Do you want to try again.	(Press 1 for yes, 0 for no.)");
			
			
			if (fgets(input, sizeof(input), stdin) == NULL) {
				puts("Input error, exiting the program.");
				return;
			}

			ans = atoi(input);

			if (ans != 0 && ans != 1) {
				puts("Invalid entry.");
				return;
			}

			puts("");


	} while (ans == 1);
}

//start of check function.
bool check(int guess, int answer) {

	if (guess == answer) {	//check if equal.
		return 1;	//return true (1 = true).
	}
	else if (guess > answer) {
		puts("Low, try again.\n");
	}
	else
	{
		puts("Hight, try again.\n");
	}
	return 0;	//return false (0  = false).

}