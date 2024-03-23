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
    void reorderList(ListNode* head) {
        ListNode *slo = head;
        ListNode *fas = head;
        
        while(fas->next != nullptr && fas->next->next != nullptr)
        {
            slo = slo->next;
            fas = fas->next->next;
        }
        
        ListNode *prev = nullptr,*cur = slo->next;
        
        while(cur != nullptr)
        {
            ListNode *nN = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nN;
        }
        slo->next = nullptr;
        
        ListNode *rt = head,*st = prev;
        
        while(st != nullptr)
        {
            ListNode *nct = rt->next,*pct = st->next;
            rt->next = st;
            st->next = nct;
            rt = nct;
            st = pct;
            
        }
    }
};
