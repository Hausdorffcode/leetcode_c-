//https://leetcode.com/problems/reverse-linked-list-ii/#/description

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//注意边界条件的判断，熟练掌握prev，cur，next三指针
//time O(n), space O(1)
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m==n) return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* head2 = &dummy;
        for (int i = 1; i < m; i++) {
            head2 = head2->next;
        }
        ListNode* prev = head2->next;
        ListNode* cur = prev->next;
        ListNode* nnext;
        for (int i = 0; i < (n-m); i++) {
            nnext = cur->next;    //nnext在这里赋值，当心null
            cur->next = head2->next;
            head2->next = cur;
            cur = nnext;
        }
        prev->next = nnext;
        return dummy.next;
    }
};