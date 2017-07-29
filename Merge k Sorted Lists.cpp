//https://leetcode.com/problems/merge-k-sorted-lists/description/

//复用mergeTwoLists
//time O(n1+n2+...) space O(1)
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return NULL;
        if (n == 1) return lists[0];
        ListNode* temp = lists[0];
        for (int i = 1; i < n; i++) {
            temp = mergeTwoLists(temp, lists[i]);
        }
        return temp;
    }
    
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy1(-1);
        ListNode* cur = &dummy1;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;                
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) {
            cur->next = l1;
        }
        if (l2) {
            cur->next = l2;
        }
        return dummy1.next;
    }
};