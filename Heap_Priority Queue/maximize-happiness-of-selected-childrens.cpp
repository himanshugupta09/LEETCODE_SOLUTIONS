class Solution {
public:
    /*    //This approach uses max heap 
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int minu = 0;
        long long sm = 0;
        priority_queue<int>pq;
        for(auto i:happiness)
        {
            pq.push(i);
        }
        //return pq.top();
        while(k--)
        {
            int cur = pq.top()-minu;
            if(cur > 0) sm  += cur;
            pq.pop();
            ++minu;
        }
        return sm;
    }
    */
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // Approach with built in sort function
        
        int minu = 0;
        long long sm = 0;
        
        sort(happiness.begin(),happiness.end(),greater<int>());
        
        for(int i=0;i<happiness.size();i++)
        {
            if(k > 0)
            {
                int c = happiness[i]-minu;
                if(c > 0)
                {
                    sm += c;
                }
                k--;
                minu++;
            }
            else
            {
                break;
            }
        }
        return sm;
    }
};
