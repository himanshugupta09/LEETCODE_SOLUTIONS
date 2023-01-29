class LFUCache {
    unordered_map<int,list<pair<int,int>>>mp;

    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> cache;
    int capacity;
    int minf;

    void insert(int key,int fre,int value)
    {
        mp[fre].push_back({key,value});
        cache[key] = {fre,--mp[fre].end()};
    }
public:
    LFUCache(int capacity): capacity(capacity), minf(0) {}
    
    int get(int key) {
        const auto it = cache.find(key);
        if (it == cache.end()) {
            return -1;
        }
        const int f = it->second.first;
        const auto iter = it->second.second;
        const pair<int, int> kv = *iter;
        mp[f].erase(iter);
        if (mp[f].empty() && minf == f) {
            ++minf;
        }
        insert(key, f + 1, kv.second);
        return kv.second;
        
    }
    
    void put(int key, int value) {
       if (capacity <= 0) {
            return;
        }
        const auto it = cache.find(key);
        if (it != cache.end()) {
            it->second.second->second = value;
            get(key);
            return;
        }
        if (capacity == cache.size()) {
            cache.erase(mp[minf].front().first);
            mp[minf].pop_front();
        }
        minf = 1;
        insert(key, 1, value); 
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
