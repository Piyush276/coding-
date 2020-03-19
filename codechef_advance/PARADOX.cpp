/// incomplete. no idea 

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


/// 0 not used 1 in stack and 2 in complete

map<ll,ll> dp;
map<pair<ll,ll>,ll> store;      // s->e    1 false 2 true

bool count_false(vector<ll> *edge,ll n,map<ll,ll> &visit,ll start,ll end, ll &temp){
    if(start==end){
        return true;
    }
    visit[start]=1;
    for(ll i:edge[start]){
        if(visit[i]==0){
            pair<ll,ll> val;
            val=make_pair(start,i);
            if(store[val]==1){
                if(count_false(edge,n,visit,i,end,temp+1))
                    return true;
            }else{
                if(count_false(edge,n,visit,i,end,temp))
                    return true;
            }
        }
    }
    return false;
}


bool count_odd_false_in_graph(vector<ll> *edge,ll n,bool *visted,ll start=0){
    stack<ll> s;
    s.push(start);
    dp[start]=1;
    while(!s.empty()){
        ll top_val=s.top();
        visted[top_val]=true;
        dp[top_val]=2;
        s.pop();

        for(ll i:edge[top_val]){
            if(!visted[i]){
                if(dp[i]==1){
                    ll temp=1;
                    map<ll,ll> visit;   // 0 for not visted 1 for visit
                    count_false(edge,n,visit,top_val,i,temp);
                    if(temp%2!=0){
                        return true;
                    }
                }
                s.push(i);
                dp[i]=1;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test_case=1;
    while(test_case!=0) {
        dp.clear();
        store.clear();
        cin >> test_case;
        ll e1=0;
        vector<ll> *edge=new vector<ll>[test_case];
        string val;
        bool flag=true;
        while (test_case--) {
            ll e2;
            cin>>e2>>val;
            e2--;
            edge[e1].pb(e2);
            pair<ll,ll> val;
            val=make_pair(e1,e2);
            if(val=="false")
                store[val]=1;
            else
                store[val]=2;
            ++e1;
        }
        bool *visted=new bool[test_case];
        for(ll i=0;i<test_case;i++){
            visted[i]=false;
        }
        if(count_odd_false_in_graph(edge,n,visted)){
            cout<<"PARADOX";
        }else{
            cout<<"NOT PARADOX";
        }
        br;
    }
        


}
