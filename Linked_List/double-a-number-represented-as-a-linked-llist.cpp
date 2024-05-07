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

// This is a Stack Based Approach 
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        stack<ListNode*>stk;
        ListNode* curr = head;
        stk.push(new ListNode(0));
        while(curr)
        {
            stk.push(curr);
            curr = curr->next;
        }
        ListNode* res = new ListNode(-1);
        int car = 0;
        while(!stk.empty())
        {
            ListNode* nw = stk.top();
            stk.pop();
            
            int base = ((nw->val*2) + car)%10;
            
            if(res->next == NULL)
            {
                ListNode* n2 = new ListNode(base);
                res->next = n2;
                car = 1 ? ((nw->val*2)+car) > 9 : 0;
            }
            else
            {
                ListNode* n2 = new ListNode(base);
                n2->next = res->next;
                res->next = n2;
                car = 1 ? ((nw->val*2)+car) > 9 : 0;
            }
        }
        if(res->next->val != 0)
        {
            return res->next;
        }
        return res->next->next;
    }
};
////Below is single pointer approach
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        //Single pointer Approach 
        if(head->val > 4)
        {
            head = new ListNode(0,head);
        }
        for(ListNode* node=head;node != nullptr;node=node->next)
        {
            node->val = (node->val*2)%10;
            
            if(node->next != nullptr && node->next->val > 4)
            {
                node->val++;
            }
        }
        return head;
    }
};
