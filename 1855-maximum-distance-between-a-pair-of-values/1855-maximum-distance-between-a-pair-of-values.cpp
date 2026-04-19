class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxDis = 0;
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();

        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                maxDis = max(maxDis, j - i);
                j++;  
            } else {
                i++;  
                if (i > j) j = i;  
            }
        }
        return maxDis;
    }
};