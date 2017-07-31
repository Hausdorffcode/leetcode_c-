//https://leetcode.com/problems/rotate-list/tabs/description

//time O(n), space O(1)
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        int n = 1;
        ListNode* cur = head;
        while (cur->next != NULL) {
            n++;
            cur = cur->next;
        }
        k = k % n;
        k = n-k;
        cur->next = head;
        while (k--) {
            cur = cur->next;
        }
        head = cur->next;
        cur->next = NULL;
        return head;
    }
};