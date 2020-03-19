/*
* @Author: piyush
* @Date:   2020-02-18 13:35:59
* @Last Modified by:   piyush
* @Last Modified time: 2020-02-18 13:37:42
*/
// C++ program to print top 
// view of binary tree 
// 
// 
////////////////////////////////////////   top view geeks for geeks



#include<bits/stdc++.h> 
using namespace std; 

struct Node{ 
	Node * left; 
	Node* right; 
	int data; 
}; 

Node* newNode(int key){ 
	Node* node=new Node(); 
	node->left = node->right = NULL; 
	node->data=key; 
	return node; 
} 

void fillMap(Node* root,int d,int l,map<int,pair<int,int>> &m){ 
	if(root==NULL) return; 

	if(m.count(d)==0){ 
		m[d] = make_pair(root->data,l); 
	}else if(m[d].second>l){ 
		m[d] = make_pair(root->data,l); 
	} 

	fillMap(root->left,d-1,l+1,m); 
	fillMap(root->right,d+1,l+1,m); 
} 

void topView(struct Node *root){ 

	map<int,pair<int,int>> m; 

	fillMap(root,0,0,m); 

	for(auto it=m.begin();it!=m.end();it++){ 
		cout << it->second.first << " "; 
	} 
} 

int main(){ 
	Node* root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->right = newNode(4); 
	root->left->right->right = newNode(5); 
	root->left->right->right->right = newNode(6); 
	cout<<"Following are nodes in top view of Binary Tree\n"; 
	topView(root); 
	return 0; 
} 

