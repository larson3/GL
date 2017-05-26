/****************************************************************
 * File:    frac_heap.h
 * Project: CMSC 313 Project 5, Fall 2015
 * Author:  John Larson
 * Date:    10/27/15
 * E-mail:  larson3@umbc.edu 
 *
 *   This file contains the declarations for our frac_heap.c file.
 *   We also define our fraction struct here.
 *
 ****************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP 20



typedef struct fraction
{
	signed char sign;
	unsigned int numerator;
	unsigned int denominator;
	
} fraction;


    /****************************************************************
     * *new_frac():
     * Preconditions:
     *   requires a valid fraction struct
     * Postconditions:
     *   places this struct into our heap
     ****************************************************************/
fraction *new_frac();

    /****************************************************************
     * init_heap():
     * Preconditions:
     *   none
     * Postconditions:
     *   creates a new heap of size 20
     ****************************************************************/
void init_heap();

    /****************************************************************
     * del_frac():
     * Preconditions:
     *   requires a valid fraction struct
     * Postconditions:
     *   removes the desired fraction from the heap
     ****************************************************************/
void del_frac(fraction *fptr1);

    /****************************************************************
     * dump_heap():
     * Preconditions:
     *   requires a heap to have been created
     * Postconditions:
     *   prints the values on the heap and the first free node
     ****************************************************************/
void dump_heap();