class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
       int res = 0;
        int n = tickets.size();
        for(int i=0;i<n;i++)
        {
            if(i <= k)
            {
                res += min(tickets[k],tickets[i]);
            }
            else
            {
                res += min(tickets[k]-1,tickets[i]);
            }
        }
        return res;
        
    }
};
