#include </Users/piyush/Desktop/CP/bits/stdc++.h>
// #include <bits/stdc++.h>
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


class node {
public:
    ll maxsum;
    ll pfs;
    ll sfs;
    ll sum;
    node(){
        maxsum=INT_MIN;
        pfs=INT_MIN;
        sfs=INT_MIN;
        sum=INT_MIN;
    };
};

node get_values(node l,node r){
    node ans;
    ans.pfs=max(l.pfs,l.sum+r.pfs);
    ans.sfs=max(r.sfs,r.sum+l.sfs);
    ans.sum=l.sum+r.sum;
    ans.maxsum=max(l.maxsum,max(r.maxsum,max(l.sum+r.pfs,max(r.sum+l.sfs,l.sfs+r.pfs))));
    return ans;
}

void buildtree(ll *a,node *tree, ll start,ll end,ll pos=1){
    if(start==end){
        tree[pos].maxsum=a[start];
        tree[pos].sum=a[start];
        tree[pos].pfs=a[start];
        tree[pos].sfs=a[start];
        return;
    }
    ll mid=(start+end)/2;
    buildtree(a,tree,start,mid,2*pos);
    buildtree(a,tree,mid+1,end,2*pos+1);
    tree[pos]=get_values(tree[2*pos],tree[2*pos+1]);
}


node querytree(node *tree,ll left,ll right,ll start,ll end,ll pos=1){
    if(start>=left and end<=right){
        return tree[pos];
    }
    if(start>right or end<left){
        node fake;
        return fake;
    }
    ll mid=(start+end)/2;
    node ln=querytree(tree,left,right,start,mid,2*pos);
    node rn=querytree(tree,left,right,mid+1,end,2*pos+1);

    node ans=get_values(ln,rn);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll *a=new ll[n];
    for(ll i=0;i<n;i++)
    {
     cin>>a[i];
    }
    node *tree=new node[4*n];
    buildtree(a,tree,0,n-1);
    ll query,l,r;
    cin>>query;
    while(query--){
        cin>>l>>r;
        l--;r--;
        node ans=querytree(tree,l,r,0,n-1);
        cout<<ans.maxsum;br;

    }

}
