//https://leetcode.com/problems/insertion-sort-list/description/

//time O(n^2), space O(1)
//selection
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        for (ListNode *p = &dummy; p->next != NULL; p = p->next) {
            ListNode* q = p;
            ListNode* min = p;
            while (q->next) {
                if (q->next->val < min->next->val) {
                    min  = q;
                }
                q = q->next;
            }
            ListNode* temp = min->next;
            min->next = temp->next;
            temp->next = p->next;
            p->next = temp;
        }
        return dummy.next;
    }
};