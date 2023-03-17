class Trie {
public:
    unordered_map<string,int>mp,sp;
    Trie() {
        
    }
    
    void insert(string word) {
       mp[word]++;
       string t;
       for(auto i:word)
       {
           t.push_back(i);
           if(sp[t] == 0) sp[t]++;
       }
        
    }
    
    bool search(string word) {
        if(mp[word]) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
       if(sp[prefix])
       {
           return true;
       }
       return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
