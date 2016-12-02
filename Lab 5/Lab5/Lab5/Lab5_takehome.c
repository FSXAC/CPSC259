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

/* Preprocessor constants */
#define BUFSIZE 256
#define BUFFER 128

void printMatrix(mxArray *matrix);

int main(void)
{
  int error = 0;
  FILE        *web_file = NULL;
  double     **web = NULL;
  int dimension = 0;

  error = fopen_s( &web_file, "web.txt", "r");
  if( error ){
      fprintf(stderr, "Unable to open file");
      system( "pause");
      return 1;
  }

  if( web_file) {
    dimension = get_web_dimension(web_file);
    web = parse_web(web_file,dimension);
    }
    else{
      fprintf( stderr, " Unable to parse maze file");
      system("pause");
      return 1;
      }




}


// get the diemsion of the web.txt
int get_web_dimension(FILE* web_file) {
    int dimension = 0;
    char line_buffer[BUFFER];

    dimension = strlen( fgets (line_buffer, BUFFER, web_file));

    fseek(web_file,0, SEEK_SET);

    if( strchr( line_buffer, '\r') !=NULL) {
      return (dimension-2);
    } else {

    return (dimension-1);
      }

}
