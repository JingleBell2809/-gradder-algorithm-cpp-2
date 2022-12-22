#include <iostream>
using namespace std;

string my_str[100];
int mod = 13;

void add_modulo_division (int key, string str)
{
	my_str[key%mod] = str;
}

string modulo_division(int key)
{
	return my_str[key%mod];
}

int main()
{
	add_modulo_division(153, "msg1");
	add_modulo_division(52, "msg2");
	add_modulo_division(7, "msg3");
	add_modulo_division(17, "msg4");
	cout<<modulo_division(153)<<endl;
	cout<<modulo_division(52)<<endl;
}


