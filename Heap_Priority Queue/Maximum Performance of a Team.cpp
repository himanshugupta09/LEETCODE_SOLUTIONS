class Solution {
public:
    
    
    /* 
    
    1.Firstly create a vector of pairs<int,int> which has par as <speed,efficiency
    
    2.Sort as per according to efficiency of the engineers.
    
    3.If any of engineers have same efficieny then place them on basis of thier maximum speed.
    
    4.Now Use Heap since our question demands for k values so use min. heap
    
    5.Initailize a variable sum with 0 and start iterate from the last index
    
    6. Add efficiency to sum and put the efficincy to heap
    
    7. Intialize a res variable that will track on our answer and update res as 
         
         res = max(res,sum*speed)
    
    8. As the size of min heap becomes greater than k , pop out the least speed engineer from heap
    
    
    9. We repeat the same process untill we go through all elemnts of list
    
    */
    
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
     
        long mod = 10e8+7;
        
        
        vector<pair<int,int>>v;
        
        priority_queue<int,vector<int>,greater<int>>heap;
        
        for(int i=0;i<n;i++)
        {
            v.push_back({efficiency[i],speed[i]});
            
            
        }
        
        long sum = 0,res = 0;
        
        sort(v.begin(),v.end());
        
        for(auto i=n-1;i>=0;i--)
        {
            sum += v[i].second;
            
            heap.push(v[i].second);
            
            if(heap.size()>k)
            {
                sum -= heap.top();
                heap.pop();
                
                
            }
            
            res = max(res,sum*v[i].first);
            
            
            
        }
        
        
        return res%mod;
        
        
    }
};
