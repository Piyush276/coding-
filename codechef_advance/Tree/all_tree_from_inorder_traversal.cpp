/*
* @Author: piyush
* @Date:   2020-02-18 01:36:16
* @Last Modified by:   piyush
* @Last Modified time: 2020-02-18 01:36:34
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
class node{
public:
    ll val;
    node *left;
    node *right;

    node(ll data){
        val=data;
        left=NULL;
        right=NULL;
    }
};

vector<node *> all_possible_tree(ll *a,ll start,ll end){
    vector<node *> trees;
    if(start>end){
        trees.push_back(NULL);
        return trees;
    }
    for(ll i=start;i<=end;i++){
        vector<node *> ltrees=all_possible_tree(a,start,i-1);
        vector<node *> rtrees=all_possible_tree(a,i+1,end);
        for(ll j=0;j<ltrees.size();j++){
            for(ll k=0;k<rtrees.size();k++){
                node *temp=new node(a[i]);
                temp->left=ltrees[j];
                temp->right=rtrees[k];
                trees.push_back(temp);
            }
        }
    }

    return trees;
}

void preorder(node *root){
    if (root != NULL)
    {
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin>>n;
    ll *a=new ll[n];
    for(ll i=0;i<n;i++) {
        cin >> a[i];
    }
    vector<node *> ans=all_possible_tree(a,0,n-1);

    for(ll i=0;i<ans.size();i++){
        preorder(ans[i]);
        br;
    }


    delete [] a;
}
