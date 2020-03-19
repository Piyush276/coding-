/ #include </Users/piyush/Desktop/CP/bits/stdc++.h>
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


void multiple(int a[2][2],int b[2][2]){
	ll p1=a[0][0]*b[0][0]+a[0][1]*b[1][0];
	ll p2=a[0][0]*b[0][1]+a[0][1]*b[1][1];
	ll p3=a[1][0]*b[0][0]+a[1][1]*b[1][0];
	ll p4=a[1][0]*b[0][1]+a[1][1]*b[1][1];

	a[0][0]=p1;
	a[0][1]=p2;
	a[1][0]=p3;
	a[1][1]=p4;

}



void power(int a[2][2],int pow){
	if(pow==0 or pow==1)
		return 1;
	multiple(a,a);
	if(p%2!=0){
		int m[2][2]={{1,1},{1,0}};
		multiple(a,m);
	}
}


ll solve(n){
	if(n==0){
		return 0;
	}
	int a[2][2]={{1,1},{1,0}};
	power(a,n-1);
	return a[0][0];

}


int main(){
	ll n;
	cin>>n;
	cout<<solve(n);
}