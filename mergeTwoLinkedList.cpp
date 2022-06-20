#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    int tempVar = 0;
    Node<int> *head1 = new Node<int>(tempVar);
    Node<int> *head = head1;
    while(first && second) {
        if(first->data > second->data) {
            head->next = second;
            second = second->next;
        }
        else {
            head->next = first;
            first = first->next;
        }
        head = head->next;
    }
    
    while(first) {
        head->next = first;
        first = first->next;
        head = head->next;
    }
    
    while(second) {
        head->next = second;
        second = second->next;
        head = head->next;
    }
    return head1->next;
}
