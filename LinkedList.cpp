#include <iostream>
using namespace std;
struct ListNode{
	int data;
	ListNode *next;
	ListNode *prev;
};

ListNode* createNode(int val){
	ListNode *temp = new ListNode();
	temp->data = val;
	return temp;
}

void printLinkedList(ListNode *head){
	if(head == NULL){
		cout<<"YES";
	}
	while(head!=NULL){
		cout<<head->data<<" -> ";
		head= head->next;
	}
	
	cout << "NULL" << endl;
}

ListNode *getTail(ListNode *head){
	while(head->next!=NULL){
		head=head->next;
	}
	return head;
}

void printInReverse(ListNode *head){
	ListNode *tail = getTail(head);
	while(tail!=NULL){
		cout<<tail->data<<" <- ";
		tail = tail->prev;
	}
	
	cout << "NULL" << endl;
}
int main() {
	ListNode *head = NULL;
	ListNode *temp = NULL;
	
	int val;
	while(cin>>val){
		//if head is null then assign the value to head
		if(head==NULL){
			head= createNode(val);
			temp = head;
		}
		else{
			//temp is the end node of the linked list, new node will be next of temp
			temp->next = createNode(val);
			temp->next->prev=temp;
			temp = temp->next;
		}
	}
	
	printLinkedList(head);
	cout<<"reverse: ";
	printInReverse(head);
	return 0;
}
