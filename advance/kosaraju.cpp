
/// kosaraju
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

void dfs(vector<ll> *edge,ll x,ll n,deque<ll> &store,bool *visted){
    visted[x]=true;
    for(ll i:edge[x]){
        if(!visted[i]){
            dfs(edge,i,n,store,visted);
        }
    }
    store.push_back(x);
}


void dfs2(vector<ll> *edgeT,ll x,ll n,bool *visted,vector<ll> &temp){
    visted[x]=true;
    temp.pb(x);
    for(ll i:edgeT[x]){
        if(!visted[i]){
            dfs2(edgeT,i,n,visted,temp);
        }
    }
}

vector<vector<ll>> get_com(vector<ll> *edge,vector<ll> *edgeT,ll n){
    deque<ll> store;
    bool *visted=new bool[n];
    for(ll i=0;i<n;i++){
        visted[i]=false;
    }
    for(ll i=0;i<n;i++){
        if(!visted[i]){
            dfs(edge,i,n,store,visted);
        }
    }
    vector<vector<ll>> ans;
    for(ll i=0;i<n;i++){
        visted[i]=false;
    }
    while(!store.empty()){
         ll val=store.back();
         store.pop_back();
         vector<ll> temp;
         if(!visted[val]) {
             dfs2(edgeT, val, n, visted, temp);
             ans.pb(temp);
         }
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n,e;
        cin>>n>>e;
        vector<ll> *edge=new vector<ll>[n];
        vector<ll> *edgeT=new vector<ll>[n];
        ll e1,e2;
        while(e--){
            cin>>e1>>e2;
            edge[e1].pb(e2);
            edgeT[e2].pb(e1);
        }
        vector<vector<ll>> components=get_com(edge,edgeT,n);
        vector<vector<ll>>::iterator pt1=components.begin();
        while(pt1!=components.end()){
            vector<ll> temp=*pt1;
            vector<ll>::iterator pt2=temp.begin();
            while(pt2!=temp.end()){
                cout<<*pt2<<" ";
                pt2++;
            }
            br;
            pt1++;
        }
    }

}
