//https://leetcode.com/problems/remove-nth-node-from-end-of-list/tabs/description

//time O(n), space O(1)
//双指针保持距离

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {       
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *p, *q;
        q = &dummy;
        p = &dummy;
        for (int i = 0; i < n; i++) {
            q = q->next;
        }
        while (q->next != NULL) {
            p = p->next;
            q = q->next;
        }
        p->next = p->next->next;
        return dummy.next;
    }
};