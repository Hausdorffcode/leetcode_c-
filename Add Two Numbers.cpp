//https://leetcode.com/problems/add-two-numbers/#/description

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//time O(n), spaceO(1)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        int carry = 0;
        ListNode* prev = &dummy;
        for (ListNode* pa = l1, *pb = l2; pa != nullptr || pb != nullptr; 
            pa = pa==nullptr ? pa : pa->next, pb = pb == nullptr ? pb : pb->next) {
                int va = pa == nullptr ? 0 : pa->val;
                int vb = pb == nullptr ? 0 : pb->val;
                int vv = (va+vb+carry)%10;
                carry = (va+vb+carry)/10;
                prev->next = new ListNode(vv);
                prev = prev->next;
        }
        if (carry > 0) prev->next = new ListNode(carry);
        return dummy.next;
    }
};