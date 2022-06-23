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
vector<Node *> reverse(Node *head, int k, Node *prevNode) {
    Node *prev = NULL;
    Node *temp = head;
    Node *nextNode = head;
    while(nextNode && k) {
        k--;
        nextNode = nextNode->next;
        temp->next = prev;
        prev = temp;
        temp = nextNode;
    }
    head->next = temp;
    if(prevNode) prevNode->next = prev;
    return { prev, nextNode, head };
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
    Node *temp = head;
    //Node *newHead = new Node(0);
    int i = 0;
    Node *prevNode = NULL;
    while(i<n && temp) {
        int k = b[i];
        if(k==0) {
            i++;
            continue; 
        }
        
        if(k==1) {
            prevNode = temp;
            temp = temp->next;
            i++;
            continue;
        }
       vector<Node *> pr = reverse(temp, k, prevNode);
        if(i==0) {
            head = pr[0];
        }
        prevNode = pr[2];
        temp = pr[1];
        i++;
    }
    return head;
}
