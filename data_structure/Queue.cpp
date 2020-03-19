// #include<bits/stdc++.h>
// using namespace std;
// struct node{
// 	int data;
// 	node *next;
// }*front=NULL,*rear=NULL;
// void Enqueue(int data){
// 	node *new_node=new node;
// 	new_node->data=data;
// 	new_node->next=NULL;
// 	if(front==NULL)
// 		front=new_node;
// 	if(rear!=NULL)
// 		rear->next=new_node;
// 	rear=new_node;
// }
// void Dequeue(){
// 	if(front==NULL)
// 	{
// 		cout<<"Empty queue\n";
// 		return;
// 	}
// 	cout<<"Dequeued element "<<front->data<<"\n";
// 	node *temp=front;
// 	front=front->next;
// 	delete(temp);
// 	if(front==NULL)
// 		rear=NULL;
// }
// void print(node *head){
// 	node *curr=head;
// 	if(curr==NULL){
// 		cout<<"No elements are present\n";
// 		return;
// 	}
// 	while(curr!=NULL){
// 		cout<<curr->data<<" ";
// 		curr=curr->next;
// 	}
// 	cout<<"\n";
// }
// int main(){

	// freopen("Z:\\LPU\\FYear\\Practice_Contest_CF_CL\\inputf.in","r",stdin);
	// freopen("Z:\\LPU\\FYear\\Practice_Contest_CF_CL\\outputf.in","w",stdout);
	// Enqueue(1);
	// Enqueue(2);
	// Enqueue(4);
	// Enqueue(3);
	// Enqueue(5);
// 	print(front);
// 	Dequeue();
// 	print(front);
// 	Enqueue(3);
// 	print(front);
// 		Dequeue();
// 		print(front);	Dequeue();	print(front);Dequeue();	print(front);Dequeue();	print(front);Dequeue();print(front);	Dequeue();print(front);
// }
#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next;
}*front=NULL,*rear=NULL;
void Enqueue(int data){
	node *new_node=new node;
	new_node->data=data;
	new_node->next=NULL;
	if(front==NULL)
		front=new_node;
	if(rear!=NULL)
		rear->next=new_node;
	rear=new_node;
}
void Dequeue(node *&front){
	if(front==NULL)
	{
		cout<<"Empty queue\n";
		return;
	}
	//cout<<"Dequeued element "<<front->data<<"\n";
	node *temp=front;
	front=front->next;
	delete(temp);
	if(front==NULL)
		rear=NULL;
}
// void reverse(queue<int>&Q){
// 	if(!Q.empty()){
// 		int a=Q.front();
// 		Q.pop();
// 		reverse(Q);
// 		Q.push(a);
// 	}
// }
void reverse(node *&front){
	if(front!=NULL){
		node *temp=front;
		Dequeue(front);
		reverse(front);
		Enqueue(temp->data);
	}
}
void print(node *head){
	node *curr=head;
	if(curr==NULL){
		cout<<"No elements are present\n";
		return;
	}
	while(curr!=NULL){
		cout<<curr->data<<" ";
		curr=curr->next;
	}
	cout<<"\n";
}
int main(){
	// freopen("Z:\\LPU\\FYear\\Practice_Contest_CF_CL\\inputf.in","r",stdin);
	// freopen("Z:\\LPU\\FYear\\Practice_Contest_CF_CL\\outputf.in","w",stdout);
	Enqueue(1);
	Enqueue(2);
	Enqueue(4);
	Enqueue(3);
	Enqueue(5);
	reverse(front);
	print(front);
}










































































































// // void Enqueue(node *&head,int val){
// // 		node *new_node=new node;
// // 		node *last=NULL;
// // 		if(head==NULL){
// // 				new_node->data=val;
// // 				new_node->next=NULL;
// // 				head=new_node;
// // 				last=new_node;
// // 		}
// // 		else{
// // 			new_node->data=val;
// // 			new_node->next=NULL;
// // 			last->next=new_node;
// // 			last=new_node;
// // 		}
// // }
