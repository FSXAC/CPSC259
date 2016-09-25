/*
 File:				lab2_in-lab_exercises.c
 Purpose:			Exercises for lab 2
 Author:			Your names
 Student #s:		12345678 and 12345678
 CS Accounts:		a1a1 and b2b2
 Date:				Add the date here
 */

#include "lab2_in-lab_exercises.h"
#include <stdlib.h>

#define SMALL_ARRAY 25

/*
 Main function drives the program.  Every C program must have one
 main function.  A project will not compile without one.
 PRE:    NULL (no pre-conditions)
 POST:	 NULL (no side-effects)
 RETURN: IF the program exits correctly
		 THEN 0 ELSE 1
 */
int main ( void )
{
	/* We start every function with a list of variables */
	int i = 0;
	int * pointer_to_some_ints;

	/* Then we do things, like invoke functions and assigns their return 
	   values to variables.  You don't need to change these two lines */
	pointer_to_some_ints = ( int * ) malloc( SMALL_ARRAY * sizeof( int ) );
	for ( i = 0; i < SMALL_ARRAY; ++i ) {
		*( pointer_to_some_ints + i ) = i;
	}

	// You can set a breakpoint here later in order to test the debugger 'watch' tab for pointers

	/* The system command forces the system to pause before closing executable window */
	system("pause");
	return 0;
}

/* 
 * Let's start with something easy.  There are 3 unit tests
 * for this function.
 *
 * Swaps the contents of two integer variables using pointers
 *
 * PARAM:     first_int is a pointer to an int
 * PARAM:     second_int is a pointer to an int
 * PRE:       both pointers are valid pointers to int
 * POST:      the contents of two integer variables are swapped
 * RETURN:    VOID
 */
void swap_ints( int * first_int, int * second_int )
{
	// Insert your code here
    int temporary = *first_int;
    *first_int = *second_int;
    *second_int = temporary;
}

/* 
 * Now let's try something a little more challenging.
 *
 * Reverses the contents of the string passed to the
 * function.  Does not move the terminating null '\0'
 * character.
 *
 * PARAM:     string is a pointer to an array of char (a string)
 * PRE:       the array of char terminates with a null '\0'
 * POST:      the char array has been reversed
 * RETURN:    VOID
 */
void reverse_string( char * string )
{
    int length = 0;
    int index = 0;
    char temp;

    // get the length of the string first
    while ((*(string + length) != '\0')) {
        length++;
    }

    // use for loop to reverse
    for (; index < length / 2; index++) {
        temp = *(string + index);
        *(string + index) = *(string + length - index - 1);
        *(string + length - index - 1) = temp;
    }
}

/* 
 * Let's see how well you read the lab document.
 *
 * Determines if candidate contains sample, and returns
 * 1 if  it does, and 0 if it does not.
 *
 * PARAM:     candidate is a pointer to an array of char (a string)
 * PARAM:     sample is a pointer to an array of char (a string)
 * PRE:       the arrays of char terminate with a null '\0'
 * PRE:       candidate != NULL; sample != NULL
 * POST:      N/A
 * RETURN:    IF candidate contains sample THEN 1
 *            ELSE 0.
 */
int contains_sample( char * candidate, char * sample )
{
    int index = 0;
    int subindex = 0;

    // check if both is empty string
    if (*candidate == '\0' && *sample == '\0') return 1;

    while (*(candidate + index) != '\0') {
        if (*(candidate + index++) != *(sample + subindex++)) {
            subindex = 0;
        }

        // reached the end of sample char array without resetting
        if (*(sample + subindex) == '\0') {
            return 1;
        }
    }
    return 0;
}

/* 
 * Returns the first index where sample is located inside the
 * candidate.  For example:
 * IF candidate = "Hello", sample = "Hello", RETURNS 0
 * IF candidate = "soupspoon", sample = "spoon", RETURNS 4
 * IF candidate = "ACGTACGTA", sample = "CGT", RETURNS 1
 * IF candidate = "CGTACGTA", sample = "CGTT", returns -1
 *
 * PARAM:     candidate is a pointer to an array of char (a string)
 * PARAM:     sample is a pointer to an array of char (a string)
 * PRE:       the arrays of char terminate with a null '\0'
 * POST:      N/A
 * RETURN:    IF candidate contains sample
 *            THEN the index where the first letter of sample is inside candidate
 *            ELSE -1.
 */
int find_index( char * candidate, char * sample )
{
    // basically the same as before

    int index = 0;
    int subindex = 0;

    // check if both is empty string
    if (*candidate == '\0' || *sample == '\0') return 0;

    while (*(candidate + index) != '\0') {
        if (*(candidate + index++) != *(sample + subindex++)) {
            subindex = 0;
        }

        // reached the end of sample char array without resetting
        if (*(sample + subindex) == '\0') {
            return (index - subindex);
        }
    }
	return -1;
}