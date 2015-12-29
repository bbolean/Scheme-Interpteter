#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <readline/readline.h>
#include <readline/history.h>

#include "constants.h"
#include "command.h"
#include "tools.h"

void execute_constant(char *command);
void execute_command(char *command);

/* main running program. Receives scheme commands
 * and executes them.
 */
int main(int argc,char **argv)
{	

	printf("%s\n", "Welcome to Scheme Interpreter!");

	while(true)
	{	
		/* get next command */
		char *command = readline( ":: > " );
			
		/* check if command is some constant value */
		if(*command != '(')
		{	
			execute_constant(command);
		}
		else
		{
			execute_command(command);
		}
	}

	return 0;
}

/* Function: execute_constant(char *command)
 * This function takes one argument, which is constant value,
 * checks its type and calls proper function to execute command. 
 */
void execute_constant(char *command)	
{	
	
	/* check if command is string constant */
	if(*command == '"')	printf("string : %s\n", command);

	/* check if command is boolean constant */
	if(strcmp(command,"#t") == 0 || strcmp(command,"#f") == 0) printf("boolean : %s\n", command);

	/* check if command is character constant */
	if(*command == '#' && *(command + 1) == '\\') printf("character : %s\n", command);

	/* check if command is integer constant */
	if(is_integer(command)) printf("integer constant %d\n",get_int(command));

	/* check if command is real number */
	if(is_real(command)) printf("real number %f\n",get_real(command));

	/* check if command is rational */
	if(is_rational(command)) {
		int nominator = get_nominator(command);
		int denominator = get_denominator(command);
		int g = gcd(nominator,denominator);

		if(g < denominator)
			printf("rational number %d / %d \n", nominator / g, denominator / g);
		else printf("rational number %d\n", nominator / g);
	}

	/* check if command is list */
	if(is_list(command)) printf("list %s\n", (++command));

}

void execute_command(char *command)
{
	/* skip '(' character*/
	command++;

	/* check if command is car */
	if(strncmp(command,"car",3) == 0)
	{
		execute_car(command);
	}

	/* check if command is cdr */
	if(strncmp(command,"cdr",3) == 0)
	{
		execute_cdr(command);
	}
}