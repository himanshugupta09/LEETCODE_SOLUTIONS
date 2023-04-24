class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int>pq;

        for(auto i:stones)
        {
            pq.push(i);
        }

        while(pq.size()>1)
        {
            int mx1 = pq.top();
            pq.pop();
            int mx2 = pq.top();
            pq.pop();

           
            if(mx1 != mx2)
            {
                pq.push(abs(mx1-mx2));
            }
        }

        return pq.empty() ? 0 : pq.top();


        
    }
};
