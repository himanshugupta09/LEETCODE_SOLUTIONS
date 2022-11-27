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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head->next == NULL)
        {
            return NULL;
            
        }
        ListNode *tut = head, *rab = head->next->next;
        
        while(rab != NULL && rab->next != NULL)
        {
            tut = tut->next;
            rab = rab->next->next;
            
        }
        
        tut->next = tut->next->next;
        //rab = rab->next->next;
        
        
        return head;
        
        
        
        
        
        
    }
};
