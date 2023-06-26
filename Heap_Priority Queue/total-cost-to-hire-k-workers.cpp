class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        
        priority_queue<int,vector<int>,greater<int>>p1,p2;

        for(int i=0;i<candidates;i++)
        {
            p1.push(costs[i]);
        }
        int rt = costs.size()-candidates;
        int st = max(candidates,rt);

        for(int i = st;i<costs.size();i++)
        {
            p2.push(costs[i]);
        }

        long res = 0;

        int n1 = candidates;
        int n2 = costs.size()-1-candidates;

        for(int i=0;i<k;i++)
        {

            if(p2.empty() || !p1.empty() && p1.top() <= p2.top())
            {
                res += p1.top();
                p1.pop();

                if(n1 <= n2)
                {
                    p1.push(costs[n1]);
                    n1++;
                    

                }
            }
            else
            {
                res += p2.top();
                p2.pop();

                if(n1 <= n2)
                {
                    p2.push(costs[n2]);
                    n2--;

                }
            }
        }
        return res;
    }
};
