class Solution {
  public:
    int transform(string &s1, string &s2) {
        // code here
       unordered_map<char,int>hash1;
       unordered_map<char,int>hash2;
       if(s1.size() != s2.size()){
           return -1;
       }
       for(auto i:s1){
           hash1[i]++;
       }
       for(auto i:s2){
           hash2[i]++;
       }
       for(auto i:s1)
       {
           if(hash2[i] != hash1[i])
           {
               //cout << hash1[i] << " " << hash2[i]; 
               return -1;
           }
       }
       int res = 0;
       int p2 = s2.size()-1;
       int p1 = s1.size()-1;
       while(p2 >= 0 && p1 >= 0)
       {
           if(s1[p1] == s2[p2])
           {
               p1--;
               p2--;
           }
            else
            {
                p1--;
                res++;
            }
       }
       return res;
    }
};
