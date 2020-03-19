#include </Users/piyush/Desktop/CP/bits/stdc++.h>
// #include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define br cout<<"\n"
#define mod 1000000007
#define max_val 10500

bool prime[max_val];
bool pnumber[max_val];
void sieve(){
    prime[0]=false;
    prime[1]=false;
    for(ll i=4;i<max_val;i+=2)
        prime[i]=false;
    for(ll i=3;i<sqrt(max_val);i+=2){
        for(ll j=i*i;j<max_val;j+=i)
            prime[j]=false;
    }
}
ll max_prime(ll n) 
{ 

	ll maxp = -1; 
	while (n % 2 == 0) { 
		maxp= 2; 
		n >>= 1;
	} 
	for (int i = 3; i <= sqrt(n); i += 2) { 
		while (n % i == 0) { 
			maxp = i; 
			n = n / i; 
		} 
	} 
	if (n > 2) 
		maxp = n; 

	return maxp; 
} 


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(prime,true,sizeof(prime));
	sieve();
	vector<ll> primelist;
    for(ll i=0;i<max_val;i++){
        if(prime[i])
            primelist.pb(i);
    }
	ll n;
	cin>>n;
	ll *a=new ll[n];
	ll maxi=0;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	ll k;
	cin>>k;

	for(ll i=0;i<n;i++){
		ll max_prime_value=max_prime(a[i]);
		if(max_prime_value<k){
			if(max_prime_value>maxi){
				maxi=max_prime_value;
			}
		}
	}

	if(maxi==0) cout<<0;
	else{
		auto it=upper_bound(primelist.begin(),primelist.end(),maxi);
		cout<<*it;
	}

}