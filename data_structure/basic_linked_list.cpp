
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define br cout<<"\n"
#define max_val 1000000


class node{
public:
	int data;
	node *next;
};

void show(node *head){
	while(head){
		cout<<head->data<<" ";
		head=head->next;
	}
	br;
	return;
}

void insert(node *&head,node *&tail,int val){
	node *temp=new node;
	temp->data=val;
	temp->next=NULL;
	if(head==NULL){
		head=temp;
		tail=temp;
	}else{
		tail->next=temp;
		tail=temp;
	}
}

void remove_all(node *&head,int val){
	node **pointer=&head;
	while(*pointer){
		node *entry=*pointer;
		if(entry->data==val){
			*pointer=entry->next;
			delete(entry);
		}else{
			pointer=&(entry->next);
		}
	}
}

void reverse_onetail(node *&head){
	node *rev=NULL,*cur=head;
	while(cur){
		node *temp=cur->next;
		cur->next=rev;
		rev=cur;
		cur=temp;
	}
	head=rev;
}

void reverse(node *&head,node *&tail){
	node *cur=head,*prev=NULL;
	node *temp_tail=NULL;
// 	tail=tail->next;
	while(cur!=tail){
	    if(prev==NULL){
	        temp_tail=cur;
	    }
	    node *temp=cur->next;
	    cur->next=prev;
	    prev=cur;
	    cur=temp;
	}
	tail=temp_tail;
	head=prev;
}

void midvalue(node *head){
	node *fast=head;
	node *slow=head;
	while(fast and fast->next and fast->next->next){
		fast=(fast->next)->next;
		slow=slow->next;
	}
	if(slow!=NULL){
		cout<<"mid val is -: "<<slow->data;
		br;
	}

}

void delete_mid(node *&head){
	node **pointer=&head;
	node *fast=head;
	node *slow=head;
	node *entry=*pointer;
	while(fast and fast->next and fast->next->next){
		fast=(fast->next)->next;
		slow=slow->next;
		pointer=&(entry->next);
		entry=*pointer;
	}
	if(slow!=NULL){
		*pointer=entry->next;
		delete(entry);
	}
}

void delete_any_point(node *&head,int position){	/// position one indexing
	node **pointer=&head;
	int pos=1;
	while(*pointer){
		node *entry=*pointer;
		if(pos==position){
			*pointer=entry->next;
			delete(entry);
			return;
		}else{
			pointer=&(entry->next);
		}
		++pos;
	}

}



node *reverse_partial (node *head, int k)  
{  
    node* current = head;  
    node* next = NULL;  
    node* prev = NULL;  
    int count = 0;  
    while (current != NULL && count < k)  
    {  
        next = current->next;  
        current->next = prev;  
        prev = current;  
        current = next;  
        count++;  
    }  
    if (next != NULL)  
    head->next = reverse_partial(next, k);  
    return prev;  
}  

int main(){
	node *head=NULL,*tail=NULL;
	insert(head,tail,12);
	insert(head,tail,14);
	insert(head,tail,13);
	insert(head,tail,12);
	insert(head,tail,12);
	insert(head,tail,12);
	insert(head,tail,23);
	insert(head,tail,28);
	insert(head,tail,81);
	insert(head,tail,12);
	insert(head,tail,2);
	show(head);
	remove_all(head,12);
	show(head);
	reverse(head,tail);
	show(head);
	head=reverse_partial(head,4);
	show(head);
	delete_any_point(head,3);
	show(head);
	// show(tail);
	// show(head);
	// midvalue(head);
	// insert(head,tail,12);
	// midvalue(head);
	// show(head);
	// delete_mid(head);
	// show(head);
	
}