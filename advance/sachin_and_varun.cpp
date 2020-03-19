
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

class triplet{
public:
    ll x;
    ll y;
    ll gcd;
};

triplet solve(ll a,ll b){
    if(b==0){
        triplet ans;
        ans.x=1;
        ans.y=0;
        ans.gcd=a;
        return ans;
    }
    triplet smallans=solve(b,a%b);
    triplet ans;
    ans.x=smallans.y;
    ans.y=smallans.x-(a/b)*smallans.y;
    ans.gcd=smallans.gcd;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll a,b,d;
        cin>>a>>b>>d;
        triplet ans;
        if(b>a)
        ans=solve(a,b);
        else
        ans=solve(b,a);
        if(d%ans.gcd!=0){
            cout<<"0";br;
            continue;
        }
        ans.x=ans.x*(d/ans.gcd);
        ans.y=ans.y*(d/ans.gcd);

        ll p1=floor(1.0*ans.x/(b/ans.gcd));
        ll p2=ceil((-1.0*ans.y)/(a/ans.gcd));
        if (p1<p2) {
            cout<<"0";br;
            continue;
        }
        cout<<p1-p2+1;br;
    }

}


