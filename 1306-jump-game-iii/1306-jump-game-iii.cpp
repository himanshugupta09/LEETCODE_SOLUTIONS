class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        queue<int>q;
        q.push(start);
        
        int n = arr.size();
        vector<bool>vis(n,false);
        if(arr[start] == 0) return true;
        vis[start] = true;
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            if(arr[i] == 0){
                return true;
            }
            
            int a = (i + arr[i]);
            int b = (i-arr[i]);
            if(a < n && !vis[a]){
                vis[a] = true;
                
                q.push(a);
            }
            if(b >= 0 && !vis[b]){
                vis[b] = true;
                q.push(b);
            }
           
        }
        return false;
    }
};