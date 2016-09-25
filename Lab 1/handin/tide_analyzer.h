/*
 File:           	tide_analyzer.h
 Purpose:         	Contains prototypes
 Author:			Mansur (Muchen) He, Shariful Alam Arnob
 Student #s:		44638154, 20293156
 CS Accounts:		p5h0b, r9t0b
 Date:				2016-09-14
 */

/********************************************************************
 YOU MAY EDIT THIS FILE (BUT YOU DON'T NEED TO)
 ******************************************************************/

#pragma once

/* Insert function prototypes here */
FILE * open_file (FILE * file_pointer, char * fileName, char * mode );
void process_file( double array_to_populate[], FILE * pointer_to_data_file );