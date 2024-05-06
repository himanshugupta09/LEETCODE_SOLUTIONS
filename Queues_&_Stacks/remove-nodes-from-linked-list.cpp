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
    ListNode* removeNodes(ListNode* head) {
        
        ListNode* curr = head;
        stack<ListNode*>stk;
        
        while(curr)
        {
            while(!stk.empty() && stk.top()->val < curr->val)
            {
                stk.pop();
            }
            stk.push(curr);
            curr = curr->next;
        }
        ListNode* res = new ListNode(-1);
        //ListNode* dm = res;
        
        while(!stk.empty())
        {
            ListNode* nw = stk.top();
            stk.pop();
            if(!res->next)
            {
                res->next = nw;
                nw->next = nullptr;
            }
            else
            {
                nw->next = res->next;
                res->next = nw;
            }
        }
        
        return res->next;
        
    }
};
