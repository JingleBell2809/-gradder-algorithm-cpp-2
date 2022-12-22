#include<bits/stdc++.h>
using namespace std;

int min_ =99999;
int nums[] = {5,6,7,1,55,10,2,9,20,15,32,17,19,23,18,19,31,21,44,39};

void findMinAndMax(int low, int high)
{
	if (low == high)
	{
		if (min_ > nums[low]) 
		{
			min_ = nums[low];
		} 
		return;	
	}
	if (high - low == 1)
	{
		if (min_ >nums[high]) 
		{
			min_= nums[high];
		}
		if (min_ >nums[low]) 
		{
			min_ = nums[low];
		}
		return;
	}
	int mid = (low + high) / 2;
	findMinAndMax( low, mid );
	findMinAndMax( mid + 1, high);	
}

int main()
{
	findMinAndMax(0, 19);
	cout << min_ << endl;
}




