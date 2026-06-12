class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                ListNode *p1 = head;
                ListNode *p2 = slow;

                while (p1 != p2) {
                    p1 = p1->next;
                    p2 = p2->next;
                }

                return p1;
            }
        }

        return NULL;
    }
};