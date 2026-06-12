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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* pre = NULL;
        ListNode* next = NULL;
        ListNode* cur = head;
        while(cur)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
    
        ListNode* hare = head;
        ListNode* tur = head;
        while(hare && hare->next)
        {
            tur = tur->next;
            hare = hare->next->next;
        }
        if(hare)
        {
            tur = tur->next;
        }
        tur  = reverseList(tur);
        ListNode* fast = head;
        ListNode* sec = tur;
        while(sec)
        {
            if(fast->val != sec->val)
            {
                return false;
            }
            fast = fast->next;
            sec = sec->next;
        }
        return true;
    }
};