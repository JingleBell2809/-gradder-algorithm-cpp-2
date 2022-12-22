#include <iostream>
using namespace std;

int mod = 7;

class node
{
	public:
	int key;
	string str;
	node*next;
	node()
	{
		key = -1;
		str = "-";
		next = NULL;
	}
	node(string s, int k)
	{
		key = k;
		str = s;
		next = NULL;
	}
};
node n[7];

void add_separate_chaining(int key, string str)
{
	int ind = key % mod;
	
	if( n[ind].next == NULL)
	{
		n[ind].str = str;
		n[ind].key = key;
		n[ind].next = new node();
	}
	else
	{
		node*start = n[ind].next;
		while(start->next!=NULL)
		{
			start = start->next;
		}
		start->str = str;
		start->key = key;
		start->next = new node();
	}
}


	string separate_chaining(int key)
	{
		int ind = key%mod;
		if(n[ind].key == key)
		{
			return n[ind].str;
		}
		else
		{
			node*start = n[ind].next;
			while(start->next != NULL)
			{
				if(key == start->key)
				{
					return start->str;
				}
				start = start->next;
			}
		}
		return "N";
	}
	
int main()
{
	add_separate_chaining(2,"a1");
	add_separate_chaining(9,"a2");
	add_separate_chaining(16,"a3");
	cout<<separate_chaining(2)<<endl;
	cout<<separate_chaining(16)<<endl;
	cout<<separate_chaining(9)<<endl;
}

