#include <bits/stdc++.h> 
/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

int findIntersection(Node *firstHead, Node *secondHead)
{
    Node *fast = firstHead;
    Node *slow = secondHead;
    
    while((fast != slow)) {
        fast = fast->next;
        slow = slow->next;
        if(!fast && !slow) return -1;
        if(!fast) fast = secondHead;
        if(!slow) slow = firstHead;
    }
    
    if(!slow) return -1;
    return slow->data;
}
