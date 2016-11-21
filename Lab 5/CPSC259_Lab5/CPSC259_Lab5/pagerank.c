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

// main function
int notmain(void) {
  /* Initial variables */
  Engine *ep         = NULL;
  mxArray *testArray = NULL;
  mxArray *result    = NULL;
  double time[3][3]  = {
    {1.0, 2.0, 3.0},
    {4.0, 5.0, 6.0},
    {7.0, 8.0, 9.0}
  };

  /* Buffer for capturing MATLAB output */
  char buffer[BUFSIZE + 1];

  /* Start a matlab process */
  if (!(ep = engOpen(NULL))) {
    fprintf(stderr, "\nCannot start MATLAB engine\n");
    END;
  }

  /* Create 3x3 empty matrix */
  testArray = mxCreateDoubleMatrix(3, 3, mxREAL);

  /* Copy the 'time' 2D array MATLAB 2D array, testArray */
  memcpy((void *)mxGetPr(testArray), (void *)time, 9 * sizeof(double));

  /* Putting variable into MATLAB engine, the copy does not need to be freed from memory */
  if (engPutVariable(ep, "testArray", testArray)) {
    fprintf(stderr, "\nCannot write test array to MATLAB\n");
    END;
  }

  /* using matlab engine to get eigenvalues */
  if (engEvalString(ep,"testArrayEigen = eig(testArray)")) {
    fprintf(stderr,"\nError calculating eigenvalues  \n");
    END;
  }

  /* using the enginegetvariable to retrieve the eigenvector */
  printf("\nRetrieving eigenvalues\n");
  if((result = engGetVariable(ep,"testArrayEigen")) == NULL){
    fprintf(stderr,"\nFail to retrieve eigenvalue vector\n");
    END;
  } else {
    size_t sizeOfResult = mxGetNumberOfElements(result);
    size_t i            = 0;
    printf("The eigenvalues are:\n");
    for(i=0;i<sizeOfResult;++i) {
      // printf("%f\n",*(mxGetPr(result)+i));
      printf("%f\n", mxGetPr(result)[i]);
    }
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
  mxDestroyArray(testArray);
  mxDestroyArray(result);
  testArray = NULL;
  result    = NULL;
  if (engClose(ep)) {
    fprintf(stderr, "\nFailed to close MATLAB engine\n");
  }

  /* exit */
  END;
}
