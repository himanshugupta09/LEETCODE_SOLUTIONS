class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {

        for(int i=1;i<n;i++)
        {
            
            int b = n-i;
            if((to_string(i)+to_string(b)).find('0') == string::npos)
            {
                return {i,b};
            }
        }
        return {};
    }
};