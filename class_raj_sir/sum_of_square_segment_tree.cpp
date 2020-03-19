

#include </Users/piyush/Desktop/CP/bits/stdc++.h>
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

class node{
public:
	ll val;
	ll type;
	node(){
		val=0;
		type=-1;
	}
};

void buildtree(ll *a, ll *tree, ll start, ll end,ll pos=1){
	if(start==end){
		tree[pos]=a[start]*a[start];
		return;
	}
	ll mid=(start+end)/2;
	buildtree(a,tree,start,mid,2*pos);
	buildtree(a,tree,mid+1,end,2*pos+1);
	tree[pos]=tree[2*pos]+tree[2*pos+1];
}

void updatetree(ll *a,ll *tree,node *lazy, ll type,ll val,ll left, ll right, ll start, ll end,ll pos=1){
	if(lazy[pos].val!=0){
		if(lazy[pos].type==1){
			tree[pos]+=lazy[pos].val;
			if(start!=end){
				lazy[2*pos].val+=lazy[pos].val;
				lazy[2*pos+1].val+=lazy[pos].val;
				lazy[2*pos].type=1;
				lazy[2*pos+1].type=1;

			}
		}else{
			tree[pos]=lazy[pos].val;
			if(start!=end){
				lazy[2*pos].val=lazy[pos].val;
				lazy[2*pos+1].val=lazy[pos].val;
				lazy[2*pos].type=0;
				lazy[2*pos+1].type=0;
			}

		}
		lazy[pos].val=0;
		lazy[pos].type=-1;
	}

	if(start>=left and end<=right){
		if(type==1){
			tree[pos]+=val;
			if(start!=end){
					lazy[2*pos].val+=val;
					lazy[2*pos+1].val+=val;
					lazy[2*pos].type=1;
					lazy[2*pos+1].type=1;
				}
		}
		else{
			tree[pos]=val;
			if(start!=end){
					lazy[2*pos].val=val;
					lazy[2*pos+1].val=val;
					lazy[2*pos].type=0;
					lazy[2*pos+1].type=0;
				}
		}
		return;
	}


	if(start>right or end<left){
		return;
	}

	ll mid=(start+end)/2;
	updatetree(a,tree,lazy,type,val,left,right,start,mid,2*pos);
	updatetree(a,tree,lazy,type,val,left,right,mid+1,end,2*pos+1);
	if(type==1){
		tree[pos].val+=(tree[2*pos].val+val*val+2*val*sqrt(tree[2*pos])+tree[2*pos+1]+val*val+2*val*sqrt(tree[2*pos+1]));
	}else{
		tree[pos].val=(end-start+1)*val*val;
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	ll n,q,temp,l,r,val;
    while(t--){
        cin>>n>>q;
        ll *a=new ll[n];
        for(ll i=0;i<n;i++){
        	cin>>a[i];
        }
        ll *tree=new ll[4*n];
        node *lazy=new node[4*n];
        buildtree(a,tree,0,n-1);
  		while(q--){
  			cin>>temp>>l>>r;
  			l--;
  			r--;
  			if(temp==2){
  				cout<<querytree(tree,lazy,l,r,0,n-1);br;
  			}else{
  				cin>>val;
  				updatetree(a,tree,lazy,temp,val,l,r,0,n-1);
  			}
  		}
    }

}