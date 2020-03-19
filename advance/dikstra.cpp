

// #include </Users/piyush/Desktop/CP/bits/stdc++.h>
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

class node{
public:
    ll s;
    ll d;
    ll w;
    node(){
        w=INT_MAX;
    }
};

ll  *dikstra(ll **edge,ll n.ll start=0){
    bool *visted=new bool[n];
    for(ll i=0;i<n;i++)
        visted[i]=false;
    visted[start]=true;
    ll count=0;

    ll *parent=new ll[n];
    for(ll i=0;i<n;i++)
        parent[i]=i;

    ll *weight=new ll[n];
    for(ll i=0;i<n;i++)
        weight[i]=0;

    while(count!=n-1){
        node mini;
        for(ll i=0;i<n;i++){
            if(visted[i]){
                for(ll j=0;j<n;j++){
                    if(edge[i][j]!=0 and !visted[j]){
                        if(mini.w>edge[i][j]+weight[i]){
                            mini.s=i;
                            mini.d=j;
                            mini.w=edge[i][j]+weight[i];
                        }
                    }
                }
            }
        }
        visted[mini.d]=true;
        parent[mini.d]=mini.s;
        weight[mini.d]=mini.w;
        count++;
    }
    return weight;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,e;
    cin>>n>>e;
    ll **edge=new ll*[n];
    for(ll i=0;i<n;i++){
    	edge[i]=new ll[n];
    	for(ll j=0;j<n;j++){
    		edge[i][j]=0;
    	}
    }
   ll e1,e2,w;
    while(e--){
        cin>>e1>>e2>>w;
        edge[e1][e2]=w;
        edge[e2][e1]=w;
    }
    ll *weight=dikstra(edge,n);
    for(ll i=0;i<n;i++)
    {
        cout<<i<<" "<<weight[i];br;
    }


}



