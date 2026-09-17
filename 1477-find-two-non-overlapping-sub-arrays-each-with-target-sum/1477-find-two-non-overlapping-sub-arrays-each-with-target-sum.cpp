class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int>prefix(n+1,INT_MAX);
        vector<int>suffix(n+1,INT_MAX);

        // Prefix
        int sum = 0;
        int left = 0;
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
            while(sum > k)
            {
                sum -= arr[left];
                left++;
            }
            if(sum == k)
            {
                int len = i-left+1;
                if(len < prefix[i])
                {
                    prefix[i] = len;
                }
            }
        }
        for (int i = 1; i < n; i++) {
            prefix[i] = min(prefix[i], prefix[i - 1]);
        }

        //  Suffix
        sum = 0;
        int right = n-1;
        for(int i=n-1;i>=0;i--)
        {
            sum += arr[i];
            while(sum > k)
            {
                sum -= arr[right];
                right--;
            }
            if(sum == k)
            {
                int len = right-i+1;
                if(len < suffix[i])
                {
                    suffix[i] = len;
                }
            }
        }
        for (int i = n-1; i >= 0; i--) {
            suffix[i] = min(suffix[i], suffix[i+1]);
        }

        int ans = INT_MAX;

        for (int i = 0; i < n - 1; i++) {
            if (prefix[i] != INT_MAX && suffix[i + 1] != INT_MAX) {
                ans = min(ans, prefix[i] + suffix[i + 1]);
            }
        }

        return ans == INT_MAX ? -1 : ans;

    }
};