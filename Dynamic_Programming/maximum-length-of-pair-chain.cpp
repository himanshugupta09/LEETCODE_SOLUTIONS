class Solution {
public:

    static bool comp(vector<int>a,vector<int>b)
    {
        return a[1] < b[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(),pairs.end(),comp);
        int res = 0;
        int temp = 0;
        for(int i=1;i<pairs.size();i++)
        {
            if(pairs[i-1][1] < pairs[i][1])
            {
                temp++;
            }
            else
            {
                res = max(temp,res);
            }
        }
        return res;
    }
    

};
