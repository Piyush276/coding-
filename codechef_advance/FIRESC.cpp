 #include </Users/piyush/Desktop/CP/bits/stdc++.h>
//#include <bits/stdc++.h>
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

void dfs(vector<ll> *a,bool *visted,ll n,vector<ll> &temp,ll start){
    visted[start]=true;
    temp.pb(start);
    for(ll i:a[start]){
        if(!visted[i]){
            dfs(a,visted,n,temp,i);
        }
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test_case;
    cin>>test_case;
    while(test_case--){
        ll n,v;
        cin>>n>>v;
        vector<ll> *a=new vector<ll>[n];
        ll e1,e2;

        for (ll i=0;i<v;i++){
            cin>>e1>>e2;
            e1--;
            e2--;
            a[e1].pb(e2);
            a[e2].pb(e1);
        }
        bool *visted=new bool[n];
        for (ll i=0;i<n;i++){
            visted[i]=false;
        }

        ll ans=1;
        ll dif_comp=0;

        for(ll i=0;i<n;i++){
            if(!visted[i]){
                dif_comp+=1;
                vector<ll> temp;
                dfs(a,visted,n,temp,i);
                ans=((ans%mod)*(temp.size()%mod))%mod;
            }
        }
        cout<<dif_comp<<" "<<ans;br;
    }

}