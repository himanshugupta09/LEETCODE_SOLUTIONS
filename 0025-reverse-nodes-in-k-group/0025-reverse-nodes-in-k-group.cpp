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
    pair<ListNode*,ListNode*> reverseList(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next_node = NULL;
        ListNode* curr_tail = NULL;

        while(curr)
        {
            next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr_tail = curr;
            curr = next_node;
        }
        return {prev,head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(!head || k == 1) return head;   // IMPROVEMENT #2

        ListNode* curr = head;

        ListNode* ansHead = NULL;          // IMPROVEMENT #3:
                                          // store final answer head

        ListNode* prevTail = NULL;         // IMPROVEMENT #4:
                                          // tail of previous reversed group

        bool isFirst = true;

        while(curr)
        {
            ListNode* groupStart = curr;

            // IMPROVEMENT #5:
            // verify k nodes exist
            ListNode* kth = curr;

            for(int i = 1; i < k && kth; i++)
            {
                kth = kth->next;
            }

            if(!kth)
            {
                // less than k nodes left
                if(prevTail)
                    prevTail->next = curr;

                break;
            }

            // IMPROVEMENT #6:
            // save next group's start
            ListNode* nextGroup = kth->next;

            // IMPROVEMENT #7:
            // isolate current group
            kth->next = NULL;

            pair<ListNode*, ListNode*> pr = reverseList(groupStart);

            ListNode* reverseHead = pr.first;
            ListNode* tail = pr.second;

            // IMPROVEMENT #8:
            // save answer head only once
            if(isFirst)
            {
                ansHead = reverseHead;
                isFirst = false;
            }

            // IMPROVEMENT #9:
            // connect previous group to current reversed group
            if(prevTail)
            {
                prevTail->next = reverseHead;
            }

            // IMPROVEMENT #10:
            // connect tail to remaining list
            tail->next = nextGroup;

            // IMPROVEMENT #11:
            // prepare for next iteration
            prevTail = tail;
            curr = nextGroup;
        }

        return ansHead ? ansHead : head;   // IMPROVEMENT #12:
                                           // return correct head
    }
};