class MyStack {
    queue<int>q1;
    queue<int>q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int n = q1.size();
        int t = 0;
        while(t < n-1)
        {
            q2.push(q1.front());
            q1.pop();
            t++;
        }
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        int x = q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
        if(empty())
        {
            return -1;
        }
        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
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