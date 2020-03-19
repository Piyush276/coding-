/*
* @Author: piyush
* @Date:   2020-02-28 09:56:27
* @Last Modified by:   piyush
* @Last Modified time: 2020-02-28 09:56:29
*/

#include </Users/piyush/Desktop/CP/bits/stdc++.h>
// #include <bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair<long long,long long> pll;


#define F first
#define S second
#define print(x) for(auto iuiuiuiuiui:x){ cout<<iuiuiuiuiui<<" ";}br;
#define print_array(array,size) for(ll i=0;i<size;i++){ cout<<array[i]<<" ";}br;
#define br cout<<"\n"
#define max_val 1000000
#define mod 1000000007
#define pb(a) push_back(a)
#define mp(asd,fgh) make_pair(asd,fgh)
#define all(c) c.begin(),c.end()
#define check_ cout<<"yo";

#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

map<ll,ll> state;       /// 1 for not visted 1 for visted 2 for processed

vector<vector<ll>> adj;

stack<ll> ans;

vector<ll> papa;
vector<ll> ranking;

bool flag=false;
void dfs(ll start){
    for(ll i:adj[start]){
        if(state[i]==1){
            flag=true;
            return;
        }
        if(state[i]!=2){
            state[i]=1;
            dfs(i);
        }
    }
    state[start]=2;
    ans.push(start);
}

void make_set(ll i){
    papa[i]=i;
    ranking[i]=0;
}

ll find_set(ll a){
    if(a==papa[a]){
        return a;
    }return papa[a]=find_set(papa[a]);
}

void union_set(ll a,ll b){
    ll x=find_set(a);
    ll y=find_set(b);

    if(x!=y){
        if(ranking[x]<ranking[y]){
            swap(x,y);
        }
        papa[y]=x;

        if(ranking[x]==ranking[y]){
            ranking[x]++;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,v;
    cin>>n>>v;

    adj.resize(n);
    ll e1,e2;
    for(ll i=0;i<v;i++){
        cin>>e1>>e2;
        --e1;
        --e2;
        adj[e1].pb(e2);
    }
    vector<ll> temp;
    for(ll i=0;i<n;i++){
        temp=adj[i];
        sort(temp.begin(),temp.end(),greater<ll>());
        adj[i]=temp;
    }
    for(ll i=n-1;i>=0;i--){
        if(state[i]==0){
            state[i]=1;
            dfs(i);
            if(flag)
                break;
        }
    }

    if(flag){
        cout<<"Sandro fails.";br;
    }else{
        while(!ans.empty()){
            cout<<ans.top()+1<<" ";
            ans.pop();
        }
    }



}
