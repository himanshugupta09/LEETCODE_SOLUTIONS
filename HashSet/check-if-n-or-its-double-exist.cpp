class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
         unordered_set<int> seen;
        for (int num : arr) {
            // Check if 2 * num or num / 2 exists in the set
            if (seen.count(2 * num) || (num % 2 == 0 && seen.count(num / 2))) {
                return true;
            }
            // Add the current number to the set
            seen.insert(num);
        }
        // No valid pair found
        return false;
    }
};
