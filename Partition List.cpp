//https://leetcode.com/problems/partition-list/#/description


//time O(n), space (1)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1(-1);
        ListNode dummy2(-1);
        ListNode* p = &dummy1;
        ListNode* q = &dummy2;
        
        while (head != NULL) {
            if (head->val < x) {
                p->next = head;
                p = p->next;
            }
            else {
                q->next = head;
                q = q->next;
            }
            head = head->next;
        }
        p->next = dummy2.next;
        q->next = nullptr;  //注意这里，不要成圈了
        return dummy1.next;
    }
};