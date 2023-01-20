class Solution
{
public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        int n = nums.size();
        set<vector<int>> st;
        for (int i = 0; i < (1 << n); i++)
        {
            vector<int> v;
            bool flag = true;
            for (int j = 0; j < n; j++)
            {
                int bit = n - 1 - j;
                if ((i >> bit) & 1)
                {
                    if (v.empty())
                        v.push_back(nums[j]);
                    else if (nums[j] >= v.back())
                        v.push_back(nums[j]);
                    else
                        flag = false;
                }
            }
            if (v.size() >= 2 and flag)
                st.insert(v);
        }
        return vector<vector<int>>(st.begin(), st.end());
    }
};
