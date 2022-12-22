#include<bits/stdc++.h>
using namespace std;

int size=0;
int arr[100];

void quickSort(int left, int right) 
{
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
    int i=left; 
	int j=right;
	int m=(left+right)/2;
    
    if((arr[m]<arr[i] && arr[i]<arr[j])   ||   (arr[j]<arr[i] && arr[i]<arr[m]))
    {
    	int temp=arr[i];
    	arr[i]=arr[right];
		arr[right]=temp;
	}
    else if((arr[m]<arr[j] && arr[j]<arr[i])   ||   (arr[i]<arr[j] && arr[j]<arr[m]))
    {
    	int tmp=arr[j];
    	arr[j]=arr[right];
		arr[right]=tmp;
	}	
	else if((arr[i]<arr[m] && arr[m]<arr[j])   ||   (arr[j]<arr[m] && arr[m]<arr[i]))
	{
		int tmp=arr[m];
    	arr[m]=arr[right];
		arr[right]=tmp;
	}
    
    int pivot=arr[right]; 
	    j=right-1;
    
    while(i<=j)
	{
        while(arr[i]<pivot)
        {
        	i++;
		} 
        while(arr[j]>pivot)
        {
        	j--;
		}			
        if(i <= j)
		{
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }
    
    for(int t=right; t>i; t--)
    {
    	int x=arr[t];
    	arr[t]=arr[t-1];
    	arr[t-1]=x;
	}
    
    if(left<j)
    {
    	quickSort(left, j);
	}      
	
    if(i<right)
    {
    	quickSort(i, right);
	}   
}

main()
{
	string key;
	while(1)
	{
		cin>>key;
		if(key =="t")
		{
			quickSort(0, size-1);
			break;
		}
		else
		{	
			const char*c=key.c_str();
			arr[size]=atoi(c);
			size++;
		}
	}
	return 0;
}
