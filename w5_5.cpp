#include <iostream>
using namespace std;

int mod1 = 11;
int mod2 = 7;
int my_key[1000];
string my_str[1000];

void add_double_hashing(int key,string str)
{
	int num = 0;
	while(true)
	{
		int hash2 = mod2 - (key % mod2);
		int ind = ((key+(num*hash2))%mod1);
		if( my_key[ind] ==0)
		{
			my_key[ind] = key;
			my_str[ind] = str;
			break;
		}
		num++;
	}
}

string double_hashing(int key)
{
	int num = 0;
	for(int i=0 ; i<mod1 ; i++)
	{
		int hash2 = mod2 - (key % mod2);
		int ind = ((key+ (num*hash2)) % mod1 );
		if( my_key[ind] == key)
		{
			return my_str[ind];
		}
		if( my_key[ind] == 0)
		{
			return "O";
		}
		num++;
	}
}
int main()
{
	add_double_hashing(75,"A1");
	add_double_hashing(152,"A2");
	add_double_hashing(171,"A3");
	add_double_hashing(38,"A4");
	add_double_hashing(211,"A5");
	add_double_hashing(18,"A6"); 
	add_double_hashing(189,"A7");
	for(int x=0;x<mod1;x++)
	{
		cout<<my_key[x]<<endl;
	}
	cout<<double_hashing(75)<<endl;
	cout<<double_hashing(171)<<endl;
	cout<<double_hashing(18)<<endl;
}


