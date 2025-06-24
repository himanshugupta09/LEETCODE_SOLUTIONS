class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        
        set<int>st;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == key)
            {
                st.insert(i);
                int j = i;
                int k1 = k;
                while(j >= 0 && k1>=0)
                {
                    st.insert(j);
                    j--;
                    k1--;
                }
                j = i;
                k1 = k;
                while(j < nums.size() && k1 >= 0)
                {
                    st.insert(j);
                    j++;
                    k1--;
                }
            }
        }
        vector<int>res(st.begin(),st.end());
        return res;        
    }
};