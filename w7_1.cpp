#include <bits/stdc++.h>
using namespace std;
int main()
{	
	int D[4][4]={{9999,2,3,1},{2,9999,4,5},{3,4,9999,8},{1,5,8,9999}};
	int ban_select[]={1,0,0,0};
	int select_city=0;
	
	for(int i=1; i<4; i++)
	{
		cout<<select_city<<endl;
		int select=0;
		int distance=9999;
		
		for (int j=0; j<4 ;j++)
		{
			if(distance>D[select_city][j] && ban_select[j]==0)
			{
				distance=D[select_city][j];
				select=j;
			}
		}
			select_city=select;
			ban_select[select_city]=1;
	}
	cout<<select_city<<endl;
}



