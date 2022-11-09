class StockSpanner {
public:
    
    stack<pair<int,int>>s;

    StockSpanner() {
        
    }
    
    int next(int price) {
        int res = 0;

        while(!s.empty() &&s.top().first <= price)
        {
            res += s.top().second;
            s.pop();

        }
        res++;

        s.push({price,res});

        return res;

        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
