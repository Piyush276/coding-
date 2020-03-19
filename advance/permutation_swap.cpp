
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


void component(vector<ll> *edge,ll x,ll n,bool *visted,vector<ll> &temp){
    visted[x]=true;
    temp.pb(x);
    for(ll i:edge[x]){
        if(!visted[i]){
            component(edge,i,n,visted,temp);
        }
    }
}

vector<vector<ll>> get_com(vector<ll> *edge,ll n){
    vector<vector<ll>> ans;
    bool *visted=new bool[n];
    for(ll i=0;i<n;i++){
        visted[i]=false;
    }
    for(ll i=0;i<n;i++){
        if(!visted[i]){
            vector<ll> temp;
            component(edge,i,n,visted,temp);
            ans.pb(temp);
        }
    }
    return ans;
}

bool checkans(map<ll,ll> position,map<ll,ll> compos,ll *a,ll *b,ll n){
    for(ll i=0;i<n;i++){
        if(a[i]!=b[i]){
            if(compos[i]!=compos[position[b[i]]]){
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    map<ll,ll> position;
    map<ll,ll> compos;
    while(t--){
        ll n,q;
        position.clear();
        compos.clear();
        cin>>n>>q;
        ll *a=new ll[n];
        ll *b=new ll[n];
        ll pos=0;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            position[a[i]]=pos++;
        }
        for(ll i=0;i<n;i++){
            cin>>b[i];
        }
        vector<ll> *edge=new vector<ll>[n];

        ll e1,e2;
        while(q--){
            cin>>e1>>e2;
            e1--;
            e2--;
            edge[e1].pb(e2);
            edge[e2].pb(e1);
        }
        vector<vector<ll>> componets=get_com(edge,n);
        vector<vector<ll>>::iterator pt1=componets.begin();
        pos=0;
        while(pt1!=componets.end()){
            vector<ll> temp=*pt1;
            vector<ll>::iterator pt2=temp.begin();
            while(pt2!=temp.end()){
                compos[*pt2]=pos;
                pt2++;
            }
            pt1++;
            pos++;
        }

        if(checkans(position,compos,a,b,n)){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
        br;

    }

}

