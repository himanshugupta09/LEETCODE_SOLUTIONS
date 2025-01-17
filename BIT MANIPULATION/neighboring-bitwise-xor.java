class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int Xor = 0;
        for(auto i:derived)
        {
            Xor ^= i;
        }
        return Xor == 0;
    }
};
