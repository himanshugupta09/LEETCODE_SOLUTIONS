class Solution {
public:
    bool findPattern(string& s) {
        int n = s.size();
        int i = 0;
        while (i < n) {
            int xCount = 0, yCount = 0;
            
            // Count consecutive 'x's
            while (i < n && s[i] == 'x') {
                xCount++;
                i++;
            }
            
            // Count consecutive 'y's
            while (i < n && s[i] == 'y') {
                yCount++;
                i++;
            }
            
            // There must be at least one 'x' and counts must match
            if (xCount == 0 || xCount != yCount) {
                return false;
            }
        }
        return true;
    }
};