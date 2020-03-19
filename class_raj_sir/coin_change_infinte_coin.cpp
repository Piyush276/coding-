#include </Users/piyush/Desktop/CP/bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define br cout<<"\n"

// int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	ll n;
// 	cin>>n;
// 	ll *coins=new ll[n];
// 	for(ll i=0;i<n;i++){
// 		cin>>coins[i];
// 	}
// 	sort(coins,coins+n,greater<int>());
// 	ll value;
// 	cin>>value;
// 	while(value--){
// 		ll count=0;
// 		cin>>value;
// 		for(ll i=0;i<n;i++){
// 			while(value>=coins[i]){
// 				count++;
// 				value-=coins[i];
// 			}
// 		}
// 		cout<<count;br;
// 	}
// }

//  or
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll *coins=new ll[n];
    for(ll i=0;i<n;i++){
        cin>>coins[i];
    }
    sort(coins,coins+n,greater<int>());
    ll value,temp;
    cin>>temp;
    
    while(temp--){
        ll count=0;
        cin>>value;
        for(ll i=0;i<n;i++){
            if(value>=coins[i]){
                ll div=value/coins[i];
                count+=div;
                value-=(div*coins[i]);
            }if(value==0)
                break;
        }
        cout<<count;br;
    }
}
