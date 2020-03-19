/*
* @Author: piyush
* @Date:   2020-02-20 09:17:00
* @Last Modified by:   piyush
* @Last Modified time: 2020-02-20 09:30:25
*/

#include </Users/piyush/Desktop/CP/bits/stdc++.h>
// #include <bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair<long long,long long> pll;



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


bool compare(pair<ll,ll> a,pair<ll,ll> b){
    return abs(a.first-a.second)>abs(b.first-b.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,andy,bob;
    cin>>n>>andy>>bob;
    vector<pair<ll,ll>> tip;  /// tip.first andy and tip.second is bob
    ll e1,e2;
    for(ll i=0;i<n;i++){
        cin>>e1;
        tip.pb(make_pair(e1,0));
    }
    for(ll i=0;i<n;i++){
        cin>>tip[i].second;
    }

    sort(tip.begin(),tip.end(),compare);
    ll ans=0;
    for(ll i=0;i<n;i++){
        if(tip[i].first>tip[i].second and andy>0){
            ans+=tip[i].first;
            andy--;
        }
        else if(tip[i].first<tip[i].second and bob>0){
            ans+=tip[i].second;
            bob--;
        }
        else{
            if(andy!=0){
                ans+=tip[i].first;
                andy--;
            }else if(bob!=0){
                ans+=tip[i].second;
                bob--;
            }
        }
    }

    cout<<ans;



}