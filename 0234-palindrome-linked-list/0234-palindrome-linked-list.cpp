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
        if(!head || !head->next)
        {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr)
        {
            ListNode* next = curr->next; // store next node
            curr->next = prev;          // reverse link
            prev = curr;                // move prev forward
            curr = next;                // move curr forward
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
            if (!head || !head->next) return true;

        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* secondHalf = reverseList(slow);

        // Step 3: Compare both halves
        ListNode* firstHalf = head;

        while (secondHalf)
        {
            if (firstHalf->val != secondHalf->val)
                return false;

            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;

    }
};