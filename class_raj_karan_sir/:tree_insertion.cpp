 #include </Users/piyush/Desktop/CP/bits/stdc++.h>
/*
* @Author: piyush
* @Date:   2020-01-29 15:41:22
* @Last Modified by:   piyush
* @Last Modified time: 2020-02-04 23:15:02
*/


//#include<bits/stdc++.h>
 using namespace std;

#define br cout<<endl
 struct node{
     int data;
     node *left,*right;
 };
 node *insertNode(int num){
     node *temp = new node();
     temp->data= num;
     temp->left = NULL;
     temp->right = NULL;
     return temp;
 }
 void print(node *root){
     queue<node *>q;
     q.push(root);
     while(!q.empty()){
         node *temp = q.front();
         q.pop();
         cout<<temp->data<<" ";
         if(temp->left)
             q.push(temp->left);
         if(temp->right)
             q.push(temp->right);
     }
 }

 void del_node(node *root,int val){
     node *pos=NULL,*store=NULL;
     node *cur=root;
     queue<node *> temp;
     temp.push(cur);
     map<node *,node *> papa;
     while(!temp.empty()){
         store=temp.front();
         temp.pop();
         if(store->left){
             temp.push(store->left);
             papa[store->left]=store;
         }
         if(store->right){
             temp.push(store->right);
             papa[store->right]=store;
         }
         if(store->data==val){
             pos=store;
         }
     }
     //cout<<pos->data<<" "<<store->data;

     swap(pos->data,store->data);
     node *parent=papa[store];
     if(parent->left==store){
         parent->left=NULL;
     }
     if(parent->right==store){
         parent->right=NULL;
     }



 }

 void del_node_with_style(node *root,int val){              // o(1)
     node **pos=NULL,**store=NULL;
     node **cur=&root;
     queue<node **> temp;
     temp.push(cur);
     while(!temp.empty()){
         store=temp.front();
         temp.pop();
         if((*store)->left){
             node **tempp=&((*store)->left);
             temp.push(tempp);
         }
         if((*store)->right){
             node **tempp=&((*store)->right);
             temp.push(tempp);
         }
         if((*store)->data==val){
             pos=store;
         }
     }

     swap((*pos)->data,(*store)->data);


     (*store)=NULL;
 }


 



 int main(int argc, char const *argv[])
 {
     // freopen("/mnt/extra/programming/io/input.txt","r",stdin);
     // freopen("/mnt/extra/programming/io/output.txt","w",stdout);
     node *root = NULL;
     int n;
     cin>>n;
     queue<node *> q;
     q.push(root);
     while(n--){
         int num;
         cin>>num;
         node *temp = q.front();
         if(!temp){
             root = insertNode(num);
             q.pop();
             q.push(root);
         }
         else if(!temp->left){
             temp->left = insertNode(num);
             q.push(temp->left);
         }
         else{
             temp->right = insertNode(num);
             q.push(temp->right);
             q.pop();
         }
     }
     print(root);
        br;
//     cout<<"Enter value to del -: ";
//     int value;
//     cin>>value;
     del_node_with_style(root,2);
     br;
     print(root);
     return 0;
 }



