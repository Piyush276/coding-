
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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        vector<ll> hey={1,2,3,34,5,566,7};
        make_heap(hey.begin(),hey.end());
        print_array(hey,hey.size());

//        priority_queue <ll,vector<ll>,greater<ll> > style;
//        ll n,temp;
//        cin>>n;
//        while(n--){
//            cin>>temp;
//            style.push(temp);
//        }
//        for(ll i=0;i<style.size();i++)
//            cout<<style.at(i)<<" ";

        br;
    }

}