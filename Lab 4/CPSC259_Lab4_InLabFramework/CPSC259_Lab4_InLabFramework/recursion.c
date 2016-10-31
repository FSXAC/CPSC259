/*
 File:              recursion.c
 Purpose:           Exercises for CPSC259 lab 4
 Author:			Your names
 Student #s:		12345678 and 12345678
 CS Accounts:		a1a1 and b2b2
 Date:				Add the date here
 */

/******************************************************************
 PLEASE EDIT THIS FILE

 Comments that start with // should be replaced with code
 Comments that are surrounded by * are hints
 ******************************************************************/


/* Preprocessor directives */
#include <stdio.h>
#include <stdlib.h>
#include "recursion.h"

/*
 Main function drives the program.
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    IF the program exits correctly
            THEN 0 ELSE 1
 */
int main (void)
{
	printf("Testing output from draw_ramp() function:\n");
	printf("\ndraw_ramp(1):\n");
	draw_ramp(1);
	printf("\ndraw_ramp(2):\n");
	draw_ramp(2);
	printf("\ndraw_ramp(3):\n");
	draw_ramp(3);
	printf("\ndraw_ramp(4):\n");
	draw_ramp(4);
	printf("\ndraw_ramp(5):\n");
	draw_ramp(5);
	system("pause");
	return 0;
}

/*
 Calculates the power.
 PARAM:     base is an integer
 PARAM:     power is an integer
 PRE:       power >= 0
 PRE:       base != 0
 RETURN:    base^power
 */
int calculate_power(int base, int power)
{
  // start with product being 1
  int product = 1;


  if (power > 0 && base != 0) {
    product = base * calculate_power(base, power - 1);
  }

  return product;
}

/*
 Returns the number of digits in an integer
 PARAM:     number is an integer
 PRE:       0 < number <= INT_MAX
 RETURN:    the number of digits in the number
 */
int count_digits(int number)
{
  int digit = 1;
	if (number / 10 > 0){
    digit += count_digits(number / 10);
  }
  return digit;
}

/*
 Returns the length of the specified string.
 PARAM:  string, a pointer to an array of char
 PRE:    the string pointer is not a dangling pointer
 RETURN: the length of the string passed as a parameter
 */
int string_length( char * string )
{
  int i = 0;
  if (*string != '\0') {
    i += 1 + string_length(string+1);
  }
  return i;
}

/*
 Determines if a string is a palindrome.  DOES NOT skip spaces!
 For example,
 ""     -> returns 1 (an empty string is a palindrome)
 "the"  -> returns 0
 "abba" -> returns 1
 "Abba" -> returns 0
 "never odd or even" -> returns 0
 PARAM:  string, a pointer to an array of char
 PARAM:  string_length, the length of the string
 PRE:    the string pointer is not a dangling pointer
 PRE:    string_length is the correct length of the string
 RETURN: IF string is a palindrome
         THEN 1
		 END 0
 */
int is_palindrome(char * string, int string_length)
{
	// int i = 1;
  // if (string_length == 0)
  //   return 1;
  // else if (*string == *(string + string_length - 1) && string_length!=0)
  //   i = is_palindrome(string + 1, string_length - 2);
  // else {
  //   return 0;
  // }
  // return i;

  int isPalindrome = 1;
  if (string_length <= 1) return 1;
  else if (*string == string[string_length - 1])
    isPalindrome *= is_palindrome(string + 1, string_length - 2);
  else return 0;
  return isPalindrome;
}

/*
 Draws a ramp.  The length of the longest rows is specified by the parameter.
 PARAM:     number, an integer
 PRE:       number >= 1
 POST:      draws a ramp whose height is the specified number
 */
void draw_ramp( int number )
{
  draw_row(number);
  if (number > 1) draw_ramp(number - 1);
  draw_row(number);
}

/*
 Draws a row of asterisks of the specified length
 PARAM: size, an integer
 PRE:   size >= 1
 POST:  prints a row of asterisks of specified length to standard output
 */
void draw_row( int size )
{
  printf("%c", '*');
  if (size > 1) draw_row(size - 1);
  else printf("\n");
}
