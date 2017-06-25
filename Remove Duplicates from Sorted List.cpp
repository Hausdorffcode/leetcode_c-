//https://leetcode.com/problems/remove-duplicates-from-sorted-list/#/description

//time O(n), space O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        auto cur = head->next;
        auto prev = head;
        while (cur != nullptr) {
            if (cur->val == prev->val) {
                prev->next = cur->next;
                cur = cur->next;
            }
            else {
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};