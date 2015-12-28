#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <readline/readline.h>
#include <readline/history.h>

#include "constants.h"

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
	if(is_rational(command)) printf("rational number %s\n", command); 

}