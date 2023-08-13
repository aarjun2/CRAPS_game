#include "definition.h" 
/*
This is the program to play the CRAPS game
Author: Arjun Anand
Filename: main.c
Description:
The program takes the bank balance and wager amount from the player. It uses 2 dices to play the game. The bank balance increases when player wins the game and decreases when player lose the game.
The program displays the menu items with options to iterate through the game. The options include displaying the bank balance and game rules
The program uses the srand library for random number generator
*/

int main(void) {

	// Initialize all the required variables
	double bank_balance = 0.0, player_wager = 0.0, check_wager = 0.0;
	int option = 0, dice1 = 0, dice2 = 0, sum_dice = 0, proceed = 1, is_point_loss = -1, initial_balance = 0, roll = 0, win_or_loss = 0, skip = -1;
	player_points = 0;

	// setup the library for random number generator
	srand((unsigned int)time(NULL)); // call only once PERIOD 

	// The program will keep showing the menu items until the player selects the option-4 (Exit the game)
	while (proceed == 1) {
		printf("\n choose an option between 1 and 4\n"); 
		printf("option 1: diplay rules\n"); 
		printf("option 2: Display bank balance\n");
		printf("option 3: play game\n");
		printf("option 4: exit game\n");
		scanf("%d", &option);

		// Decide the actions based on the option selected
		switch (option) // option has to be 1 - 4
		{
		case 1:
			print_game_rules();// print the rules
			break;

		case 2: // get the current bank balance  
			printf("\n current bank balance: %.2f\n", bank_balance);
			break;

		case 3: // play the Craps Game

			// get the bank balance and wager from the player 
			bank_balance = get_bank_balance();
			initial_balance = bank_balance;
			player_wager = get_wager_amount();

			// no need to play if the balance is not greater than 0
			if (bank_balance > 0) {
				check_wager = check_wager_amount(player_wager, bank_balance);
				if (check_wager == 0) {
					printf("\n you cannot place wager, insufficient balance \n");
					break;
				} 

				// Roll the dices
				dice1 = roll_dice();
				dice2 = roll_dice();
				sum_dice = calculate_sum_dice(dice1, dice2);
				roll = 1;

				// if the player gets 7 or 11, player wins in the first roll
				win_or_loss = is_win_loss_or_point(sum_dice);
				if (win_or_loss == 1) {
					bank_balance = adjust_bank_balance(player_wager, bank_balance, win_or_loss);
					chatter_messages(roll, win_or_loss, initial_balance, bank_balance);
					break;
				}

				// If the sum is 2, 3, or 12 on the first throw, its a lose
				if (win_or_loss == 0) {
					bank_balance = adjust_bank_balance(player_wager, bank_balance, win_or_loss); 
					chatter_messages(roll, win_or_loss, initial_balance, bank_balance);
					break;
				}
				else {
					printf("\n you got %d points. Keep Playing \n", player_points);
					do {
						// get the wager from the player for every roll
						player_wager = get_wager_amount();
						check_wager = check_wager_amount(player_wager, bank_balance);
						if (check_wager == 0) {
							printf("\n you cannot place wager, insufficient balance \n");
							break;
						}

						// roll the dices, calculate sum and find if its a lose or win. If its neither win or lose, take the roll's sum as points
						dice1 = roll_dice();
						dice2 = roll_dice();
						sum_dice = calculate_sum_dice(dice1, dice2);
						is_point_loss = is_point_loss_or_neither(sum_dice, player_points);

						// keep track of the rolls - will be used for chatter messages
						roll = roll + 1;
						chatter_messages(roll, skip , initial_balance, bank_balance); 
					} while (is_point_loss == -1);

					// if its a lose or win, adjust the bank balance accordingly
					if (is_point_loss == 0) {
						bank_balance = adjust_bank_balance(player_wager, bank_balance, is_point_loss);
						chatter_messages(roll, is_point_loss, initial_balance, bank_balance);
					}
					if (is_point_loss == 1) {
						bank_balance = adjust_bank_balance(player_wager, bank_balance, is_point_loss);
						chatter_messages(roll, is_point_loss, initial_balance, bank_balance);
					}
				}
			}
			break;

		case 4: // exit the program. Player need to enter "4" to exit the program
			proceed = 0;
			break;

		default:  // If player types in any option other than 1,2,3,4  keep looping in the game to get the valid option
			proceed = 1;
		}
	}
	return 0;
}