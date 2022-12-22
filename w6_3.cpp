#include<bits/stdc++.h>
using namespace std;

class point
{
 	public:
 	int x=0;
 	int y=0;
 	point(){} 
 	point(int px,int py)
	{
  		x=px; 
  		y=py;
 	}  
 	void print()
	{
  		cout<<x<<","<<y<<" "; 
 	}
};


void merge(point* a, int left, int center, int right, int check[])
{
 	for(int i=left; i<=center; i++)
	{
  		for(int j=center+1 ;j<=right; j++)
		{
   			if(check[i]==1  &&  check[j]==1)
			{			
    			if(a[i].x <= a[j].x   &&   a[i].y <= a[j].y )
				{
     				check[i]=0;
     				break;
    			}
   			}
  		}
 	}
 	
 	for(int i=center+1; i<=right; i++ )
	{
  		for(int j=left; j<=center; j++)
		{
   			if(check[i]==1&&check[j]==1)
			{			
    			if(a[i].x <= a[j].x   &&   a[i].y <= a[j].y)
				{
     				check[i]=0;
     				break;
    			}
   			}
  		}
 	}
}


void divide(point* a, int left, int right, int check[])
{
 	if(left<right)
	{
  		int center=(left+right)/2;
  		divide(a, left, center, check),
  		divide(a, center + 1, right, check);
  		merge(a, left, center, right, check);
 	}
}

main()
{
 	int s;
 	cin>>s;
 	int check[s];
 	point p[s];
 	
 	for(int i=0; i<s; i++)
	{
  		check[i]=1;
  		cin>>p[i].x;
  		cin>>p[i].y;
 	}
 
 	divide(p, 0, s-1, check);
 	
 	for(int i=0; i<s; i++)
	{
  		if (check[i] == 1 )
		{
   			p[i].print(); 
  		} 
 	}
 	cout<<endl;
}
