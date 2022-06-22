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

Node *addTwoNumbers(Node *head1, Node *head2)
{
    int carry = 0;
    Node *sumHead = new Node(0);
    Node *head = sumHead;
    while(head1 && head2) {
        int val = head1->data + head2->data + carry;
        carry = val/10;
        val %= 10;
        head->next = new Node(val);
        head1 = head1->next;
        head2 = head2->next;
        head = head->next;
    }
    while(head1) {
        int val = head1->data + carry;
        carry = val/10;
        val %= 10;
        head->next = new Node(val);
        head1 = head1->next;
        head = head->next;
    }
    while(head2) {
        int val = head2->data + carry;
        carry = val/10;
        val %= 10;
        head->next = new Node(val);
        head2 = head2->next;
        head = head->next;
    }
    if(carry) {
        head->next = new Node(carry);
    }
    
    return sumHead->next;
}
