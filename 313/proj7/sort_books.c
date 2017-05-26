/****************************************************************
 * File:    sort_books.c
 * Project: CMSC 313 Project 7, Fall 2015
 * Author:  John Larson
 * Date:    11/7/15
 * E-mail:  larson3@umbc.edu 
 *
 *   This file contains the entirety of the sort_books program with
 *   the exception of the bookcmp subroutine which is linked as an
 *	 external function.
 *
 ****************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "book.h"

/*will call quicksort to sort the struct array passed in*/
void sort_books(struct book books[], int numBooks);

/*externally stored assembly code.  Compares two book structs and returns
-1,0,1 depending on which is larger*/
extern int bookcmp(const void *,const void *);

void sort_books(struct book books[], int numBooks) {

/*calling qsort with the books array, the size of the array, size of
a book struct and the assembly function we will use to compare*/
	qsort(books,numBooks,sizeof(struct book),bookcmp);
	
}