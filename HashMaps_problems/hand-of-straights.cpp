/*
// Using Map + Priority Queue
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        priority_queue<pair<int,int>>pq;
        map<int,int>mp;
        for(auto i:hand)
        {
            mp[i]++;
        }
        for(auto i:mp)
        {
            pq.push({i.first,i.second});
        }
        
        while(!pq.empty())
        {
            vector<int>t;
            vector<pair<int,int>>tpq;
            
            while(!pq.empty() && t.size() < groupSize)
            {
                int num = pq.top().first;
                int f = pq.top().second;
                pq.pop();
                
                if(t.size() > 0 && abs(num-t.back()) != 1)
                {
                    return false;
                }
                t.push_back(num);
                f--;
                
                if(f > 0)
                {
                    tpq.push_back({num,f});
                }
                
            }
            if(t.size() < groupSize)
            {
                return false;
            }
            while(tpq.size())
            {
                int a = tpq.back().first;
                int b = tpq.back().second;
                pq.push({a,b});
                tpq.pop_back();
            }
            
        }
        return true;
    }
};


*/


/*
Using Multi Map Data Structure
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        multiset<int> ms(hand.begin(), hand.end());

        while (!ms.empty()) {
            int start = *ms.begin();
            for (int i = 0; i < groupSize; ++i) {
                if (ms.find(start + i) == ms.end())
                    return false; // If the next consecutive element is not found
                ms.erase(ms.find(start + i));
            }
        }
        return true;
    }
};



*/
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
       int n = hand.size();
        
       if(n%groupSize != 0)
       {
           return false;
       }
       unordered_map<int,int>mp;
       for(auto i:hand)
       {
           mp[i]++;
       }
       
       for(int i=0;i<n;i++)
       {
           int card = hand[i];
           
           while(mp[card-1])
           {
               card--;
           }
           
           while(card <= hand[i])
           {
               while(mp[card])
               {
                   for(int nex=card;nex<card+groupSize;nex++)
                   {
                       if(!mp[nex]) // Corrected typo here from mp[next] to mp[nex]
                       {
                           return false;
                       }
                       mp[nex]--;
                   }
               }
               card++;
           }
       }
        return true;
    
    }
};
