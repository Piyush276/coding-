// C++ program to detect and remove loop 
// We can hash the addresses of the linked list nodes in an unordered map and just check if the 
// element already exists in the map. If it exists, we have reached a node which already exists 
// by a cycle, hence we need to make the last node’s next pointer NULL.

#include </Users/piyush/Desktop/CP/bits/stdc++.h>

// #include <bits/stdc++.h>
// 
#include <unordered_map>
typedef long long ll;
using namespace std;

#define br cout<<"\n"
#define max_val 1000000


// #include <bits/stdc++.h> 
// using namespace std; 

struct Node { 
	int key; 
	struct Node* next; 
}; 

Node* newNode(int key) 
{ 
	Node* temp = new Node; 
	temp->key = key; 
	temp->next = NULL; 
	return temp; 
} 

// A utility function to print a linked list 
void printList(Node* head) 
{ 
	while (head != NULL) { 
		cout << head->key << " "; 
		head = head->next; 
	} 
	cout << endl; 
} 

// Function to detect and remove loop 
// in a linked list that may contain loop 
void hashAndRemove(Node* head) 
{ 
	// hash map to hash addresses of the linked list nodes 
	unordered_map<Node*, int> node_map; 
	// pointer to last node 
	Node* last = NULL; 
	while (head != NULL) { 
		// if node not present in the map, insert it in the map 
		if (node_map[head] == 0) { 
			node_map[head]++; 
			last = head; 
			head = head->next; 
		} 
		// if present, it is a cycle, make the last node's next pointer NULL 
		else { 
			last->next = NULL; 
			break; 
		} 
	} 
} 
/* Driver program to test above function*/
int main() 
{ 
	Node* head = newNode(50); 
	head->next = head; 
	head->next = newNode(20); 
	head->next->next = newNode(15); 
	head->next->next->next = newNode(4); 
	head->next->next->next->next = newNode(10); 

	/* Create a loop for testing */
	head->next->next->next->next->next = head->next->next; 
	// printList(head); 
	// printList(head); 
	hashAndRemove(head); 

	printf("Linked List after removing loop \n"); 
	printList(head); 

	return 0; 
} 
