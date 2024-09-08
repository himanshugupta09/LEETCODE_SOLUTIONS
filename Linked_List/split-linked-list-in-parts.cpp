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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Step 1: Count the number of nodes
        ListNode* cur = head;
        int n = 0;
        while (cur) {
            n++;
            cur = cur->next;
        }

        // Step 2: Determine the size of each part
        vector<ListNode*> res(k, nullptr);
        int partSize = n / k;
        int extra = n % k;
        
        cur = head;
        for (int i = 0; i < k; ++i) {
            // Initialize the head of the current part
            ListNode* partHead = cur;
            ListNode* partTail = nullptr;
            int currentPartSize = partSize + (i < extra ? 1 : 0);

            // Traverse to the end of the current part
            for (int j = 0; j < currentPartSize; ++j) {
                if (cur) {
                    partTail = cur;
                    cur = cur->next;
                }
            }

            // Disconnect the current part from the rest of the list
            if (partTail) {
                partTail->next = nullptr;
            }

            // Add the current part to the result
            res[i] = partHead;
        }

        return res;
    }
};
