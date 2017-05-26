#include <stdio.h>


int main()
{
	int begNow,begSoFar,endSoFar,bestSoFar,bestNow,x,temp;
	int A[5] = {-5,4,3,-4,6};
	begSoFar = -1;
	endSoFar = -1;
	begNow= -1;
	bestSoFar = 0;
	bestNow = 0;
	
	for(x=0;x<5;x++)
	{
		temp = bestNow + A[x];
		
		if(temp>0)
		{
			if(bestNow == 0)
			{
				begNow = x;
			}
			bestNow = temp;
		}
		else{
				bestNow = 0;
			}
			if(bestNow > bestSoFar)
			{
				bestSoFar = bestNow;
				endSoFar = x;
				begSoFar = begNow;
				
			}	
	printf("NOW: Beginning: %d  End: %d  Total: %d \n",begNow,x,bestNow);
	printf("SO FAR: Beginning: %d  End: %d  Total: %d \n",begSoFar,endSoFar,bestSoFar);	
	}

	printf("FINAL: Beginning: %d  End: %d  Total: %d \n",begSoFar,endSoFar,bestSoFar);
}