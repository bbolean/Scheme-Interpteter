#include <stdlib.h>

#include "tools.h"

/* Function: gcd(int a,int b)
 * Takes integer arguments a and b
 * and returns their greatest commmon 
 * divisor */
int gcd(int a,int b)
{
	if(a == 0) return b;
	return gcd(b % a,a);
}

/* Function: remove_spaces(char *line)
 * Takes one argument line, removes all preceding
 * spaces and returns pointer to the first
 * non space character or NULL if such 
 * character doesn't exist
 */
char *remove_spaces(char *line)
{	
	/* skipp all spaces */
	while(*line == ' ' && *line != '\0') line++;

	/* check if there is any character left */
	if(line != '\0') return line;

	return NULL;
}

char *move_to_next_space(char *data)
{
	while(*data != ' ') data++;

	return data;
}