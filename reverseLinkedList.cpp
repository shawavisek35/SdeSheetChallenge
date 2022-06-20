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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int> *prev, *temp, *nextNode;
    prev = NULL;
    temp = head;
    nextNode = head;
    
    while(nextNode) {
        nextNode = nextNode->next;
        temp->next = prev;
        prev = temp;
        temp = nextNode;
    }
    
    return prev;
}
