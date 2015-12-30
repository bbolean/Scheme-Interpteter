#include <stdbool.h>

#include "constants.h"

/* Function: is_integer(char *number)
 * Takes one argument 'number', and checks if it only
 * consists of digits and nothing else. Returns true
 * if so, or false otherwise
 */
bool is_integer(char *number)
{	
	
	while(*number != '\0' && *number != ' ')
	{
		if(*number < '0' || *number > '9') return false;

		number++;
	}

	return true;
}

/* Function: get_int(char *number)
 * Takes one argument, number, which consists of only
 * digits and returns its integer value.
 */
int get_int(char *number)
{	
	/* keep result in this variable */
	int rest = 0;

	while(*number != '\0' && *number != ' ')
	{	
		rest *= 10;
		rest += *number - '0';
		number++;
	}

	return rest;
}

/* Function: is_real(char *real)
 * Tkaes one arguments and check if its
 * real number or not. Returns true or
 * false respectively
 */
bool is_real(char *real)
{

	int num_dots = 0;

	/* check if number consists of only digits and exactly 
	 * one dot */
	while(*real != '\0' && *real != ' ')
	{	
		if(*real == '.')
			num_dots++;
		else 
			if(*real > '9' || *real < '0') return false;
		 
		real++;
	}

	/* check if there was exactly one dot*/
	if(num_dots == 1) return true;
	else return false;
}

double get_real(char *real)
{	
	/* keep two different values, we will sum them
	 * up in the final result */
	double before_dot = 0;
	double after_dot = 0;

	/* iterate before dot */
	while(*real != '.')
	{
		before_dot = before_dot * 10;
		before_dot += *real - '0';
		real++;
	}

	/* skip dot */
	real++;
	
	/* denominator of number */
	double power = 10;

	while(*real != '\0' && *real != ' ')
	{	
		double curr_val = *real - '0';
		after_dot += curr_val / power;
		power *= 10;
		real++;
	}

	/* sum the result */
	return before_dot + after_dot;
}

/* Function: is_rational(char *rational)
 * Takes one argument and checks whether it represents
 * rational number or not.
 */
bool is_rational(char *rational)
{
	int num_slashes = 0;

	while(*rational != '\0' && *rational != ' ')
	{
		if(*rational == '/') num_slashes++;
		else if(*rational < '0' || *rational > '9') return false;

		rational++;
	}

	if(num_slashes == 1) return true;
	return false;
}

/* Function: get_nominator(char *rational)
 * Takes one argument of type a / b, and returns
 * integer value of a
 */
int get_nominator(char *rational)
{
	int rest = 0;
	/* evaluate value before '/' character */
	while(*rational != '/')
	{
		rest *= 10;
		rest += *rational - '0';
		rational++;
	}

	return rest;
}

/* Function: get_denominator(char *rational)
 * Takes one argument of type a / b, and returns
 * integer value of b 
 */
int get_denominator(char *rational)
{	
	/* skip everything before '/' character */
	while(*rational != '/') rational++;
	/* skip '/' character */
	rational++;

	/* evaluate denominator */
	int rest = 0;
	while(*rational != '\0' && *rational != ' ')
	{
		rest *= 10;
		rest += *rational - '0';
		rational++;
	}

	return rest;
}

/* Function: is_list(char *command)
 * Takes one argument and checks whether it 
 * contains list or not. Since is cheme list
 * starts with " ' " we only check this feature 
 */
bool is_list(char *command)
{
	if(*command == '\'') return true;
	return false;
}