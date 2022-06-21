#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    if(!head || K==0) return head;
    LinkedListNode<int> *fast=head, *slow=head, *prev=head;
    int i = 0;
    while(i<K && fast) {
        fast = fast->next;
        i++;
    }
    if(!fast) return head->next;
    while(fast) {
        fast = fast->next;
        prev = slow;
        slow = slow->next;
    }
    prev->next = slow->next;
    return head;
}
