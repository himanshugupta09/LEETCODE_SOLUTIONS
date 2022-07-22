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
    ListNode* partition(ListNode* head, int x) {
        ListNode *cur = head;
        ListNode *less = new ListNode(-1);
        ListNode *High = new ListNode(-1);
        ListNode *sm_hd = less;
        ListNode *High_hd = High;
        while(cur)
        {
            if(cur->val<x)
            {
                less->next = cur;
                less = less->next;
                
                cur = cur->next;
                less->next = NULL;
            }
            else{
                High->next = cur;
                High = High->next;
                
                cur = cur->next;
                High->next = NULL;
            }
           
        }
        less-> next = High_hd -> next;

        return sm_hd -> next;
        
    }
};
