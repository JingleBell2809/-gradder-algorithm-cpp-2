#include <bits/stdc++.h>
using namespace std;
int main()
{
	int PO[]={0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3};
	int JO[]={0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3};
	int select[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int J_J[]={9,2,7,8,6,4,3,7,5,8,1,8,7,6,9,4};
	
	for(int i=0; i<16; i++)
	{
		for(int j=i+1; j<16; j++)
		{
			if(J_J[i]>J_J[j])
			{
				int T=J_J[i];   J_J[i]=J_J[j];    J_J[j]=T;
					T=PO[i];    PO[i] =PO[j];     PO[j] =T;
					T=JO[i];    JO[i] =JO[j];     JO[j] =T;
			}
		}
	}
	
	for(int i=0; i<16; i++)
	{
		if(select[i] == 0)
		{
			cout<<"Person : "<<PO[i]<<" Job : "<<JO[i]<<endl;
			for(int j=i+1; j<16; j++)
			{
				if(PO[j]==PO[i] || JO[j]==JO[i])
				{
					select[j] = 1;
				}
			}
		}
	}	
}





