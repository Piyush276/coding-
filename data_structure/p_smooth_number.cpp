
#include<bits/stdc++.h>
using namespace std;
#define num 1001
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 //    #ifndef ONLINE_JUDGE
 //    	freopen("/mnt/extra/sem5/cse330/i_o/input.txt", "r", stdin);
 //    	freopen("/mnt/extra/sem5/cse330/i_o/output.txt", "w", stdout);
 //    	freopen("/mnt/extra/sem5/cse330/i_o/error.txt","w",stderr);
	// #endif
    int arr[num];
    for (int i = 0; i < num; i++)
    {
    	arr[i] = 1;
    }
    // for (int i = 0; i < num; i++)
    // {
    // 	cout<<arr[i]<<" ";
    // }
    arr[0] = 0;
    arr[1] = 0;
    for(int i =2;i*i<=num;i++)
    {
    	for(int j=2*i;j<num;j+=i)
    	{
    		arr[j] = 0;
    	}
    }
    // for (int i = 0; i < num; i++)
    // {
    // 	cout<<arr[i]<<" ";
    // }
	int p = 5;	
	int count = 10;
	int minprime = 2;
	int j=3;
	while(minprime<p)
	{
		if(arr[j])
		{
			minprime=j;
			// cout<<minprime<<" ";
		}	
		j++;
	}
	//cout<<minprime;
	int i = minprime;
	while(count)
	{
		if(arr[i])
		{
			cout<<i<<"\n";
			arr[(i/arr[i])*(arr[i]+1)] = arr[i]+1;
			count--;
		}
		i++;			
	}
	return 0;
}