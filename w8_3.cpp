#include<iostream>
#include<math.h>
using namespace std;

char X[]="acbcf";
char Y[]="abcdaf";
int s_x=5;
int s_y=6;
int array[10][10];

int max(int a, int b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int main()
{
	for(int i=0; i<=s_x; i++)
	{
		for(int j=0; j<=s_y; j++)
		{
			if(i==0 || j==0)
			{
				array[i][j]=0;
			}
			else if(X[i-1]==Y[j-1])
			{
				array[i][j]=1+array[i-1][j-1];
			}
			else
			{
				array[i][j]=max(array[i][j-1], array[i-1][j]);
			}
		}
	}
	
	for(int i=0; i<=s_x; i++)
	{
		for(int j=0; j<=s_y; j++)
		{
			cout<<array[i][j]<<" ";
		}
		cout<<endl;	
	}
}
