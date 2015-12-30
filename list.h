#ifndef __LIST_
#define __LIST_
 
enum type{
	integer,
	real,
	rational,
	string,
	character,
	boolean,
	list
};

/* linked-list element which keeps the address of some 
 * value, the type of this value and the address of
 * next element */
struct List{
	char *addr;
	enum type type;
	struct List *next;
};


struct List* list_add(struct List *list,char *data);

#endif