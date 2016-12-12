#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  // for printf
#include <stdlib.h> // for system("pause");
#include <string.h> // For string functions

/*
 Main function drives the program.
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    IF the program exits correctly THEN 0 ELSE 1
 */
int main(void) {

	char * empty_string;
	char a_long_string[128] = "These ";

	strcat(a_long_string,"strings ");

	strcat(a_long_string,"are ");

	strcat(a_long_string,"concatenated!");

	empty_string = strcat(a_long_string, " We can add more like this!");

	printf("%s\n", empty_string);
	return 0;
}
