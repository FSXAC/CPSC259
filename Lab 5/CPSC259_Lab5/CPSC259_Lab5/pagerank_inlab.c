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
#define BUFSIZE 256

/* Function prototypes */
void printMatrix(mxArray *matrix);
void printLocalBuffer(Engine *ep);

// main function
int main_inlab(void) {
  /* Initial variables */
  Engine *ep         = NULL;
  mxArray *testArray = NULL;
  mxArray *result    = NULL;
  double time[3][3]  = {
    {1.0, 2.0, 3.0},
    {4.0, 5.0, 6.0},
    {7.0, 8.0, 9.0}
  };

  /* Initial variables for todo 3 */
  mxArray *matOne   = NULL;
  mxArray *matTwo   = NULL;
  mxArray *matThree = NULL;
  double matrixOne[3][3] = {
    {1.0, 4.0, 7.0},
    {2.0, 5.0, 8.0},
    {3.0, 6.0, 9.0}
  };
  double matrixTwo[3][3] = {
    {2.0, 3.0, 4.0},
    {2.0, 3.0, 4.0},
    {2.0, 3.0, 4.0}
  };

  /* Start a matlab process */
  if (!(ep = engOpen(NULL))) {
    fprintf(stderr, "\nCannot start MATLAB engine\n");
    END(1);
  }

  /*** CHANGED TODO 2 - DISPLAY EIGENVALUES ********************/
  printf("*** TODO 2 ***");
  /* Create 3x3 empty matrix */
  testArray = mxCreateDoubleMatrix(3, 3, mxREAL);

  /* Copy the 'time' 2D array MATLAB 2D array, testArray */
  memcpy((void *)mxGetPr(testArray), (void *)time, 9 * sizeof(double));

  /* Putting variable into MATLAB engine, the copy does not need to be freed from memory */
  if (engPutVariable(ep, "testArray", testArray)) {
    fprintf(stderr, "\nCannot write test array to MATLAB\n");
    END(1);
  }

  /* using matlab engine to get eigenvalues */
  if (engEvalString(ep,"testArrayEigen = eig(testArray)")) {
    fprintf(stderr,"\nError calculating eigenvalues\n");
    END(1);
  }

  /* using the enginegetvariable to retrieve the eigenvector */
  printf("\nRetrieving eigenvalues\n");
  if((result = engGetVariable(ep,"testArrayEigen")) == NULL){
    fprintf(stderr,"\nFail to retrieve eigenvalue vector\n");
    END(1);
  } else {
    size_t sizeOfResult = mxGetNumberOfElements(result);
    size_t i            = 0;
    printf("The eigenvalues are:\n");
    for(i = 0; i < sizeOfResult; i++) printf("%f\n", mxGetPr(result)[i]);
  }

  /*** CHANGED TODO 3 - MATRIX MULTIPLICATION ********************/
  printf("\n\n*** TODO 3 ***\n");
  /* Create 3x3 matrices */
  matOne = mxCreateDoubleMatrix(3, 3, mxREAL);
  matTwo = mxCreateDoubleMatrix(3, 3, mxREAL);

  /* Assign values into empty matrix */
  memcpy((void *) mxGetPr(matOne), (void *)matrixOne, 9 * sizeof(double));
  memcpy((void *) mxGetPr(matTwo), (void *)matrixTwo, 9 * sizeof(double));

  /* Display current matrix */
  printf("FIRST MATRIX: \n");
  printMatrix(matOne);
  printf("SECOND MATRIX: \n");
  printMatrix(matTwo);

  /* Put matrix into matlab */
  if (engPutVariable(ep, "matOne", matOne)) {
    fprintf(stderr, "\nCannot write matOne to MATLAB\n");
    END(1);
  }
  if (engPutVariable(ep, "matTwo", matTwo)) {
    fprintf(stderr, "\nCannot write matTwo to MATLAB\n");
    END(1);
  }

  /* Send a command to do matrix multiplication */
  if (engEvalString(ep, "matrixProduct = matOne' * matTwo'")) {
    fprintf(stderr, "\nCannot do matrix multiplication\n");
    END(1);
  }

  /* Retrieve the product */
  printf("\nRetrieving product of two matrices\n");
  if((result = engGetVariable(ep,"matrixProduct")) == NULL){
    fprintf(stderr,"\nFail to retrieve matrix product\n");
    END(1);
  } else {
    size_t sizeOfResult = mxGetNumberOfElements(result);
    printf("The matrix product is:\n");
    printMatrix(result);
  }

  printLocalBuffer(ep);

  /* done, now free memory */
  mxDestroyArray(testArray);
  mxDestroyArray(result);
  testArray = NULL;
  result    = NULL;
  if (engClose(ep)) {
    fprintf(stderr, "\nFailed to close MATLAB engine\n");
  }

  /* exit */
  END(0);
}

void printMatrix(mxArray *matrix) {
  size_t i, j;
  printf("/                                    \\\n");
  for(i = 0; i < 3; i++) {
    printf("|");
    for (j = 0; j < 3; j++) printf("%12.6f", mxGetPr(matrix)[i * 3 + j]);
    printf("|\n");
  }
  printf("\\                                    /\n");
}

void printLocalBuffer(Engine *ep) {
  /* Buffer for capturing MATLAB output */
  char buffer[BUFSIZE + 1];

  /* Capture the output by using local buffer */
  /* Add a null terminating character to string returned by engEvalString */
  printf("\n\n*** LOCAL BUFFER ***\n");
  if (engOutputBuffer(ep, buffer, BUFSIZE)) {
    fprintf(stderr, "\nCannot create buffer for MATLAB output");
  }
  buffer[BUFSIZE] = '\0';

  /* 'whos' - MATLAB command that lists of all current variables */
  engEvalString(ep, "whos");
  printf("%s\n", buffer);
}
