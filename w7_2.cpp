#include <bits/stdc++.h>
using namespace std;	

int bag=10;
double D[5];
int W[5]={1,5,3,2,4};
int V[5]={5,9,10,6,7};
int ans[5]={0,0,0,0,0};
int I[5]={1,2,3,4,5};
int size=sizeof(W)/sizeof(W[0]);

bool check_constrain()
{
	int sum=0;
	for(int i=0; i<size; i++)	
	{
		if(ans[i]==1)
		{
			sum=sum+W[i];
		}
		if(sum>bag)
		{
			return false;
		}
	}
	return true;
}

int main()
{		
	for(int i=0; i<5; i++)
	{
		D[i]=(V[i]*1.0)/(W[i]*1.0);
	}
	for(int i=0; i<5; i++)
	{
		for(int j=i+1; j<5; j++)
		{
			if(D[i]<D[j])
			{
				   int T=V[i];    V[i]=V[j];    V[j]=T;
				       T=W[i];    W[i]=W[j];    W[j]=T;
				       T=I[i];    I[i]=I[j];    I[j]=T;
				double d=D[i];    D[i]=D[j];    D[j]=d;
			}
		}
		//cout<<D[i]<<"---";
	}
	//cout<<endl;
	
	for(int i=0; i<5; i++)
	{
		ans[i] = 1;
		if(check_constrain())
		{
			cout<<I[i]<<" ";
		}
		else
		{
			ans[i]=0;
		}
	}	
}




