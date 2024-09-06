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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>nts(nums.begin(),nums.end());
        
        ListNode* cur = head;
        ListNode* dum = NULL;
        while(cur != NULL)
        {
            if(nts.find(cur->val) != nts.end())
            {
                if(cur == head)
                {
                    head = head->next;
                    cur = head;
                }
                else
                {
                    dum->next = cur->next;
                    cur->next = dum;
                    cur  = cur->next;
                }
                
            }
            else
            {
                dum = cur;
                cur = cur->next;
            }
            
        }
        return head;
    }
};
