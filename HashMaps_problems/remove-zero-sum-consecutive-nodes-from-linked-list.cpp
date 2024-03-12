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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        std::unordered_map<int, ListNode*> prefixSumMap;
        int prefixSum = 0;
        for (ListNode* current = dummy; current != nullptr; current = current->next) {
            prefixSum += current->val;
            prefixSumMap[prefixSum] = current;
        }
        
        prefixSum = 0;
        for (ListNode* current = dummy; current != nullptr; current = current->next) {
            prefixSum += current->val;
            current->next = prefixSumMap[prefixSum]->next;
        }
        
        return dummy->next;
        
    }
};
