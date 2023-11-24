class Solution {
public:
    int maxCoins(vector<int>& piles) {
       // priority_queue<int>pq;
        
        sort(piles.begin(),piles.end());
        
        int j = 0;
        int i=piles.size()-1;
        int mine = 0;
        while(i-j >= 2)
        {
            mine += piles[i-1];
            i-=2;
            j++;
        }
        return mine;
    }
};
