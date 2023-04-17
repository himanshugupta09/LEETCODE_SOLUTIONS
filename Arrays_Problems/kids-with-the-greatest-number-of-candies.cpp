class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_candies = *max_element(candies.begin(),candies.end());

        vector<bool>res(candies.size(),true);

        for(int i=0;i<candies.size();i++)
        {
            if(candies[i]+extraCandies < max_candies)
            {
                res[i] = false;
            }
        }
        return res;
    }
};
