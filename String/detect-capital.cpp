class Solution {
public:
    bool detectCapitalUse(string word) {
        int upperCount = 0;
        int lowerCount = 0;

        for(auto i:word)
        {
            if(isupper(i))
            {
                upperCount++;
            }
            else
            {
                lowerCount++;
            }
        }

        if(word.size() == 1)
        {
            return true;
        }

        if((upperCount == 0 || upperCount == 1 || upperCount == word.size()) &&(lowerCount == 0 || lowerCount == word.size()-1 || lowerCount == word.size()))
        {
            if(upperCount == 1 && isupper(word[0]))
            {
                return true;
            }
            else if(upperCount == word.size())
            {
                return true;
            }
            else if(lowerCount == word.size())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
};
