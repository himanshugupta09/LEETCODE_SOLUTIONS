class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int maxDepth = -1;
        int depth = 0;

        for(int i=0;i<n;i++)
        {
            if(s[i] == '(')
            {
                depth++;
                maxDepth = max(maxDepth,depth);
            }
            else if(s[i] == ')')
            {
                depth--;
            }
        }
        return max(maxDepth,depth);
    }
};