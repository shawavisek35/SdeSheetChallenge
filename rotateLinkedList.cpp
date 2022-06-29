/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!k || !head || !head->next) return head;
        int cnt = 0;
        ListNode *temp = head;
        while(temp) {
            cnt ++;
            temp = temp->next;
        }
        k = k%cnt;
        if(!k) return head;
        ListNode *fast = head;
        ListNode *slow = head;
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
        ListNode *newHead = slow->next;
        fast->next = head;
        slow->next = NULL;
        return newHead;
    }
};
