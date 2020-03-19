/*
* @Author: piyush
* @Date:   2020-03-04 01:00:04
* @Last Modified by:   piyush
* @Last Modified time: 2020-03-04 01:00:05
*/

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

vector<ll> arr;
vector<pair<ll,ll>> tree;


pair<ll,ll> join_node(pair<ll,ll> a, pair<ll,ll> b){
    if(a.first>b.first){
        return a;
    }
    if(a.first<b.first){
        return b;
    }

    return make_pair(a.first,a.second+b.second);

}



void buildtree(ll start,ll end,ll pos=1){
    if(start==end){
        tree[pos]=make_pair(arr[start],1);
        return;
    }

    ll mid=(start+end)/2;
    buildtree(start,mid,2*pos);
    buildtree(mid+1,end,2*pos+1);

    tree[pos]=join_node(tree[2*pos],tree[2*pos+1]);

}


pair<ll,ll> querytree(ll left,ll right,ll start,ll end,ll pos=1){
    if(start>=left and end<=right){
        return tree[pos];
    }

    if(start>right or end<left){
        return make_pair(INT_MIN,0);
    }
    ll mid=(start+end)/2;
    pair<ll,ll> left_side=querytree(left,right,start,mid,2*pos);
    pair<ll,ll> right_side=querytree(left,right,mid+1,end,2*pos+1);

    return join_node(left_side,right_side);

}


void updatetree(ll ind,ll data,ll start,ll end,ll pos=1){
    if(start==end){
        arr[ind]=data;
        tree[pos]=make_pair(data,1);
        return;
    }

    ll mid=(start+end)/2;
    if(ind>=start and ind<=mid){
        updatetree(ind,data,start,mid,2*pos);
    }else{
        updatetree(ind,data,mid+1,end,2*pos+1);
    }

    tree[pos]=join_node(tree[2*pos],tree[2*pos+1]);

}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n,temp;
    cin>>n;

    tree.resize(4*n);

    for(ll i=0;i<n;i++){
        cin>>temp;
        arr.pb(temp);
    }

    buildtree(0,n-1);

    ll query;
    cin>>query;
    ll l,r;
    char type;
    while(query--){
        cin>>type>>l>>r;
        l--;
        if(type=='Q') {
            r--;
            pair<ll, ll> ans = querytree(l, r, 0, n - 1);
            cout << ans.first << " " << ans.second;
            br;
        }
        else{
            updatetree(l,r,0,n-1);          // l is ind and r is val
            print(arr);
        }

    }



}
