
#include </Users/piyush/Desktop/CP/bits/stdc++.h>
// #include <bits/stdc++.h>
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

class node{
public:
	ll s;
	ll d;
	ll v;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
    while(t--){
        ll n,q;
        cin>>n>>q;
        ll *parent=new ll[n];
        for(ll i=0;i<n;i++){
        	parent[i]=i;
        }
        vector<node> store;
        ll e1,e2,v;
        while(q--){
        	cin>>e1>>e2>>v;
        	node temp;
        	temp.s=e1;
        	temp.d=e2;
        	temp.v=v;
        	store.push_back(temp);
        }
        
    }

}