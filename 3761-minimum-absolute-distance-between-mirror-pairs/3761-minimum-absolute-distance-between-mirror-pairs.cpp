class Solution {
public:
    int reverseNumber(int num) {
        int res = 0;
        while (num != 0) {
            int digit = num % 10;
            res = res * 10 + digit;
            num /= 10;
        }
        return res;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int minDiff = INT_MAX;
        unordered_map<int, int> indexMap;

        for (int i = 0; i < nums.size(); i++) {
            int revNum = reverseNumber(nums[i]);

            if (indexMap.find(nums[i]) != indexMap.end()) {
                minDiff = min(minDiff, i - indexMap[nums[i]]);
            }

            indexMap[revNum] = i;
        }

        return (minDiff == INT_MAX) ? -1 : minDiff;
    }
};