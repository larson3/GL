/****************************************************************
 * File:    sort_books.c
 * Project: CMSC 313 Project 4, Fall 2015
 * Author:  John Larson
 * Date:    10/20/15
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

#define TITLE_LEN       32
#define AUTHOR_LEN      20
#define SUBJECT_LEN     10

struct book {
    char title[TITLE_LEN + 1];
    char author[AUTHOR_LEN + 1];    /* first author */
    char subject[SUBJECT_LEN + 1];  /* Nonfiction, Fantasy, Mystery, ... */
    unsigned int year;              /* year of e-book release */
};

void sort_books(struct book books[], int numBooks);
void print_books(struct book books[], int numBooks);
/*
 * Declarations for functions that are defined in other files
 */
extern int bookcmp();

/*
 * Declarations for global variables that need to be accessed
 * from other files
 */

struct book book1;
struct book book2;


#define MAX_BOOKS 100

int main(int argc, char **argv) {
    struct book books[MAX_BOOKS];
    int numBooks, i, x ,numFields, d;
	//a is just a temporary char array where we scale the title
	char a[80];

   for (i = 0; i < MAX_BOOKS; i++) {

		numFields = scanf("%80[^,], %20[^,], %10[^,], %u \n",&a,books[i].author,books[i].subject,&d);
		
		//checking to make sure we have all the necessary fields
		if(numFields==4)
		{
		for(x=0;x<32;x++)
		{
			//taking only the first 32 chars
			books[i].title[x]=a[x];
		}
		books[i].title[x]=0;

		//could have named "d" a little better, but it just exists to temp
		//hold the year value, as the compiler didn't want me putting in in
		//directly
		books[i].year = d;

		}
		if (numFields == EOF) {
			if(i==0)
			{
				//if there's an empty array aka nothing in the file
				printf("Data file empty.\n");
				exit(0);
			}
			numBooks = i;
		
			break;
		}
		//so we don't go over our allotted books array
		if (i==99)
		{
			numBooks = i;
			break;
		}
   }
     
    sort_books(books, numBooks);
	
    print_books(books, numBooks);

    exit(1);
}

/*
 * sort_books(): receives an array of struct books, of length
 * numBooks.  Sorts the array in-place (i.e., actually modifies
 * the elements of the array).
 *
 * This is almost exactly what was given in the pseudocode in
 * the project spec--need to replace STUBS with real code
 */
void sort_books(struct book books[], int numBooks) {
    int i, j, min;
    int cmpResult;
	struct book temp;
	//starting selection sort
    for (i = 0; i < numBooks - 1; i++) {
	min = i;
	for (j = i + 1; j < numBooks; j++) {
		book1 = books[min];
		book2 = books[j];

		//calling our assembly subroutine
	    cmpResult = bookcmp();

		if(cmpResult == 1)
		{
			min = j;

		}

	}
	//SWAPPPPPING!
	if (min != i) {
	    temp = books[i];
		books[i] = books[min];
		books[min] = temp;
	}
	
    }
}

void print_books(struct book books[], int numBooks) {
	int x;
	for (x = 0; x < numBooks; x++) {
   	printf("%s, ",books[x].title);
	printf("%s, ",books[x].author);
	printf("%s, ",books[x].subject);
	printf("%u\n",books[x].year);
	}
  }
