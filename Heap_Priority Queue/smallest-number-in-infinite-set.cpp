class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    set<int>s;
    

   int curn;

    SmallestInfiniteSet() {
        curn = 1;
    }
    
    int popSmallest() {
       int res;
       if(!pq.empty())
       {
           res = pq.top();
           s.erase(res);
           pq.pop();
       }
       else
       {
           res = curn;
           curn++;
       }
       return res;

    }
    
    void addBack(int num) {
       if(curn <= num || s.find(num) != s.end())
       {
           return;
       }
       pq.push(num);
       s.insert(num);
       
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
