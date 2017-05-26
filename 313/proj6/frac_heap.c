/****************************************************************
 * File:    frac_heap.c
 * Project: CMSC 313 Project 5, Fall 2015
 * Author:  John Larson
 * Date:    11/2/15
 * E-mail:  larson3@umbc.edu 
 *
 *   This file is the logic for frac_heap.  This file will aid in creating
 *   a linked list of free memory which will be given to a calling function
 *   and used to create fraction structures.
 ****************************************************************/

#include "frac_heap.h"
#include <stdio.h>
#include <stdlib.h>

static frac_block *free_list;

void init_heap()
{
	free_list = NULL;
}

fraction *new_frac()
{
	/*this will be useful in remembering where the start of our list is*/
	frac_block *root = NULL;
	int x;
	fraction *return_val;
	
	if(free_list == NULL)
	{
		/*asking for more memory*/
		free_list = (frac_block*)malloc(5* sizeof(frac_block));
		/*in case we are entirely out of memory we exit*/
		if(free_list == NULL)
		{
			printf("Out of memory!\n");
			exit(1);
		}
		/*setting our root, so we can find the start again*/
		root = free_list;
		
		printf("called malloc(%d): returned %p\n",5*sizeof(frac_block),free_list);
		/*loop through, filling out the linked list*/
		for(x=0;x<4;x++)
		{
			free_list->next = free_list+1;
			free_list = free_list->next;
		}
		/*the end of the list should be null terminated*/
		free_list->next = NULL;
		free_list = root;
		
	}
	/*set the value to return and move up one on the list*/
	return_val = &(free_list->frac);
	free_list = free_list->next;
	
	return return_val;
		
}

void dump_heap()
{
	frac_block *temp;
	/*if the list is empty, we let the user know*/
	if(free_list == NULL)
	{
		printf("Free list is empty\n");
	}
	else
	{
		printf("\n**** BEGIN HEAP DUMP ****\n\n");
		/*same as root earlier*/
		temp = free_list;
		while(free_list != NULL)
		{
			printf("%p\n",free_list);
			free_list = free_list->next;
		}
		free_list = temp;
		printf("**** END HEAP DUMP ****\n");
	}
}

void del_frac(fraction *fptr)
{
	frac_block *fpb, *current;

	/*cast the fraction as the union so we can get at next*/
	fpb = (frac_block *) fptr;
	current = NULL;
	/*we check to see if the list is empty, so we don't try to assign our new
	value to the ->next of a NULL which will seg fault.*/
	if(free_list!=NULL)
	{
		current = free_list;
		/*looping to the end of the free list and adding the new value*/
		while(current->next!=NULL)
		{
			current=current->next;
		}
		current->next = fpb;
		current->next->next=NULL;
	}
	else{
		free_list = fpb;
		free_list->next = NULL;
	}
}