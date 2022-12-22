#include<bits/stdc++.h>
using namespace std;

int size=9;
int S[9]={1,2,4, 1,5,8, 9,11,13};
int E[9]={3,5,7, 8,9,10, 11,14,16};
int I[9]={1,2,3,4,5,6,7,8,9};
int O[3][9];
int Select[9]={0,0,0, 0,0,0, 0,0,0};

bool check_constrain(int row)
{
	for(int i=0; i<size-1; i++)
	{
		for(int j=i+1; j<size; j++)
		{
			if(O[row][i]==1  &&  O[row][j]==1)
			{
				if( S[i]>=E[j]  ||  E[i]<=S[j])
				{}
				else
				{
					return false;
				}					
			}
		}
	}	
	return true;	
}

main()
{
	for(int i=0; i<9; i++)
	{
		for(int j=i+1; j<9; j++)
		{
			if(S[i] >= S[j])
			{
				int T=S[i];   S[i]=S[j];   S[j]=T;
			     	T=E[i];   E[i]=E[j];   E[j]=T;
				    T=I[i];   I[i]=I[j];   I[j]=T;

			}
		}
	}

	int row=0;
	
	while(1)
	{
		for(int i=0; i<9; i++)
		{
			if(Select[i] == 0)
			{
				O[row][i]=1;
				if(check_constrain(row))
				{
					Select[i]=1;
				}
				else
				{
					O[row][i]=0;
				}
			}
		}
		
		row=row+1;
		bool out_loop=true;	
		
		for(int i=0; i<9; i++)
		{
			if(Select[i] == 0)
			{
				out_loop=false; 
				break; 
			} 
		}
		if(out_loop) 
		{
			break;
		}
	}
	
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<size; j++)
		{
			cout<<O[i][j]<<"\t";  
		}
		cout<<endl;
	}
}
