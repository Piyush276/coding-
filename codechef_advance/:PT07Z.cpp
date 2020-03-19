/*
* @Author: piyush
* @Date:   2020-01-30 23:54:14
* @Last Modified by:   piyush
* @Last Modified time: 2020-01-31 02:55:04
*/

/// check tree or not ....   cycle detection in undirected graph


 #include </Users/piyush/Desktop/CP/bits/stdc++.h>
 // #include <bits/stdc++.h>
 typedef long long ll;

 using namespace std;

 typedef vector<vector<ll>> vvl;
 typedef vector<ll> vll;


 #define print(x) for(auto iuiuiuiuiui:x){ cout<<iuiuiuiuiui<<" ";}br;
 #define print_array(array,size) for(ll i=0;i<size;i++){ cout<<array[i]<<" ";}br;
 #define br cout<<"\n"
 #define max_val 1000000
 #define mod 1000000007
 #define pb(a) push_back(a)

 #define FILE_READ_IN freopen("input.txt","r",stdin);
 #define FILE_READ_OUT freopen("output.txt","w",stdout);

void dfs(vector<ll> *edge,bool *visted,ll start){
    visted[start]=true;
    for(ll i:edge[start]){
        if(!visted[i]){
            dfs(edge,visted,i);
        }
    }
}

/////////// -1 , 0 , 1 

bool detect_cycle(vector<ll> *edge,bool *visted,ll n){
    queue<ll> q;
    q.push(0);
    ll *state=new ll[n];
    for(ll i=0;i<n;i++){
        state[i]=-1;
    }
    state[0]=0;

    ll front;

    while(!q.empty()){
        front=q.front();
        q.pop();
        state[front]=1;
        for(ll i:edge[front]){
            if(state[i]==0){
                return true;                    //// cycle detected
            }
            if(state[i]==-1){
                q.push(i);
                state[i]=0;
            }
        }
    }
    return false;

}


 int main() {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     ll test_case;
     test_case=1;
     while(test_case--) {
        ll n,v;
        cin>>n>>v;
        vector<ll> *edge=new vector<ll>[n];
        ll e1,e2;
        for(ll i=0;i<v;i++){
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

        ///  it should not be disconnected

        ll dif_comp=0;
        for(ll i=0;i<n;i++){
            if(!visted[i]){
                dif_comp+=1;
                dfs(edge,visted,i);
                if(dif_comp>=2){
                    break;
                }
            }
        }

        if(dif_comp>1){
            cout<<"NO";br;
            continue;
        }

        /////  it should not contain cycles

        if(detect_cycle(edge,visted,n)){
            cout<<"NO";br;
        }else{
            cout<<"YES";br;
        }

     }

 }
