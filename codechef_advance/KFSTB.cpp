 #include </Users/piyush/Desktop/CP/bits/stdc++.h>
//#include <bits/stdc++.h>
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

void bfs(vector<ll> *edge,ll n, map<ll,ll> &dist,bool *visted,ll start){
    queue<ll> q;
    q.push(start);
    while(!q.empty()){
        ll top=q.front();
        visted[top]=true;
        q.pop();
        for(ll i:edge[top]){
            if(!visted[i]){
                dist[i]+=1;
                q.push(i);
            }
        }
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test_case;
    cin>>test_case;
    while(test_case--){
        ll n,v,s,e;
        cin>>n>>v>>s>>e;
        s--;
        e--;
        vector<ll> *edge=new vector<ll>[n];
        ll e1,e2;
        for(ll i=0;i<v;i++){
            cin>>e1>>e2;
            e1--;
            e2--;
            edge[e1].pb(e2);
        }

        map<ll,ll> dist;
        bool *visted=new bool[n];
        for(ll i=0;i<n;i++){
            visted[i]=false;
        }
        bfs(edge,n,dist,visted,s);
        cout<<dist[e]%mod;br;



    }

}









// // KFSTB
// #include <bits/stdc++.h>
// using namespace std;
 
// #define int long long
// #define all(V) (V).begin(),(V).end()
// #define umap unordered_map
// #define uset unordered_set
// #define br cout<<"\n";
 
// const int MAXN=1e5+10, MOD=1e9+7;
// int n,m;
// vector<int> grf[MAXN];
 
// int bfs(int src,int des){
//     int dis[MAXN]={0};
//     dis[src]=1;
//     bool visited[MAXN]={false};
//     visited[src]=true;
//     queue<int> q; q.push(src);
//     while(!q.empty()){
//         int node = q.front(); q.pop();
//         for(auto nbr: grf[node]){
//             dis[nbr] = (dis[nbr]+dis[node])%MOD;
//             if(!visited[nbr]){
//                 visited[nbr]=true;
//                 q.push(nbr);
//             }
//         }
//     }
//     return dis[des];
// }
 
// signed main()
// {
// //  #ifndef ONLINE_JUDGE
// //      freopen("./input.txt","r",stdin);
// //      freopen("./output.txt","w",stdout);
// //  #endif
//     ios::sync_with_stdio(false); cin.tie(nullptr);
//     int t; cin>>t; while(t--){
//         int src,des;
//         cin>>n>>m>>src>>des;
//         for(int i=1; i<=n; i++){
//             grf[i].clear();
//         }
//         for(int i=1; i<=m; i++){
//             int x,y; cin>>x>>y;
//             grf[x].push_back(y);
// //            grf[y].push_back(x);
//         }
//         int d = bfs(src,des);
//         cout<<d; br;
//     }
 
// } 
