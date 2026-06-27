class MinStack {
public:
    stack<int>stk;
    stack<int>minStack;
    MinStack() {
        
    }
    
    void push(int value) {
        if(minStack.empty() && stk.empty())
        {
            stk.push(value);
            minStack.push(value);
        }
        else
        {
            stk.push(value);
            if(value <= minStack.top())
            {
                minStack.push(value);
            }
            else 
            {
                minStack.push(minStack.top());
            }
        }
    }
    
    void pop() {
        if(stk.empty()) return;
        minStack.pop();
        stk.pop();
    }
    
    int top() {
        return stk.empty() ? -1 : stk.top();
    }
    
    int getMin() {
        return minStack.empty() ? -1 : minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */