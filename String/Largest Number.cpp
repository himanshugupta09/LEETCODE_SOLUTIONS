class Solution {
public:
    
    static bool comp(string a,string b)
    {
       
        return a+b > b+a;
    }
    
    string largestNumber(vector<int>& nums) {
        
       string str;
        
       vector<string>v;
        
         for(int i=0;i<nums.size();i++)
            v.push_back(to_string(nums[i]));
        
        sort(v.begin(),v.end(),comp);
        
        for(int i=0;i<v.size();i++)
            str+=v[i];
        
        if(str.size()>1&&str[0]=='0')
        return "0";
        return str;
        
    }
};
