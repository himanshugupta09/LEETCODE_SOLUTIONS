/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* up = head->next;
        ListNode* ns = up;
        
        while(ns)
        {
            int sm = 0;
            
            while(ns->val != 0)
            {
                sm += ns->val;
                ns = ns->next;
            }
            up->val = sm;
            ns = ns->next;
            up->next = ns;
            up = up->next;
        }
        return head->next;
    }
};
