#include <iostream>
using namespace std;

int mod = 13;
int my_key[1000];
string my_str[100];

void add_linear_probing(int key, string str)
{
	int num = 0;
	while(true)
	{
		int ind = (key+num) % mod;
		if(my_key[ind] == 0)
		{
			my_key[ind] = key;
			my_str[ind] = str;
			break;
		}
		num++;
	}
}

string linear_probing(int key)
{
	int num = 0;
	for(int i=0; i<mod; i++)
	{
		int ind = (key+num) % mod;
		if (my_key[ind] == key)
		{
			return my_str[ind];
		}
		if(my_key[ind] == 0)
		{
			return "0";
		}
		num++;
	}
}

int main()
{
	add_linear_probing(156, "A1");
	add_linear_probing(85, "A2");
	add_linear_probing(42, "A3");
	add_linear_probing(54, "A4");
	add_linear_probing(189, "A5");
	add_linear_probing(125, "A6");
	add_linear_probing(34, "A7");
	add_linear_probing(99, "A8");
	cout<<linear_probing(54)<<endl;
	cout<<linear_probing(189)<<endl;
}






