
#include </Users/piyush/Desktop/CP/bits/stdc++.h>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



#define print(x) for(auto iuiuiuiuiui:x){ cout<<iuiuiuiuiui<<" ";}br;
#define print_array(array,size) for(ll i=0;i<size;i++){ cout<<array[i]<<" ";}br;
#define br cout<<"\n"
#define max_val 1000000
#define mod 1000000007
#define pb(a) push_back(a)

#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);


void max_heap(ll *a,ll *heap,ll n){
	ll pp=1;   // pp->parent position




}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	ll *a=new ll[n+1];
	ll *heap=new ll[4*n];
	ll temp;
	ll pp=1;   // pp->parent position
	for(ll i=1;i<n+1;i++){
		cin>>a[i];
		temp=i/2;
		if(i==0){
			continue;
		}
		while(a[temp]<a[i]){
			swap(a[temp],a[i]);
			temp=i/2;
			if(i==0){
				break;
			}
		}
	}
	for(ll i=1;i<n+1;i++){
		cout<<a[i]<<" ";
	}



	// max_heap(a,heap,n);

	// for(ll i=0;i<n;i++){
	// 	cin>>a[i];
	// }

}