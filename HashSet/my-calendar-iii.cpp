class MyCalendarThree {
    private:
    map<int,int>dif;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        
        int now = 0,res  = 0;
        dif[start]++;
        dif[end]--;
        
        for(auto& [_,delta] : dif)
        {
            now += delta;
            res  = max(res,now);
        }
        
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
