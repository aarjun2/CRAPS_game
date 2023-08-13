#define _CRT_SECURE_NO_WARNINGS // necessary to ignore scanf_s () warnings 
#define PI 3.14159265 	// defined as a global variable 



#include <stdio.h> 	// necessary to use printf () and scanf () 
#include <math.h>	//necessary to include power and square root functions   
#include <stdlib.h> // rand (), srand ()
#include <time.h> // time ()
int player_points; 

void print_game_rules(void); 
double get_bank_balance(void); 
double get_wager_amount(void); 
int check_wager_amount(double wager, double balance); 
int roll_dice(void); 
int calculate_sum_dice(int dice1_value, int dice2_value); 
int is_win_loss_or_point(int sum_dice); 
int is_point_loss_or_neither(int sum_dice, int point_value); 
double adjust_bank_balance(double  wager_amount, double bank_balance, int add_or_subtract);
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance); 
