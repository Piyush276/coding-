
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





int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n;
    cin>>n;
    ll *preorder=new ll[n];
    ll *postorder=new ll[n];
    ll *inorder=new ll[n];
    
    for(ll i=0;i<n;i++){
        cin>>preorder[i];
    }
    
    for(ll i=0;i<n;i++){
        cin>>postorder[i];
    }
    
    for(ll i=0;i<n;i++){
        cin>>inorder[i];
    }
    
    
    
    
    delete [] preorder;
    delete [] postorder;
    delete [] inorder;



}
/*
* @Author: piyush
* @Date:   2020-03-03 12:10:11
* @Last Modified by:   piyush
* @Last Modified time: 2020-03-03 12:10:12
*/
