#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define br cout<<"\n"
#define max_val 100000

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,temp,val;
    map<ll,ll> s;
    while(n--){
    	cin>>temp;
    	if(temp==1){
    		cin>>val;
    		s[val]=1;
    	}
    	else if(temp==2){
    		cin>>val;
    		s[val]=0;
    	}
    	else{
    		ll min=LONG_LONG_MAX;
    		for(auto i=s.begin();i!=s.end();i++){
    			if(min<i.first and i.second==1){
    				min=i;
    			}
    		}
    		if(min==LONG_LONG_MAX){
    			cour<<"-1";
    			br;
    		}
    		else{
    			cout<<min;
    			br;
    		}
    	}
    }

}