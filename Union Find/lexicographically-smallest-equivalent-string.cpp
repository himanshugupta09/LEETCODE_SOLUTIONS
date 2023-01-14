class Solution {
public:

    vector<int>headChar;

    int find(int x)
    {
        if(headChar[x] == -1)
        {
            return x;
        }
        return headChar[x] = find(headChar[x]);
    }

    void Union(int x,int y)
    {
        int parx = find(x);
        int pary = find(y);

        if(parx == pary)
        {
            return;
        }
        headChar[max(parx,pary)] = min(parx,pary);


    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        headChar.resize(26,-1);

        for(int i=0;i<s1.size();i++)
        {
            Union(s1[i] - 'a',s2[i]-'a');
        }

        for(int i=0;i<baseStr.size();i++)
        {
            baseStr[i] = find(baseStr[i]-'a') + 'a';
        }

        return baseStr;
    }
};
