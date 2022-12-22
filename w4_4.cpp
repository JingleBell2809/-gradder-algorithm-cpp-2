#include <iostream>
#include <sstream>
using namespace std;

int Array[1000];
int index=0;

void merge(int left,int mid,int right)
{
	int Left[mid-left+1], Right[right-mid];
	
	for(int i=0; i<mid-left+1; i++)
	{
		Left[i]=Array[left+i];
	}
	for(int i=0; i<right-mid; i++)
	{
		Right[i]=Array[mid+i+1];
	}
	
	int i=0,j=0;
	int k = left;
	
	while(i<mid-left+1 && j<right-mid) 
	{
		if(Left[i] <= Right[j]) 
		{
			Array[k]=Left[i];
			i++;
		}
		else{
			Array[k]=Right[j];
			j++;
		}
		k++;
	}
	while(i < mid-left+1) 
	{
		Array[k]=Left[i];
		i++;
		k++;
	}
	while(j < right-mid) 
	{
		Array[k] = Right[j];
		j++;
		k++;
	}
	for(int i=0; i<index; i++)
	{
		cout<<Array[i]<<" ";
	}
	cout<<endl;	
}

void sort(int left, int right)
{
	int mid = (left+right)/2;
	
	if(left<right)
	{
		sort(left, mid);
		sort(mid+1, right);
		merge(left, mid, right);
	}
}

int main()
{
	int x;
	string key;
	
	while(1)
	{
		cin>>key;
		stringstream ss;  
	  	ss << key;  
	  	ss >> x;
	  	
		if(key != "m")
		{
			Array[index]=x;
			index++;
		}
		else
		{
			sort(0, index-1);
			break;
		}
	}	
}
