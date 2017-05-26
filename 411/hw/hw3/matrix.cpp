#include <iostream>

using namespace std;

int main(){

	int A[3] = {1,2,3};
	int B[3] = {9,8,7};
	int C[3] = {};
	int D[3][3] = {};
	
	for(int i=0;i<3;i++)
	{
		C[i] = A[i]*B[i];
		
		cout<<C[i]<<endl;
	}
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			D[i][j] = A[i]*B[j];
			cout<<D[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	
	return 0;
}


