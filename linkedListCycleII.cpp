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

Node *firstNode(Node *head)
{
    if(!head || !head->next) return NULL;
	Node *fast = head;
    Node *slow = head;
    do{
        fast = fast->next;
        if(fast) fast = fast->next;
        slow = slow->next;
    }while(fast && fast != slow);
    
    if(!fast) return NULL;
    slow = head;
    while(fast && fast!=slow) {
        fast = fast->next;
        slow = slow->next;
    }
    
    return slow;
}
