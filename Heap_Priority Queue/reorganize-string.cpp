class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for (auto i : s) {
            mp[i]++;
        }
        
        priority_queue<pair<int, char>> pq;
        for (auto entry : mp) {
            pq.push({entry.second, entry.first});
        }
        
        string ans = "";
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            if (ans.empty() || ans.back() != curr.second) {
                ans += curr.second;
                if (curr.first > 1) {
                    pq.push({curr.first - 1, curr.second});
                }
            } else {
                if (pq.empty()) {
                    return "";
                }
                auto next = pq.top();
                pq.pop();
                ans += next.second;
                if (next.first > 1) {
                    pq.push({next.first - 1, next.second});
                }
                pq.push(curr);
            }
        }
        
        return ans;
    }
};
