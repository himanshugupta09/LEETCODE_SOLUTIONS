class Solution {
public:

    bool checker(string& s1,string& s2,string &order)
    {
        int i=0;
        while(i < s1.size() && s1[i] == s2[i])
        {
            i++;
        }
        if(s1.size() == i)
        {
            return true;
        }
        else if(s2.size() == i)
        {
            return false;
        }
        return order.find(s1[i]) < order.find(s2[i]);
    }

    bool isAlienSorted(vector<string>& words, string order) {
        
        for(int i=0;i<words.size()-1;i++)
        {
            if(!checker(words[i],words[i+1],order))
            {
                return false;
            }
        }
        return true;
        
    }
};
