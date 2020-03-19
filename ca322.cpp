#include </Users/piyush/Desktop/CP/bits/stdc++.h>
// #include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define br cout<<"\n"
#define mod 1000000007
#define max_val 10500


bool sorting(pair<ll,ll> a,pair<ll,ll> b){
    if(a.second<b.second){
        return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<pair<ll,ll>> a;
    ll e1,e2;
    for(ll i=0;i<n;i++){
        cin>>e1>>e2;
        a.push_back(make_pair(e1,e2));
    }
    sort(a.begin(),a.end(),sorting);

    ll i = 0; 
    cout << "(" << arr[i].start << ", " << arr[i].finish << "), "; 
    ll count=1;
    for (ll j = 1; j < n; j++) 
    { 
	    if (a[j].first >= a[i].second) 
	    { 
	       count++;
	        i = j; 
	    } 
    }
    cout<<count; 
    
}