class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
        stack<pair<int,int>>stk;
        for(int i=0;i<color.size();i++)
        {
            if(stk.empty())
            {
                stk.push({color[i],radius[i]});
                continue;
            }
            else
            {
                pair<int,int>pr = stk.top();
                if((!stk.empty()) && (pr.first == color[i] && pr.second == radius[i]))
                {
                    stk.pop();
                    
                }
                else
                {
                    pair<int,int>tp = {color[i],radius[i]};
                    stk.push(tp);
                }
            }
            
        }
        return stk.size();
    }
};
