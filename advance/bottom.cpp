
//#include </Users/piyush/Desktop/CP/bits/stdc++.h>
#include <bits/stdc++.h>
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


void dfs(vector<ll> *edge,ll x,ll n,bool *visted,stack<ll> &store){
    visted[x]=true;
    for(ll i:edge[x]){
        if(!visted[i]){
            dfs(edge,i,n,visted,store);
        }
    }
    store.push(x);
}

void dfs2(vector<ll> *edgeT,ll x,ll n,vector<ll> &temp,bool *visted){
    visted[x]=true;
    temp.pb(x);
    for(ll i:edgeT[x]){
        if(!visted[i]){
            dfs2(edgeT,i,n,temp,visted);
        }
    }
}

vector<vector<ll>> get_comp(vector<ll> *edge,vector<ll> *edgeT,ll n){
    stack<ll> store;
    bool *visted=new bool[n];
    for(ll i=0;i<n;i++)
    {
        visted[i]=false;
    }
    for(ll i=0;i<n;i++)
    {
        if(!visted[i]){
            dfs(edge,i,n,visted,store);
        }
    }
    for(ll i=0;i<n;i++)
    {
        visted[i]=false;
    }
    vector<vector<ll>> ans;
    while(!store.empty()){
        vector<ll> temp;
        ll val=store.top();
        store.pop();
        if(!visted[val]){
            dfs2(edgeT,val,n,temp,visted);
            ans.pb(temp);
        }
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    while(true){
        ll n,k;
        cin>>n;
        if(n==0)break;
        cin>>k;
        vector<ll> *edge=new vector<ll>[n];
        vector<ll> *edgeT=new vector<ll>[n];
        ll e1,e2;
        vector<pair<ll,ll>> storing;
        while(k--){
            cin>>e1>>e2;
            e1--;
            e2--;
            storing.pb(make_pair(e1,e2));
            edge[e1].pb(e2);
            edgeT[e2].pb(e1);
        }
        vector<vector<ll>> comp=get_comp(edge,edgeT,n);
        vector<vector<ll>>::iterator pt1=comp.begin();
        ll pos=0;
        map<ll,ll> comppos;
        while(pt1!=comp.end()){
            vector<ll> temp1=*pt1;
            vector<ll>::iterator pt2=temp1.begin();
            while(pt2!=temp1.end()){
                comppos[*pt2]=pos;
               // cout<<*pt2<<" ";
                pt2++;
            }
          // br;
            pos++;
            pt1++;
        }

        bool *visted=new bool[n];
        for(ll i=0;i<n;i++)
        {
            visted[i]=true;
        }
        map<ll,ll> checking;
        auto pt=storing.begin();
        while (pt!=storing.end()){
            pair<ll,ll> tem=*pt;
            if(comppos[tem.first]!=comppos[tem.second]){
                visted[tem.first]=false;
                checking[comppos[tem.first]]=1;
            }
            pt++;
        }
        for(ll i=0;i<n;i++)
        {
            if(visted[i] and checking[comppos[i]]!=1){
                cout<<i+1<<" ";
            }
        }
        br;

    }

}