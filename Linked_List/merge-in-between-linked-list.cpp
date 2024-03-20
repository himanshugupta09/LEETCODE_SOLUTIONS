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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* t = list1;
        int c = 1;
        
        while(c < a)
        {
            t = t->next;
            c++;
        }
        ListNode* tm = list2;
        ListNode* tp = t;
        
        while(tm->next)
        {
            tm = tm->next;
        }
        
        while(c <= b)
        {
            tp = tp->next;
            c++;
        }
        t->next = list2;
        tm->next = tp->next;
        return list1;
        
    }
};
