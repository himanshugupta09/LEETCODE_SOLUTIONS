class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        
        
        
        
        stack<int>s;
        
        
        for(int i=0;i<arr.size();i++)
        {
            int cur = arr[i];
            
            while(!s.empty() && arr[i] < s.top())
            {
                cur = max(cur,s.top());
                s.pop();
                
            }
            s.push(cur);
            
        }
        
        
        return s.size();
        
    }
};
