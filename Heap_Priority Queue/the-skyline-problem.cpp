class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<vector<int>>pq;
        map<int,vector<pair<int,int>>>m;
        vector<vector<int>>ans;
        int count =0, width = 0;
        for(auto i : buildings){
            m[i[0]].push_back({i[2],i[1]});
            m[i[1]].push_back({0,0});
        }
        for(auto i : m){
            auto vec = i.second;   
            for(auto j : vec){
                if(j.first!=0){
                    pq.push({j.first, j.second});
                }    
            }
            if(i.first == width){
                count = 0;
            }
            while(!pq.empty() && pq.top()[1]<=i.first){
                pq.pop();
            }
            if(!pq.empty() && pq.top()[0]>count){
                count = pq.top()[0];
                width = pq.top()[1];
                ans.push_back({i.first,count});
            }
            else if(count == 0){
                ans.push_back({i.first, 0});
            }       
        }  
        
        vector<vector<int>> vec;
        int prev = -1;
        for(auto i : ans){
            if(i[1]!=prev){
                vec.push_back(i);
                prev = i[1];
            }
        }
        return vec;
    }
};
