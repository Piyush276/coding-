#include </Users/piyush/Desktop/CP/bits/stdc++.h>
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



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,l,r;
    cin>>n;
    ll *a=new ll[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll weight;
    cin>>weight;
    for(ll i=0;i<n;i++){
        if(weight>=a[i]){
            cout<<a[i]<<" ";
            weight-=a[i];
        }
    }
    
}
