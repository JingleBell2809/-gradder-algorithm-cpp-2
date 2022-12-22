#include<bits/stdc++.h>
using namespace std;

void quickSort(int arr[], int left, int right, int size) 
{
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
    int i=left, j=right;
    int pivot=arr[(left+right)/2];
    
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
            int tmp=arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;
            i++;
            j--;
        }
    }
    
    if(left<j)
    {
    	quickSort(arr, left, j, size);
	}      
	
    if(i<right)
    {
    	quickSort(arr, i, right, size);
	}   
}

main()
{
	int size=0,arr[100];
	int x;
	string key;
	while(1)
	{
		cin>>key;
		stringstream ss;
		ss<<key;
		ss>>x;
		
		if(key!="q")
		{
			arr[size]=x;
			size++;
		}
		else
		{
			quickSort(arr, 0, size-1, size);
			for(int i=0;i<size;i++)
			{
				cout<<arr[i]<<" ";
			}
			cout<<endl;
			break;
		}
	}
}
