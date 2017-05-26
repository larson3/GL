#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 10


void* mymalloc(int size) {
 void* ptr = malloc(size);
 fprintf(stderr,"malloc: %p\n",ptr);
 return ptr;
}
void myfree(void* ptr) {
 fprintf(stderr,"free: %p\n",ptr);
 free(ptr);
}
char *concatenate(char *a, char *b)
{
	int i=0;
	int x=0;
	char* c = mymalloc(200);
	//char *c = (char*)malloc(400);
    while(a[i] != NULL)
	{
		c[i]=a[i];
		i++;
		//printf("TEST\n");
	}
	while(b[x]!=NULL)
	{
		c[i]=b[x];
		i++;
		x++;
		//printf("TEST2\n");
	}

    return c;
}

int main(int argc, char **argv)
{
    if (argc > 4) {
	printf("Usage: hw1_leaky <count> <firstword> <secondword> \n");
	exit(1);
    }
    
    char *middle = "cruel";
    char number[MAXCHAR];
    int i = 0;

    for(i = 0;i < atoi(argv[1]); i++)
    {
		sprintf(number,"%d", i);

		//begin leaky
		                     //not leaked
		char *line1 = concatenate(argv[2], number);
		char *line2 = concatenate(number, argv[3]);
		char *line3 = concatenate(middle, line2);
		char *line = concatenate(line1,line3);
	
		myfree(line1);
		myfree(line2);
		myfree(line3);
		if(i > 0) //should not free statically allocated "cruel" string
		myfree(middle);
		//myfree(line);
	//end leaky
		printf("%s \n",line);
		middle = line;
		//myfree(line);
    }
	
    myfree(middle);
	/*concatenate(argv[2],argv[3]);
	int test1 = strlen(argv[2]);
	int test2 = sizeof(argv[2]);
	printf("%d %d \n",test1,test2);*/
}

