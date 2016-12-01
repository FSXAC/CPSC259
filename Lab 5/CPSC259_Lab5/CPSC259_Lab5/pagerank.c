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
int charsInString(char * string, char sample);
double ** parseMatrix(FILE * webfile, int size);
void printMatrix(mxArray *matrix, int size);
void printMatrixPt(double **matrix, int size);

/* Main function */
int main(void) {
  FILE *webfile          = NULL;
  Engine *engPointer     = NULL;
  mxArray *connectMat    = NULL;
  double **connectMatrix = NULL;
  int websize;

  /* File read */
  if (fopen_s(&webfile, FILE_LOCATION, "r")) {
    fprintf(stderr, "Unable to open file: %s\n", FILE_LOCATION);
    END(1);
  }

  /* Need to read and parse data in file to an array */
  if (webfile) {
    // get size of matrix
    websize = getNumOfLinks(webfile);

    // parse to 2D array
    connectMatrix = parseMatrix(webfile, websize);

    // start matlab engine process
    if (!(engPointer = engOpen(NULL))) {
      fprintf(stderr, "\nCannot start MATLAB engine\n");
      END(1);
    }

    // create array
    connectMat = mxCreateDoubleMatrix(websize, websize, mxREAL);

    // copy connect matrix into a memory
    memcpy(
      (void *)mxGetPr(connectMat),
      (void *)connectMatrix,
      websize * websize * sizeof(double)
    );

    // copy matrix into MATLAB engine
    if (engPutVariable(engPointer, "connectMat", connectMat)) {
      fprintf(stderr, "\nCannot write connect matrix to MATLAB\n");
      END(1);
    }

    // let MATLAB do its thing



  } else {
    fprintf(stderr, "Null file pointer error: %s\n", FILE_LOCATION);
    END(1);
  }

  END(0);
}

int rankpages(Engine * engPointer) {
  // get column sum
  if (engEvalString(engPointer, "columnSum = sum(connectMat)")) {
    fprintf(stderr,"\nError calculating eigenvalues\n");
    END(1);
  }

  return 0;
}

/* Returns number of links in the connectivity matrix (dimension)
 * PARAM: File pointer to the file
 */
int getNumOfLinks(FILE * webfile) {
  char line_buffer[BUFFER];

  // read the first line
  fgets(line_buffer, BUFFER, webfile);
  fseek(webfile, 0, SEEK_SET);

  // return length of line - total white space - 1
  return (int) strlen(line_buffer) - charsInString(line_buffer, ' ') - 1;
}

/* Returns the number of character occurances in a string
 * PARAM: character pointer to the string
 * PARAM: character to check for
 */
int charsInString(char * string, char sample) {
  int count;

  // while string[count] is not NULL
  // if string[count] is sample, count++ and move on to the next letter
  // if not, *string++ which is equivalent to count++ without incrementing count
  for (count = 0; string[count]; string[count] == sample ? count++ : *string++);
  return count;
}

/* Returns a 2D pointer to the matrix of the parsed connect matrix
 * PARAM: webfile - the file pointer to the file
 * PARAM: size - size of matrix
 * FILE(example):  0 0 1 1 0 1 1
 *         index:  012345789ABCD
 */
double ** parseMatrix(FILE * webfile, int size) {
  // for reading file
  char line_buffer[BUFFER];
  int row = 0, column = 0;
  double **webmatrix = NULL;

  // allocate memory for 2D array
  // allocating row
  webmatrix = (double **)malloc(size * size * sizeof(double));

  // allocating column for each row
  for (; row < size; row++) {
    webmatrix[row] = (double *)malloc(size * sizeof(double));
  }

  // copies web txt data to memory
  row = 0;
  while (fgets(line_buffer, BUFFER, webfile)) {
    for (column = 0; column < size; column++) {
      // column * 2 to account for whitespace
      webmatrix[row][column] = line_buffer[column * 2] - '0';
    }
    row++;
  }

  // print initial connect matrix
  printMatrixPt(webmatrix, size);

  return webmatrix;
}

/* Prints matrix
 * PARAM: the matrix in mxArray form of matlab
 */
void printMatrix(mxArray *matrix, int size) {
  size_t i, j;
  for(i = 0; i < size; i++) {
    for (j = 0; j < size; j++) printf("%-8.4f", mxGetPr(matrix)[i * size + j]);
    printf("\n");
  }
}

/* Prints matrix
 * PARAM: the matrix in pointers
 */
void printMatrixPt(double **matrix, int size) {
  unsigned short int i, j;
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) printf("%-8.4f", matrix[i][j]);
    printf("\n");
  }
}
