











/////////////////////////////////////////////        TLE using dijkstra
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

#define INF LONG_LONG_MAX
#define N_INF LONG_LONG_MIN

vector<vector<ll>> adj,store;
vector<ll> dist;
vector<bool> visted;

#define INF LONG_LONG_MAX

void dijkstra(ll start){
    priority_queue<ll,vector<ll>,greater<>> yolo;
    dist[start]=0;
    yolo.push(start);
    ll up;
    while(!yolo.empty()){
        up=yolo.top();
        yolo.pop();
        if(visted[up]){
            continue;
        }

        visted[up]=true;
        for(ll i:adj[up]){
            if(dist[up]+1<dist[i]){
                dist[i]=dist[up]+1;
            }
            yolo.push(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n,v;
    cin>>n>>v;

    adj.resize(n);
    ll e1,e2;
    for(ll i=0;i<v;i++){
        cin>>e1>>e2;
        e1-=1;
        e2-=1;
        adj[e1].pb(e2);
        adj[e2].pb(e1);
    }

    ll hosp;
    cin>>hosp;
    vector<ll> temp(n,INF);
    store.resize(hosp);
    unordered_map<ll,ll> index,rindex;
    ll pos=0,x;
    vector<ll> hospital;

    for(ll i=0;i<hosp;i++){
        cin>>x;
        x--;
//        index[x]=pos;
//        rindex[pos]=x;
        hospital.pb(x);
    }
    ll start;
    for(ll i=0;i<hosp;i++){
        start=hospital[i];
        dist.assign(n,INF);
        visted.assign(n, false);
        dijkstra(start);
        store[pos++]=dist;
    }

    ll query;
    cin>>query;
    ll ans;
    while(query--){
        ans=INF;
        cin>>start;
        start--;
        for(ll j=0;j<hosp;j++){
            if(store[j][start]<ans){
                ans=store[j][start];
            }
        }
        if(ans!=INF) {
            cout << ans;
        }
        else{
            cout<<"Dead";
        }
        br;
    }
}
