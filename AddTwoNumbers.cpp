/**Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/**直接加
时间(n)，空间O(1)*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode *prev = &dummy;
        int carry = 0;
        for(ListNode *p2 = l2, *p1 = l1; p1 != nullptr || p2 != nullptr; 
            p1 = p1 == nullptr ? nullptr : p1->next, p2 = p2 == nullptr ? nullptr : p2->next) {
            int p1_val = p1 == nullptr ? 0 : p1->val;
            int p2_val = p2 == nullptr ? 0 : p2->val;
            int digit = p1_val + p2_val + carry;
            carry = digit / 10;
            prev->next = new ListNode(digit % 10);
            prev = prev->next;
        }
        if (carry > 0) {
            prev->next = new ListNode(carry);
        }
        return dummy.next;
    }
};