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
        ListNode* prevNode = NULL,*nextNode;
        ListNode* curr = head;

        while(curr)
        {
            nextNode = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = nextNode;

        }
        return prevNode;

    }

    int pairSum(ListNode* head) {
        int n = 0;

        ListNode* ptr = head;

        while(ptr->next)
        {
            n++;
            ptr = ptr->next;
        }
        ListNode* half = head;
        int md = 0;
        while(md < (n/2))
        {
            md++;
            half = half->next;
        }
        ListNode* revList = reverseList(half);

        int maxSum = 0;

        ptr = head;
        int sum = 0;
        while(ptr && revList)
        {
            sum = ptr->val + revList->val;
            maxSum = max(maxSum,sum);

            ptr = ptr->next;
            revList = revList->next;

        }
        return maxSum;
        
    }
};
