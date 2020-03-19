/*
* @Author: piyush
* @Date:   2020-02-20 08:53:47
* @Last Modified by:   piyush
* @Last Modified time: 2020-02-20 08:53:54
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




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll test;
    cin>>test;
    while(test--){

        ll n;
        cin>>n;
        ll *home=new ll[n];
        ll col=INT_MIN;
        for(ll i=0;i<n;i++){
            cin>>home[i];
            home[i]*=2;
            if(col<home[i]){
                col=home[i];
            }
        }

        ll *p=new ll[n];
        for(ll i=0;i<n;i++){
            cin>>p[i];
        }

        ll **grid =new ll*[n+1];
        for(ll i=0;i<n+1;i++){
            grid[i]=new ll[col+1];
            for(ll j=0;j<col+1;j++){
                if(j!=0 and i==0)
                    grid[i][j]=INT_MAX;
                else{
                    grid[i][j]=0;
                }

            }
        }

        for(ll i=0;i<n;i++){
            for(ll j=1;j<=col;j++){
                if(j>=p[i]) {
                    grid[i + 1][j] = min(grid[i][j], 1+grid[i + 1][j - p[i]]);
                    //cout<<grid[i][j]<<" "<<grid[i + 1][j - p[i]];br;
                }
                else{
                    grid[i+1][j]=grid[i][j];
                }
            }
        }
        ll ans=0,min_val=INT_MAX;
        for(ll i=0;i<n;i++){
            min_val=INT_MAX;
            for(ll j=0;j<n+1;j++){
                if(min_val>grid[j][home[i]]){
                    min_val=grid[j][home[i]];
                }
            }
            ans+=min_val;
        }

        cout<<ans;br;





    }
}