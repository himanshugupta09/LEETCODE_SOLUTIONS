class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(),deck.end());
        
        vector<int>res(n);
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            q.push(i);
        }
        int p = 0;
        while(!q.empty())
        {
            int a = q.front();
            q.pop();
            int b = q.front();
            q.pop();
            q.push(b);
            res[a] = deck[p];
            p++;
            
        }
        return res;
        
    }
};
