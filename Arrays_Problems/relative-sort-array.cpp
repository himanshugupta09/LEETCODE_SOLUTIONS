
//Appraoch using HashMap
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        vector<int>arr;
        
        for(auto i:arr1)
        {
            mp[i]++;
        }
        // arr1.erase(arr1.begin(),arr1.end());
        
        for(int i=0;i<arr2.size();i++)
        {
            while(mp[arr2[i]])
            {
                arr.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }
        for(auto i:mp)
        {
            while(i.second > 0)
            {
                arr.push_back(i.first);
                i.second--;
            }
        }
        return arr;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Solution {
public:
    // Approach with couting sort
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxi = *max_element(arr1.begin(),arr1.end());
        
        vector<int>count(maxi+1);
        
        for(int ele:arr1)
        {
            count[ele]++;
        }
        vector<int>res;
        
        for(auto ele:arr2)
        {
            while(count[ele] > 0)
            {
                res.push_back(ele);
                count[ele]--;
            }
        }
        for(int num = 0;num<=maxi;num++)
        {
            while(count[num] > 0)
            {
                res.push_back(num);
                count[num]--;
            }
        }
        return res;
    }
};
