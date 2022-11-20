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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(n>0)
        {
            fast = fast->next;
            n--;
            
            
        }
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next;
            
        }
        if(fast)
        {
            slow->next = slow->next->next;
            
        }
        else{
            head = head->next;
            
        }
        
        return head;
        
        
    }
};
