#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "command.h"
#include "list.h"

void execute_cdr(char *command)
{
	/* skip cdr command */
	command += 3;
	// TODO: cdr command handling
}

void execute_car(char *command)
{	

	/* skip car command */
	command += 4;

	/* check if car is followed by list*/
	if(strncmp(command,"'(",2) == 0)
	{	
		/* skip "'(" characters*/
		command += 2;

		/* construct list by command */
		struct List *list;
		list_init(list);
		list = list_add(list,command);
		/* print first element from list as car supposes to be */
		printf("first value is : %s\n", list->addr);
	} else printf("%s\n","car must be followed by list" );
}