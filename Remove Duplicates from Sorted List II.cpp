//https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/#/description


//time O(n), space O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* cur = prev->next;
        ListNode* next;
        while (cur != NULL) {
            next = cur->next;
            if (next != NULL && next->val == cur->val) {
                while (next != NULL && next->val == cur->val) {
                    next = next->next;
                }
                prev->next = next;
            }
            else {
                prev = cur;
            }
            cur = next;
        }
        return dummy.next;
    }
};