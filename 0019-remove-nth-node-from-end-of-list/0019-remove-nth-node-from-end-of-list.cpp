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
        if(!head)
        {
            return head;
        }   
        ListNode * prev = nullptr;
        ListNode* curr = head;
        while(curr)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* revHead = reverseList(head);

        // Step 2: Remove the n-th node from the beginning
        if (n == 1) {
            // Remove the first node
            ListNode* temp = revHead;
            revHead = revHead->next;
            delete temp;
        } else {
            ListNode* curr = revHead;
            for (int i = 1; i < n - 1 && curr->next; ++i) {
                curr = curr->next;
            }
            if (curr->next) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
        }

        // Step 3: Reverse again to restore original order
        return reverseList(revHead);
    }
};