class MyStack {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);

        int sz = q.size();
        while (sz > 1) {
            q.push(q.front());
            q.pop();
            sz--;
        }
    }

    int pop() {
        if (q.empty()) return -1;
        int x = q.front();
        q.pop();
        return x;
    }

    int top() {
        if (q.empty()) return -1;
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};