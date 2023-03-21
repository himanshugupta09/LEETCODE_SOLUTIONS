class Solution {
public:
    vector<int> evenOddBit(int n) {
        unsigned int dec = n;
        
        const int l = 12;
        string binary = bitset<l>(dec).to_string();
        int eve = 0,odd = 0;
        for(int i=0;i<binary.size();i++)
        {
            if(i%2 == 0 && binary[i] - '0' == 1)
            {
                eve++;
            }
            if(i%2 != 0 && binary[i]-'0' == 1)
            {
                odd++;
            }
        }
        return {odd,eve};
        
    }
};
