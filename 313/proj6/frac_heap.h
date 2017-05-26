/****************************************************************
 * File:    frac_heap.h
 * Project: CMSC 313 Project 6, Fall 2015
 * Author:  John Larson
 * Date:    10/30/15
 * E-mail:  larson3@umbc.edu 
 *
 *   This file contains the declarations for our frac_heap.c file.
 *   We also define our fraction struct here.
 *
 ****************************************************************/
#ifndef FRAC_HEAP_H
#define FRAC_HEAP_H





typedef struct fraction
{
	signed char sign;
	unsigned int numerator;
	unsigned int denominator;
	
} fraction;

typedef union fraction_block_u {
    union fraction_block_u *next;
    fraction frac;
	} frac_block;

    /****************************************************************
     * *new_frac():
     * Preconditions:
     *   requires a valid fraction struct
     * Postconditions:
     *   takes a free address from the free list and assigns it to where
	 *   the new_frac is set to return to.  will ask for more memory if
	 *   we fun out of free nodes on our free list.
     ****************************************************************/
fraction *new_frac(void);

    /****************************************************************
     * init_heap():
     * Preconditions:
     *   none
     * Postconditions:
     *   creates a new free list, sets to NULL
     ****************************************************************/
void init_heap(void);

    /****************************************************************
     * del_frac():
     * Preconditions:
     *   requires a valid fraction struct
     * Postconditions:
     *   adds the memory address to our free list
     ****************************************************************/
void del_frac(fraction *fptr);

    /****************************************************************
     * dump_heap():
     * Preconditions:
     *   requires a heap to have been created
     * Postconditions:
     *   prints the memory addresses of everthing in the free list
     ****************************************************************/
void dump_heap(void);

#endif