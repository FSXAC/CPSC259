/*
 File:              pagerank.c
 Purpose:           Using matlab to calculate page ranks
 Author:			      Muchen He, Yunpeng Liu
 Student #s:		    44638154 and 36001155
 CS Accounts:		    p5h0b and w9t0b
 Date:				      2016-11-21
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "engine.h"

/* Macros */
#define END(x) system("pause"); return x

/* Preprocessor constants */
#define BUFFER 256
#define FBUFFER  128
#define FILE_LOCATION "web.txt"


/* Function prototypes */
int getNumOfLinks(FILE * webfile);

/* Main function */
int main(void) {
  FILE *webfile       = NULL;
  Engine *ep          = NULL;
  mxArray *connectMat = NULL;
  int **connectMatrix = NULL;

  /* File read */
  if (fopen_s(&webfile, FILE_LOCATION, "r")) {
    fprintf(stderr, "Unable to open file: %s\n", FILE_LOCATION);
    END(1);
  }

  /* Need to read and parse data in file to an array */
  if (webfile) {
    // TODO HERE
  } else {
    fprintf(stderr, "Null file pointer error: %s\n", FILE_LOCATION);
    END(1);
  }
}

/* Returns number of links in the connectivity matrix (dimension)
 * PARAM: File pointer to the file
 */
int getNumOfLinks(FILE * webfile) {
  int links = 0;
  char line_buffer[BUFFER];

  // read the first line
  fgets(line_buffer, BUFFER, webfile)

  // get number of links
  links = strlen(line_buffer) - charsInString(line_buffer, ' ');
}

/* Returns the number of character occurances in a string
 * PARAM: character pointer to the string
 * PARAM: character to check for
 */
int charsInString(char * string, char sample) {
  int count = 0;
  for (count = 0; string[count]; string[count] == sample ? count++ ? *string++);
  return count;
}
