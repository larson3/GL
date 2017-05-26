#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Following is straight from the project description
 */
#define TITLE_LEN       32
#define AUTHOR_LEN      20
#define SUBJECT_LEN     10

void testbreak();

struct book {
    char title[TITLE_LEN + 1];
    char author[AUTHOR_LEN + 1];    /* first author */
    char subject[SUBJECT_LEN + 1];  /* Nonfiction, Fantasy, Mystery, ... */
    unsigned int year;              /* year of e-book release */
	int fuck;
};

int main(int argc, char **argv) {

	int x;
	struct book book1;
	char a[] = "Harry Potter";
	char b[] = "JK Rowling";
	char c[] = "Fantasy";
	for(x=0;x<32;x++)
	{
		book1.title[x]=a[x];
	}
	
	for(x=0;x<20;x++)
	{
		book1.author[x]=b[x];
	}
	
	for(x=0;x<10;x++)
	{
		book1.subject[x]=c[x];
	}

	book1.year = 1997;
	book1.fuck = 111;
	printf("%s\n", book1.title);
	testbreak();
	exit(1);
}

void testbreak(){};