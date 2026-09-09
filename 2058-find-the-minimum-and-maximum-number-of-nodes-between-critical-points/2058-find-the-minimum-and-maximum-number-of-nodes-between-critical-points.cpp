class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticalPoints;

        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return {-1, -1};

        ListNode* prev = head;
        ListNode* curr = head->next;

        int pos = 1;

        while (curr->next != nullptr) {

            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                criticalPoints.push_back(pos);
            }

            prev = curr;
            curr = curr->next;
            pos++;
        }

        if (criticalPoints.size() < 2)
            return {-1, -1};

        int minDist = INT_MAX;

        for (int j = 1; j < criticalPoints.size(); j++) {
            minDist = min(minDist,
                          criticalPoints[j] - criticalPoints[j - 1]);
        }

        int maxDist = criticalPoints.back() - criticalPoints.front();

        return {minDist, maxDist};
    }
};
