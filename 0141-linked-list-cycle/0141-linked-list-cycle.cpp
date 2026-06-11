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
    bool hasCycle(ListNode *head) {
        ListNode* hare = head;
        ListNode* turtle = head;
        if(!head)
        {
            return false;
        }
        while(hare && hare->next)
        {
            hare = hare->next->next;
            turtle = turtle->next;
            if(hare == turtle)
            {
                return true;
            }
            
        }
        return false;

    }
};