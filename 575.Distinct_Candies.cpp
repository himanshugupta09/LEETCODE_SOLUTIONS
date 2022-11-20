class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        
        set<int>typ(candyType.begin(),candyType.end());
        
        return min(typ.size(),(candyType.size()/2));
        
        
        
        
    }
};
