#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
	if(a>b){return a;}
	else{return b;}
}

int min(int a, int b)
{
	if(a<b){return a;}
	else{return b;}
}

int main()
{
	int size=4;
	int arr[]={3,9,1,2};
	int table[100][100];

	for(int gap=0; gap<size; ++gap)
	{
		for(int i=0,j=gap; j<size; ++i,++j)
		{
			int x=0;
			if(i+2 <= j){x=table[i+2][j];}

			int y=0;
			if(i+1 <= j-1){y=table[i+1][j-1];}

			int z=0;
			if(i <= j-2){z=table[i][j-2];}

			table[i][j]=max(arr[i]+min(x,y),arr[j]+min(y,z));
		}
	}

	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			cout<<table[i][j]<<"\t";
		}
		cout<<endl;
	}
}


