class MyStack {
    queue<int>stk;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        stk.push(x);
    }
    
    int pop() {
        if(!empty())
        {
            int t = 0;
            int n = stk.size();
            while(t < n-1)
            {
                stk.push(stk.front());
                stk.pop();
                t++;
            }
            int x = stk.front();
            stk.pop();
            return  x;
        }
        return -1;
    }
    
    int top() {
        if(!empty())
        {
            return stk.back();
        }
        return -1;
    }
    
    bool empty() {
        return stk.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */