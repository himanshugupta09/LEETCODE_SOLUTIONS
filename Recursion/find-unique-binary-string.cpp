class Solution {
public:
    //string res;
    set<string>st;
    string ans;
    void solve(int max_len,string res)
    {
        if(st.find(res) == st.end() && res.size() == max_len)
        {
            ans = res;
            return;
        }
        if(st.find(res) != st.end() && res.size() == max_len)
        {
            res.pop_back();
            return;
        }
        if(res.size() == 0)
        {
            solve(max_len,res = "1");
            solve(max_len,res = "0");
        }
        if(res.size() < max_len)
        {
            solve(max_len,res+="1");
            solve(max_len,res+="0");
        }
        
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        int max_len = nums[0].size();
        
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
            //max_len = max(max_len,i.size());
        }
        string res = "";
        solve(max_len,res);
        return ans;
    }
};
