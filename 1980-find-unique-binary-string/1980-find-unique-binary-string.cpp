class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        
        string notFound = "";
        
        for(int i=0;i<n;i++)
        {
            if(nums[i][i] == '0')
            {
                notFound += "1";
            }
            else notFound += '0';
        }
        return notFound;
    }
};