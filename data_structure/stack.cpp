// /*
// 1.)Middle element in the stack.
// 2.) Pop from the middle of the stack and print that element
// 3.) Insert element at middle of the stack
// 4.) That stack question of number.
// */
// #include<bits/stdc++.h>
// using namespace std;
// struct node{
// 	int data;
// 	node* next,*prev;
// }*mid=NULL;
// int cnt=0;
// void print(node *head){
// 	if(head)
// 		while(head!=NULL)
// 			{
// 				cout<<head->data<<" ";
// 				head=head->next;
// 			}
// }
// void push(node *&head,int val){
// 	node *new_node=new node;
// 	if(head==NULL){
	
// 		new_node->data=val;
// 		new_node->next=NULL;
// 		new_node->prev=NULL;
// 		head=new_node;
// 	}
// 	else{
// 		new_node->data=val;
// 		new_node->prev=NULL;
// 		new_node->next=head;
// 		head->prev=new_node;
// 		head=new_node;
// 	}
// 	cnt++;
// 	if(cnt==1)
// 		mid=new_node;
// 	else{
// 		if(cnt&1){
// 			mid=mid->prev;
// 		}
// 	}
// }
// void middle_elem(node *head){
// 	if(head==NULL){
// 			cout<<"Underflow\n";
// 	}
// 	else{
// 	if(mid)
// 		cout<<"Current middle Element is "<<mid->data<<"\n";
// 	}
// }
// void pop_mid_elem(node *&head){
// 	if((mid->prev!=NULL)&&(mid->next!=NULL)){
// 	cnt=cnt-1;
// 	mid->prev->next=mid->next;
// 	mid->next->prev=mid->prev;
// 	node *curr=mid;
// 	if((curr!=NULL))
// 	cout<<curr->data<<"\n";
// 	if(cnt&1){
// 		mid=curr->prev;
// 	}
// 	else{
// 		mid=curr->next;
// 	}
// 	free(curr);
// 	}
// 	else{
// 		cout<<"No element is there\n";
// 		mid=NULL;
// 		head=NULL;
// 	}
// }
// void pop(node *&head){
// 	node *curr=head;
// 	if(head){
// 	int temp=curr->data;
// 	head=head->next;
// 	free(curr);
// 	cout<<temp<<"\n";
// 	cnt=cnt-1;
// 	if(!(cnt&1))
// 	mid=mid->next;
// 	}
// 	else
// 	{
// 		cout<<"Underflow\n";
// 	}
// }
// void insert_middle(int val){
// 		if(head==NULL){
// 			head->data=val;
// 			head->prev=NULL;
// 			head->next=NULL;
// 			mid=head;
// 			cnt++;
// 		}
// 		else{
// 			node *new_node=new node;
// 			new_node->data=val;
// 			cnt++;
// 			if(cnt&1){

// 			}
// 		}
// }
// int main(){
// 	freopen("Z:\\LPU\\FYear\\Practice_Contest_CF_CL\\inputf.in","r",stdin);
// 	freopen("Z:\\LPU\\FYear\\Practice_Contest_CF_CL\\outputf.in","w",stdout);
// 	node *head=NULL;
// 	cout<<"1 to insert an element into the stack\n";
// 	cout<<"2 to pop an element form the stack\n";
// 	cout<<"3 to print the middle element\n";
// 	cout<<"4 to pop the middle element\n";
// 	cout<<"5 to insert in the middle\n";
// 	while(1){
// 		int x;
// 		cin>>x;
// 		if(x==0)
// 			break;
// 		else if(x==1){
// 			int val;
// 			cin>>val;
// 			push(head,val);
// 		}
// 		else if(x==2){
// 			cout<<"Element poped is ";
// 			pop(head);
// 		}
// 		else if(x==3){
			
// 			middle_elem(head);
// 		}
// 		else if(x==4){
// 			cout<<"Poped middle element is ";//
// 			pop_mid_elem(head);
// 		}
// 		else if(x==5){
// 			int x;
// 			cin>>x;
// 			insert_middle(x);
// 		}
// 	}
// 		cout<<"Current stack looks like this\n";
// 		print(head);
// 		cout<<"\n";
		
// }
// /*
// 		node *delmid(node *top){
// 			if(mid==NULL)
// 			return NULL;
// 			node *temp=mid;
// 			if(mid->prev!=NULL)
// 			mid->prev->next=mid->next;
// 			if(mid->next!=NULL)
// 			mid->next->prev=mid->prev;
// 			c--;
// 			f(c%2!=0)
// 			mid=mid->prev;
// 			else
// 			mid=mid->next;
// 			if(mid==NULL
// 			top=NULL:
// 		}
// */
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
// 	int n;
// 	cin>>n;
// 	stack<int>s;
// 	n--;
// 	int x;
// 	cin>>x;
// 	s.push(x);
// 	while(n--){
// 		int x;
// 		cin>>x;
// 		if(s.top()<x){
// 			cout<<x<<"\n";
// 			s.pop();
// 			s.push(x);
// 		}
// 	}
// 	while(!s.empty()){
// 		cout<<"-1\n";
// 		s.pop();
// 	}
// }
