class TimeMap {
public:
    
    unordered_map<string,map<int,string>> keyTime;
    
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
    
        keyTime[key][timestamp] = value;
        
    }
    
    string get(string key, int timestamp) {
        
        if(keyTime.find(key) == keyTime.end())
        {
            return "";
        }
        auto i = keyTime[key].upper_bound(timestamp);
        
        if(i == keyTime[key].begin())
        {
            return "";
            
        }
        
        return prev(i)->second;
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
