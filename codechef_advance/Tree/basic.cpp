/*
* @Author: piyush
* @Date:   2020-02-17 01:39:00
* @Last Modified by:   piyush
* @Last Modified time: 2020-02-18 13:39:02
*/


#include </Users/piyush/Desktop/CP/bits/stdc++.h>
// #include <bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair<long long,long long> pll;


#define check_ cout<<"yo";
#define print(x) for(auto iuiuiuiuiui:x){ cout<<iuiuiuiuiui<<" ";}br;
#define print_array(array,size) for(ll i=0;i<size;i++){ cout<<array[i]<<" ";}br;
#define br cout<<"\n"
#define max_val 1000000
#define mod 1000000007
#define pb(a) push_back(a)
#define mp(asd,fgh) make_pair(asd,fgh)
#define all(c) c.begin(),c.end()

#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

class node{
public:
    ll val;
    node *left;
    node *right;
};

node *newnode(ll data){
    node *temp=new node();
    temp->left=NULL;
    temp->right=NULL;
    temp->val=data;
    return temp;
}

void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}


void insert(node *&root,ll data){
    if(root==NULL){
        root=getNode(data);
        return;
    }
    queue<node *> 
    q.push(root);
    while(!q.empty()){
        node *up=q.front();
        q.pop();
        if(up->left==NULL){
            up->left=getNode(data);
            return;
        }
        q.push(up->left);
        if(up->right==NULL){
            up->right=getNode(data);
            return;
        }
        q.push(up->right);
    }

}


void deletion(node *root,ll data){
    queue<node *> q;
    q.push(root);
    node *pos=NULL;
    node *up;
    map<node *,node *> papa;

    while(!q.empty()) {
        up = q.front();
        //cout<<up->val<<" ";
        q.pop();
        if (up->val == data) {
            pos = up;
        }
        if (up->left!=NULL) {
            papa[up->left]=up;
            q.push(up->left);
        }

        if (up->right!=NULL) {
            papa[up->right]=up;
            q.push(up->right);
        }

    }

    //br;
    if(pos!=NULL) {
        swap(pos->val, up->val);

        if (papa[up]->left == up) {
            papa[up]->left = NULL;
        }
        if (papa[up]->right == up) {
            papa[up]->right = NULL;
        }
    }
}


void all_path(node *root,vector<vector<ll>> &path,vector<ll> temp={}){
    if(root==NULL){
        return;
    }
    if(root->left==NULL and root->right==NULL){
        temp.pb(root->val);
        path.pb(temp);
        return;
    }
    temp.pb(root->val);
    all_path(root->left,path,temp);
    all_path(root->right,path,temp);
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//    node *root=newnode(10);
//    root->left=newnode(11);
//    root->left->left=newnode(7);
//    root->right=newnode(9);
//    root->right->left=newnode(15);
//    root->right->right=newnode(8);
//
//    inorder(root);
//    br;
//
//    insert(root,12);
//    inorder(root);
//    br;

    node *root=newnode(3);
    root->left=newnode(2);
    root->right=newnode(4);
    root->left->left=newnode(1);
    root->left->right=newnode(3);
    root->right->right=newnode(5);

    deletion(root,12);
    inorder(root);
    br;

    vector<vector<ll>> path;
    all_path(root,path);

    for(vector<ll> i:path){
        for(ll j:i){
            cout<<j<<" ";
        }
        br;
    }


}