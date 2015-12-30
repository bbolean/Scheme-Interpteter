#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "list.h"
#include "tools.h"

/* Function: list_init(struct List *list)
 * Takes one argument, pointer to List type list,
 * and initializes it by pointing it to NULL 
 */
void list_init(struct List *list)
{
	list = NULL;
}

/* Function: list_add(struct List *list,char *data)
 * Takes two arguments, parses data and keeps elements 
 * described in data into the list linked-list.
 * returns number of elements added in list or -1
 * on error */
struct List* list_add(struct List *list,char *data)
{	
	/* create head and tail pointers of list */
	struct List *head = NULL;
	struct List *tail = NULL; 
	 
	while(true)
	{	
		/* remove precedding spaces */
		data = remove_spaces(data);
		/* check if nothing has left */
		if(data == NULL) return head;

		/* check if list is finished */
		if(*data == ')') return head;

		struct List *next = malloc(sizeof(struct List));

		/* handling very concrete case here, needs to be generalized */
		next->type = integer;
		next->addr = malloc(2);
		strncpy(next->addr,data,1);
		next->addr[1] = '\0';
		next->next = NULL;
		

		if(head == NULL) 
		{
			head = next;
			tail = next;
		} else {
			tail->next = next;
			tail = next;
		}		

		/* move to next entry described in data */
		data = move_to_next_space(data);
	}


	 
	return head;
}