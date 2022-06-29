#include <bits/stdc++.h> 
/********************************

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

********************************/

Node *rotate(Node *head, int k) {
     // Write your code here.
    if(!k || !head || !head->next) return head;
    Node *fast = head;
    Node *slow = head;
    while(k) {
        k--;
        fast = fast->next;
        if(!fast) fast = head;
    }
    if(fast == head) return head;
    while(fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    Node *newHead = slow->next;
    fast->next = head;
    slow->next = NULL;
    return newHead;
    
}
