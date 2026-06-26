class DListNode {
public:
    int key;
    int val;
    DListNode* prev;
    DListNode* next;

    DListNode(int key, int val) {
        this->key = key;
        this->val = val;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
        unordered_map<int,DListNode*>hashMap;
        DListNode* head;
        DListNode* tail;
        int capacity;
    LRUCache(int capacity) {
      this->capacity = capacity;
      head = new DListNode(-1,-1);
      tail = new DListNode(-1,-1);
      head->next = tail;
      tail->prev = head;
    }
    void removeNode(DListNode* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insertNode(DListNode* node)
    {
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }
    int get(int key) {
        if(hashMap.find(key) == hashMap.end())
        {
            return -1;
        }
        DListNode* node = hashMap[key];
        removeNode(node);
        insertNode(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(hashMap.find(key) != hashMap.end())
        {
            DListNode* node = hashMap[key];
            node->val = value;
            removeNode(node);
            insertNode(node);
            return;
        }
        if(hashMap.size() == capacity)
        {
            DListNode* lru = head->next;
            removeNode(lru);
            hashMap.erase(lru->key);
            delete lru;
        }
        DListNode* newVal = new DListNode(key,value);
        insertNode(newVal);
        hashMap[key] = newVal;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */