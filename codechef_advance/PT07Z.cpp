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


void dfs(vector<ll> *edge,ll n,bool *visted,ll &maxD,ll tempD,ll &end,ll start){
    visted[start]=true;
    if(maxD<tempD){
        maxD=tempD;
        end=start;
    }
    for(ll i:edge[start]){
        if(!visted[i])
        dfs(edge,n,visted,maxD,tempD+1,end,i);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    vector<ll> *edge=new vector<ll>[n];
    ll e1,e2;
    for(ll i=0;i<n-1;i++){
        cin>>e1>>e2;
        e1--;
        e2--;
        edge[e1].pb(e2);
        edge[e2].pb(e1);
    }

    bool *visted=new bool[n];
    for(ll i=0;i<n;i++){
        visted[i]=false;
    }

    ll maxD=-1,end_1=-1;
    dfs(edge,n,visted,maxD,0,end_1,0);

    for(ll i=0;i<n;i++){
        visted[i]=false;
    }

    ll end_2=-1;
    maxD=-1;
    dfs(edge,n,visted,maxD,0,end_2,end_1);

    cout<<maxD<<" "<<end_1+1<<" "<<end_2+1;br;

}