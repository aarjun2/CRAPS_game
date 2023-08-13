
/*
This is the program to play the CRAPS game
Author: Arjun Anand
Filename:functions.c
Description:
The file has the list of all functions implemented for the Craps game.
Each of the functions below is used by the main program to play the game.
*/

#include "definition.h" 

/*
 Function: print_game_rules
 Description: This function prints the game's rule
*/

void print_game_rules(void) {
	printf("Welcome to the famous Craps Game \n\n");
	printf("This is a game of fun and money.. Enjoy the time \n");
	printf("A player rolls two dices. Each dice has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots. \n");
	printf("After the dice have come to rest, the sum of the spots on the two upward faces is calculated. \n");
	printf("If the sum is 7 or 11 on the first throw, the player wins. If the sum is 2, 3, or 12 on the first throw (called craps), the player loses (i.e. the house wins). \n");
	printf("If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's point. To win, player must continue rolling the dice until they make the point again. \n");
	printf(" The player lose if they get a 7 before making the point.\n\n");
}

/*
 Function: get_bank_balance
 Description: This function asks for the bank balance to the user. The accepted bank balance is sent back to the requested function
*/
double get_bank_balance(void) {
	double player_initial = 0.0;
	int getamount = 1;
	while (getamount)
	{
		printf("Enter your bank balance - How much do you want to start with? \n");
		scanf("%lf", &player_initial);
		if (player_initial > 0) {
			getamount = 0;
		}
		else
		{
			printf("Bank balance cannot be negative or zero \n");
		}
	}
	return player_initial;
}

/*
 Function: get_wager_amount
 Description: This function asks for the wager balance to the user. The accepted wager amount is sent back to the requested function
*/
double get_wager_amount(void) {
	double player_wager = 0.0;
	int getamount = 1;
	while (getamount)
	{
		printf("Enter the wager amount - How much do you want to wager this round? \n");
		scanf("%lf", &player_wager);
		if (player_wager > 0) {
			getamount = 0;
		}
		else
		{
			printf("Wager amount cannot be negative or zero \n");
		}
	}
	return player_wager;
}

/*
 Function: check_wager_amount
 Description: This function checks if the wager amount is greater than balance. if so, it informs the calling functional accordingly
*/
int check_wager_amount(double wager, double balance) {
	int value = 1;
	// if wager amount is greater than balance, inform the caller accordingly
	if (wager > balance) {
		value = 0;
	}
	return value;
}

/*
 Function: roll_dice
 Description: This function generates the random number to identify the roll in a dice
*/
int roll_dice(void) {
	return rand() % 6 + 1;
}

/*
 Function: calculate_sum_dice
 Description: This function calculates the sum of the dice values
*/
int calculate_sum_dice(int dice1_value, int dice2_value) {
	int sum_dice = 0;
	sum_dice = dice1_value + dice2_value;
	return sum_dice;
}

/*
 Function: is_win_loss_or_point
 Description: This function decides if the roll is a win or lose in the first roll
*/
int is_win_loss_or_point(int sum_dice) {
	// if its 7 or 11 in the first roll, its a win
	if (sum_dice == 7 || sum_dice == 11) {
		return 1;
	}
	// if its 2 or 3 or 12 in the first roll, its a lose
	if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12) {
		return 0;
	}
	// if not win or lose, set the roll value as the points
	else {
		player_points = sum_dice;
		return -1;
	}
}

/*
 Function: is_point_loss_or_neither
 Description: This function decides if the roll is a win or lose in subsequent rolls
*/
int is_point_loss_or_neither(int sum_dice, int point_value) {
	// if the player hits the point value from the rolled dice, then it's a win
	if (sum_dice == point_value) {
		return 1;
	}
	// if the player hits the value 7 from the rolled dice, then it's a lose
	if (sum_dice == 7) {
		return 0;
	}
	else {
		return -1;
	}
}

/*
 Function: adjust_bank_balance
 Description: This function adjust the bank balance depending on win or lose. if its a win, bank balance is increased. if its a lose, then the wager is deducted from the bank balance
*/
double adjust_bank_balance(double wager_amount, double bank_balance , int add_or_subtract) {
	// if win, increase the bank balance
	if (add_or_subtract == 1) {
		bank_balance = wager_amount + bank_balance;
	}
	// if lose, decrease the bank balance
	else if (add_or_subtract == 0) {
		bank_balance = bank_balance - wager_amount;
	}
	return bank_balance;
}

/*
 Function: chatter_messages
 Description: This function is a helper function to print different messages while playing the craps game
*/
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance) {
	if (number_rolls == 1 && win_loss_neither == 1) {
		printf("\n congratulations, your bank balance is : %.2f\n", current_bank_balance);
		return;
	}
	if (number_rolls == 1 && win_loss_neither == 0) {
		printf("\n Sorry, you lost, your bank balance is : %.2f\n", current_bank_balance);
		return;
	}
	if (number_rolls > 1 && win_loss_neither == 1) {
		printf("\n good job, you won in %d rolls and final balance is %.2f \n", number_rolls, current_bank_balance);
		return;
	}
	if (number_rolls > 1 && win_loss_neither == 0) {
		printf("\n tough luck, you lost in %d rolls and final balance is %.2f \n", number_rolls, current_bank_balance);  
		return;
	}    
	if (number_rolls > 5) {
		printf("\n i like your energy. You are in roll %d. your balance is: %.2f  \n", number_rolls, current_bank_balance);
		return;
	}
	if (number_rolls <= 5) {
		printf("\n Keep playing. You are in roll %d. Wishing you the best and your balance is: %.2f  \n", number_rolls, current_bank_balance);
		return;
	}
}