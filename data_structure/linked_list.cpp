///// doubly linked list reverse
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define br cout<<"\n"
#define max_val 1000000


class Node 
{ 
	public: 
	int data; 
	Node *next; 
	Node *prev; 
}; 

void reverse(Node **head_ref) 
{ 
	Node *temp = NULL; 
	Node *current = *head_ref; 
	while (current != NULL) 
	{ 
		temp = current->prev; 
		current->prev = current->next; 
		current->next = temp;			 
		current = current->prev; 
	} 
	if(temp != NULL ) 
		*head_ref = temp->prev; 
} 

void add(Node *&head,int val){
	Node *temp=new Node();
	temp->data=val;
	temp->prev=NULL;
	temp->next=head;
	if(head!=NULL){
		head->prev=temp;
	}
	head=temp;
}

void printList(Node *node) 
{ 
	while(node != NULL) 
	{ 
		cout << node->data << " "; 
		node = node->next; 
	} 
	br;
} 

int main() 
{ 
	Node* head = NULL; 
	add(head,2);
	add(head,23);
	add(head,22);
	add(head,21);
	cout << "Original Linked list" << endl; 
	printList(head); 
	reverse(&head); 
	
	cout << "\nReversed Linked list" << endl; 
	printList(head);		 
	
	return 0; 
} 

