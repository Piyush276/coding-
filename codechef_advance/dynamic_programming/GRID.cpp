/*
* @Author: piyush
* @Date:   2020-02-20 09:14:26
* @Last Modified by:   piyush
* @Last Modified time: 2020-02-20 09:14:29
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




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll test;
    cin >> test;
    while (test--) {

        ll n;
        cin >> n;
        char **grid = new char *[n];
        ll *dp = new ll[n];

        for (ll j = 0; j < n; j++) {
            dp[j] = 0;
        }

        for (ll i = 0; i < n; i++) {
            grid[i] = new char[n];
            for (ll j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        ll count=0;
        for(ll i=n-1;i>=0;i--){
            for(ll j=n-1;j>=0;j--){
                if(grid[i][j]=='#'){
                    break;
                }
                else{
                    if(dp[j]==0){
                        count++;
                    }
                }
            }
            // merging
            for(ll j=n-1;j>=0;j--){
                if(grid[i][j]=='#'){
                    dp[j]=1;
                }
            }
        }

        cout<<count;br;


    }
}