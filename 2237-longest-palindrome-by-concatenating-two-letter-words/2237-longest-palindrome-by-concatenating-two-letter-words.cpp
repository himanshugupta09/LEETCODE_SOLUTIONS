class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mpp;
        for(int i=0;i<words.size();i++)
        {
            mpp[words[i]]++;
        }
        
        int res = 0,pal = 0;
        for(auto& [w,freq]:mpp)
        {
            string rev = w;
            reverse(rev.begin(),rev.end());
            
            if(rev == w)
            {
                res += (freq/2)*4;
                if(freq%2) pal = 1;
            }
            else if(w < rev && mpp.count(rev))
            {
                res+= min(freq,mpp[rev])*4;
            }
        }
        return res+ pal*2;
    }
};