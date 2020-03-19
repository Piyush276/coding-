
#include </Users/piyush/Desktop/CP/bits/stdc++.h>
using namespace std;
typedef long long ll;
#define br cout<<"\n"
#define pb push_back
#define max_val 1000



#define print(x) for(auto iuiuiuiuiui:x){ cout<<iuiuiuiuiui<<" ";}br;
#define print_array(array,size) for(ll i=0;i<size;i++){ cout<<array[i]<<" ";}br;


void solve(vector<ll> *edge,ll n,vector<vector<ll>> &paths,bool visted[max_val],int end,int start=0,vector<ll> path={}){
    if(start==end){
        paths.pb(path);
        return;
    }
    visted[start]=true;
    for(ll i:edge[start]){
        if(!visted[i]){
            path.pb(i);
            solve(edge,n,paths,visted,end,i,path);
            path.pop_back();
        }
    }

}

bool comp(vector<ll> a,vector<ll> b){
    if(a.size()<b.size())
        return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        ll n,e;
        cin>>n>>e;
        vector<ll> *edge=new vector<ll>[n];
        ll e1,e2;
        while(e--){
            cin>>e1>>e2;
            edge[e1].pb(e2);
            edge[e2].pb(e1);
        }
        vector<vector<ll>> paths;
        bool visted[max_val];
        for(ll i=0;i<n;i++){
            visted[i]=false;
        }
        ll starting_pos,ending_pos;
        cin>>starting_pos>>ending_pos;
        vector<ll> path;
        path.pb(starting_pos);
        solve(edge,n,paths,visted,ending_pos,starting_pos,path);
        sort(paths.begin(),paths.end(),comp);
        vector<vector<ll>>::iterator pt=paths.begin();
        while(pt!=paths.end()){
            vector<ll> temp=*pt;
            vector<ll>::iterator tempp=temp.begin();
            while(tempp!=temp.end()){
                cout<<*tempp<<" ";
                tempp++;
            }
            br;
            pt++;
        }


    }
}
