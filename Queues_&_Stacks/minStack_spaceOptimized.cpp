class MinStack {
public:
    stack<pair<int,int>> stk; // {value, currentMin}
    
    void push(int value) {
        int currentMin = stk.empty() ? value : min(value, stk.top().second);
        stk.push({value, currentMin});
    }
    
    void pop() {
        if(!stk.empty()) stk.pop();
    }
    
    int top() {
        return stk.empty() ? -1 : stk.top().first;
    }
    
    int getMin() {
        return stk.empty() ? -1 : stk.top().second;
    }
};