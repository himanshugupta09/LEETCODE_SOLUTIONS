class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int ones = count(s.begin(),s.end(),'1');
        if(!ones || ones < k){
            return "";
        }
        
        //cout << ones;
        int shortest = INT_MAX;
        string res = s;

        
        int n = s.size();
        int left = 0,right=0;
        int onec = 0;

        while(right < n)
        {
            onec += s[right]-'0';
            while(onec > k && left < right)
            {
                if(s[left] == '1')
                {
                    onec--;
                    left++;
                }
                else
                {
                    left++;
                }
            }
            
            if(onec == k)
            {
                while(s[left] == '0') left++;
                int curr = right-left+1;
                if (curr < shortest || (curr == shortest && s.substr(left, curr) < res))
                {
                    shortest = curr;
                    res = s.substr(left,curr);
                }
            }
            right++;
        }
        return res;
    }
};