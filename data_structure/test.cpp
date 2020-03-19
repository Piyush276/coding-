#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define br cout<<"\n"
#define max_val 100000


bool check(bool *visted,ll n){
    for(ll i=0;i<n;i++){
        if(visted[i]==false){
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll n,edge;
    cin>>n>>edge;

    ll **e=new ll*[n];

    ll **mst=new ll*[n];

    for(ll i=0;i<n;i++){
        e[i]=new ll[n];
    }
    for(ll i=0;i<n;i++){
        mst[i]=new ll[n];
    }
    ll e1,e2,w;
    for(ll i=0;i<edge;i++){
        cin>>e1>>e2;
        e[e1][e2]=1;
        e[e2][e1]=1;
    }

    bool *visted=new bool[n];
    for(ll i=0;i<n;i++){
        visted[i]=false;
    }


    bool *notvisted=new bool[n];
    for(ll i=0;i<n;i++){
        notvisted[i]=true;
    }

    visted[0]=true;
    notvisted[0]=false;

    ll *shortest_path=new ll[n];
    for(ll i=0;i<n;i++){
       shortest_path[i]=0;
    }

    while(check(visted,n)){
        
        ll pos1=LONG_LONG_MAX,pos2=LONG_LONG_MAX,weight=LONG_LONG_MAX;
        for(ll i=0;i<n;i++){
            if(visted[i]==true) {
                for (ll j = 0; j < n; j++) {
                    if (e[i][j] != 0 and visted[j] == false) {
                        if (weight > (e[i][j]+shortest_path[i])) {
                            weight = e[i][j]+shortest_path[i];
                            shortest_path[j]=weight;
                            pos1 = i;
                            pos2 = j;
                        }
                    }
                }
            }
        }
     //   cout<<pos2<<" "<<pos1<<" "<<weight<<endl;
        mst[pos1][pos2]=weight;
        mst[pos2][pos1]=weight;

        visted[pos2]=true;

    }

    for(ll i=0;i<n;i++){
        visted[i]=false;
    }
    visted[0]=true;
    for(ll i=0;i<n;i++){
        cout<<i<<" "<<shortest_path[i]<<endl;
    }
}

