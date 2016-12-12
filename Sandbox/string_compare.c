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

	char string1[] = "Hello";
	char string2[] = "Hello";

	if (!strcmp(string1, string2)) printf("%s == %s\n", string1, string2);
	else printf("%s != %s\n", string1, string2);

	return 0;
}
