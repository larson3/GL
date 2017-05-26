/****************************************************************
 * File:    frac_heap.c
 * Project: CMSC 313 Project 5, Fall 2015
 * Author:  John Larson
 * Date:    10/27/15
 * E-mail:  larson3@umbc.edu 
 *
 *   This file is the logic for frac_heap.  This file will aid in creating
 *   an array which will serve as a memory heap as well as allocating 
 *   new memory into the heap.  It also has the capability of deleting
 *   members and printing the heap.
 *
 ****************************************************************/

#include "frac_heap.h"

static int first_free =0;
static fraction fracArray[MAX_HEAP];

fraction *new_frac()
{
	/*this is our 'magic number' if we hit 20 we've gone too far*/
	if(first_free==20)
	{
		return NULL;
	}

	else{
	int temp = first_free;
	first_free = fracArray[first_free].denominator;
	return fracArray+temp;
	}
}

void init_heap()
{
	int i;
	for(i=0;i<MAX_HEAP;i++)
	{
		/*all values except denom set to zero*/
		fracArray[i].sign = 0;
		fracArray[i].numerator = 0;
		fracArray[i].denominator = i+1;
	}
	
}

void del_frac(fraction *fptr1)
{
	fraction *tempP1;
	int index;
	tempP1 = fracArray;
	index = fptr1 - tempP1;
	/*if we are outside of our array we quit*/
	if(index >= 20 || index < 0)
	{
		printf("Error.  Cannot delete from outside array.\n");
		exit(1);
	}
	fracArray[index].denominator = first_free;
	first_free = index;
	fracArray[index].sign = 0;
	fracArray[index].numerator = 0;

}

void dump_heap()
{
	int x;
	printf("***BEGIN HEAP DUMP***\nfirst_free = %d\n\n",first_free);
	/*just printing every line*/
	for(x=0;x<MAX_HEAP;x++)
	{
		printf("%d: %d %u %u\n",x,fracArray[x].sign,fracArray[x].numerator,fracArray[x].denominator);
	}
	printf("***END HEAP DUMP***\n\n");
}
