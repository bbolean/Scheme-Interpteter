#ifndef __CONSTANTS_
#define __CONSTANTS_

bool is_integer(char *number);
int get_int(char *number);
void execute_constant(char *command);
bool is_real(char *real);
double get_real(char *real);
bool is_rational(char *rational);
int get_nominator(char *rational);
int get_denominator(char *rational);
bool is_list(char *command);


#endif