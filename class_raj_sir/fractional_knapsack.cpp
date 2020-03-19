
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
    double val;
    double weight;
};

bool sorting(node l,node r){
    if((l.val/l.weight)>(r.val/r.weight)){
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        ll n,l,r;
    cin>>n;
    node *item=new node[n];
    for(ll i=0;i<n;i++){
        cin>>l>>r;
        item[i].val=l;
        item[i].weight=r;
    }
    sort(item,item+n,sorting);
    ll weight;
    cin>>weight;
    double cost=0;
    for(ll i=0;i<n;i++){
        if(weight>=item[i].weight){
            weight-=item[i].weight;
            cost+=item[i].val;
        }else{
            double temp=weight/item[i].weight;
            weight=0;
            cost+=(temp*item[i].val);
        }
        if(weight==0){
            break;
        }
       }
    cout<<cost;br;
}
