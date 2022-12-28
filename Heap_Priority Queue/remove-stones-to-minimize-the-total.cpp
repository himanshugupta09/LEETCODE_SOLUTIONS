class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int>max_heap;

        for(auto i:piles)
        {
            max_heap.push(i);
        }

        while(k--)
        {
            int mx = max_heap.top();
            mx  = mx -  mx/2;
           
            max_heap.pop();
            max_heap.push(mx);

        }

        int sm = 0;

        while(!max_heap.empty())
        {
            sm += max_heap.top();
            max_heap.pop();

        }

        return sm;
    }
};
