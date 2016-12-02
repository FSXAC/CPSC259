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
#define END system("pause"); return 1

/* Preprocessor constants */
#define BUFSIZE 256

void printMatrix(mxArray *matrix);

int main(void) {
  Engine *ep         = NULL;

  mxArray *matOne = NULL;
  mxArray *matTwo = NULL;
  mxArray *result;

  // TODO #3
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

  /* Buffer for capturing MATLAB output */
  char buffer[BUFSIZE + 1];

  matOne = mxCreateDoubleMatrix(3, 3, mxREAL);
  matTwo = mxCreateDoubleMatrix(3, 3, mxREAL);

  memcpy((void*) mxGetPr(matOne), (void*)matrixOne, 9 * sizeof(double));
  memcpy((void*) mxGetPr(matTwo), (void*)matrixTwo, 9 * sizeof(double));


  /* Start a matlab process */
  if (!(ep = engOpen(NULL))) {
    fprintf(stderr, "\nCannot start MATLAB engine\n");
    END;
  }

  /* print the input matrix */
  printf("FIRST MATRIX: \n");
  printMatrix(matOne);
  printf("SECOND MATRIX: \n");
  printMatrix(matTwo);

  if (engPutVariable(ep, "matOne", matOne)) {
    fprintf(stderr, "\nCannot write matOne to MATLAB\n");
    END;
  }
  if (engPutVariable(ep, "matTwo", matTwo)) {
    fprintf(stderr, "\nCannot write matTwo to MATLAB\n");
    END;
  }

  if (engEvalString(ep, "matrixProduct = matOne * matTwo")) {
    fprintf(stderr, "\nCannot do matrix multiplication\n");
    END;
  }

  printf("\nRetrieving product of two matrices\n");
  if((result = engGetVariable(ep,"matrixProduct")) == NULL){
    fprintf(stderr,"\nFail to retrieve matrix product\n");
    END;
  } else {
    size_t sizeOfResult = mxGetNumberOfElements(result);
    printf("The matrix product is:\n");
    printMatrix(result);
  }

  /* Capture the output by using local buffer */
  /* Add a null terminating character to string returned by engEvalString */
  if (engOutputBuffer(ep, buffer, BUFSIZE)) {
    fprintf(stderr, "\nCannot create buffer for MATLAB output");
    END;
  }
  buffer[BUFSIZE] = '\0';

  /* 'whos' - MATLAB command that lists of all current variables */
  engEvalString(ep, "whos");
  printf("%s\n", buffer);

  /* done, now free memory */
  mxDestroyArray(matOne);
  mxDestroyArray(matTwo);
  mxDestroyArray(result);
  matOne = NULL;
  matTwo = NULL;
  result = NULL;
  if (engClose(ep)) {
    fprintf(stderr, "\nFailed to close MATLAB engine\n");
  }

  END;

}

void printMatrix(mxArray *matrix) {
  size_t i, j;
  for(i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%12.6f", mxGetPr(matrix)[i * 3 + j]);
    }
    printf("\n");
  }
}
