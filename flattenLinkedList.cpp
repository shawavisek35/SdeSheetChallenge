#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/

Node* flattenLinkedList(Node* head) 
{
	if(!head || !head->next) return head;
    Node *newHead = flattenLinkedList(head->next);
    Node *nextHead = new Node(0);
    Node *temp = nextHead;
    while(head && newHead) {
        if(head->data > newHead->data) {
            temp->child = newHead;
            newHead = newHead->child;
        }
        else {
            temp->child = head;
            head = head->child;
        }
        temp = temp->child;
        temp->next = NULL;
    }
    while(head) {
        temp->child = head;
        head = head->child; 
        temp = temp->child;
    }
    while(newHead) {
        temp->child = newHead;
        newHead = newHead->child;
        temp = temp->child;
    }
    
    return nextHead->child;
}
