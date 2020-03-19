#include </Users/piyush/Desktop/CP/bits/stdc++.h>
using namespace std;
int start2(int a[],int n,int capacity)
{
	int b[n],res=1; // check res
	for(int i=0;i<n;i++)
		b[i]=capacity;
	for(int i=0;i<n;i++)
	{
		int target=0;
		for(int j=0;j<n;j++)
		{
			if(b[j]>=a[i])
			{
				target=j;
				break;
			}
		}
			
		if(b[target]==capacity)
				res++;
		b[target]-=a[i];
		
	}
	return res;
}

int start3(int a[],int n,int capacity){
	int man=
}

int main()
{
	int a[]={10,9,8,4,3,2};
	int n=sizeof(a)/sizeof(a[0]);
	int capacity=12;
	cout<<start2(a,n,capacity);
	
}