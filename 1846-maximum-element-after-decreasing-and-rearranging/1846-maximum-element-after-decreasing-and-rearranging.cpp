class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int ops = (arr[0] == 1) ? 0 : 1;
        
        arr[0] = 1;
        int maxEle = arr[0];
        for(int i=1;i<arr.size();i++)
        {
            if((arr[i]-arr[i-1]) > 1)
            {
                arr[i] = arr[i-1]+1;
            }
            maxEle = max(maxEle,arr[i]);
            
        }
        return maxEle;
    }
};