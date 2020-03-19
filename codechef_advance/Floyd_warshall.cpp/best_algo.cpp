/*
* @Author: piyush
* @Date:   2020-02-29 00:05:10
* @Last Modified by:   piyush
* @Last Modified time: 2020-03-01 11:31:50
*/






/////////////////////////////////////////////////////////  NOT COMPLETE
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


vector<vector<ll>> adj_mat,next_val,dp;
vector<ll> temp;




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n,v;
    cin>>n>>v;

    temp.assign(n,-1);
    adj_mat.resize(n);
    next_val.resize(n);
    dp.resize(n);


    for(ll i=0;i<n;i++){
        adj_mat[i]=temp;
        next_val[i]=temp;
        dp[i]=temp;
    }

    ll e1,e2,w;
    for(ll i=0;i<v;i++){
        cin>>e1>>e2>>w;
        adj_mat[e1][e2]=w;
        dp[e1][e2]=w;
    }

    for(ll k=0;k<n;k++){
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(dp[i][k]+dp[k][j]< dp[i][j]){
                    dp[i][j]=dp[i][k]+dp[k][j];
                    next_val[i][j]=next_val[i][k];
                }
            }
        }
    }







}