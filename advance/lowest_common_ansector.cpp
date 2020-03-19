/// instead of linear searching use segment tree
/// 
/// 0 based indexing remember



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

void euler_path(vector<ll> *edge,ll n,vector<ll> &ans, bool *visted,ll x){
    visted[x]=true;
    ans.pb(x);
    for(ll i:edge[x]){
        if(!visted[i]){
            euler_path(edge,n,ans,visted,i);
            ans.pb(x);
        }
    }
}


vector<ll> get_path(vector<ll> *edge,ll n,map<ll,ll> &mapping_pos){
    bool *visted=new bool[n];
    for(ll i=0;i<n;i++){
        visted[i]=false;
    }
    vector<ll> ans;
    vector<ll> real_ans;
    euler_path(edge,n,ans,visted,0);
  //  print(ans);
    ll pos=1;
    for(ll i:ans){
        if(mapping_pos[i]==0){
            mapping_pos[i]=pos;
            pos+=1;
        }
        real_ans.pb(mapping_pos[i]);
    }
    return real_ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n,q;
        cin>>n>>q;
        vector<ll> *edge=new vector<ll>[n];
        ll e1,e2;
        while(q--){
            cin>>e1>>e2;
            edge[e1].pb(e2);
            edge[e2].pb(e1);
        }
        map<ll,ll> mapping_pos;
        map<ll,ll> mapping_value;
        vector<ll> euler_path=get_path(edge,n,mapping_pos);
       // print(euler_path);
        auto pt=mapping_pos.begin();
        while(pt!=mapping_pos.end()){
            pair<ll,ll> temp=*pt;
            mapping_value[temp.second]=temp.first;
            pt++;
        }
        ll query;
        cin>>query;
        while(query--){
            cin>>e1>>e2;
//            e1--;
//            e2--;
            e1=mapping_pos[e1];
            e2=mapping_pos[e2];
            cout<<e1<<" "<<e2;br;
            ll pos1=0,pos2=0;
            for(ll i:euler_path){
                if(i==e1) break;
                 pos1++;
            }
            for(ll i:euler_path){
                if(i==e2) break;
                pos2++;
            }



            ll mini=euler_path[min(pos1,pos2)];
            if(pos1>pos2){
                swap(pos1,pos2);
            }


            for(ll i=pos1;i<pos2;i++){
                cout<<euler_path[i]<<" ";
                if(mini>euler_path[i]){
                    mini=euler_path[i];
                }
            }
            
            br;
            cout<<mapping_value[mini];br;


        }
    }

}