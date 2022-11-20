class MyCircularQueue {
public:
    
    vector<int> CQ;
    int head = 0,sz = 0;
    
    MyCircularQueue(int k):CQ(k) {}
    
    bool enQueue(int value) {
        if(isFull())
        {
        return false;
        
        }
        CQ[(head+(sz++))%CQ.size()] = value;
        return true;
}      
    
    bool deQueue() {
        if(isEmpty())
        {
            return false;
        }
        head = (head + 1)%CQ.size();
        sz--;
        return true;
        
    }
      
    
    int Front() {
          if(isEmpty())
        {
            return -1;
        }
        return CQ[head];
        
    }
        
    
    
    int Rear() {
        if(isEmpty())
        {
            return -1;
        }
        return CQ[(head + sz -1)%CQ.size()];
        
        
    }
    
    bool isEmpty() {
        return !sz;
    }
    
    bool isFull() {
        return sz == CQ.size();
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
