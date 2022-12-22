#include <bits/stdc++.h>
using namespace std;
long long int karasuba(long long int x, long long int y)
{
	if(x<10||y<10)
	{
		return (x*y);
	}
	
	int lx=0; int t=1;
	while(1)
	{
		if((x/t)<=0)
		{
			break;
		}
		t=t*10; 
		lx++;	
	}

	int ly=0; t=1;
	while(1)
	{
		if((y/t)<=0)
		{
			break;
		}
		t=t*10; 
		ly++;	
	}
	
	int n=0;
	if(lx>ly)
	{
		n=lx;
	}
	else
	{
		n=ly;
	}
	n=(int)(n/2);
	
	long long int p=pow(10,n);
	long long int a=(long long int)(x/p);
	long long int b=x%p;
	long long int c=(long long int)(y/p);
	long long int d=y%p;
	long long int ac=karasuba(a,c);
	long long int bd=karasuba(b,d);
	long long int ad_bc=karasuba(a+b,c+d)-ac-bd;
	return ac*pow(10,2*n)+(ad_bc*pow(10,n))+bd;
}
int main()
{	
	int x,y;
	cin>>x>>y;
	cout<<karasuba(x,y)<<endl;	
}




