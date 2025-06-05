class Solution {
public:
    vector<int>parent;
    int find(int X)
    {
        if(parent[X] == -1)
        {
            return X;
        }
        return parent[X] = find(parent[X]);
    }
    void unionFind(int X,int Y)
    {
        int parX = find(X);
        int parY = find(Y);
        if(parX == parY)
        {
            return;
        }
        parent[max(parX,parY)] = min(parX,parY);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26,-1);
        for(int i=0;i<s1.size();i++)
        {
            unionFind(s1[i]-'a',s2[i]-'a');
        }
        for(int i=0;i<baseStr.size();i++)
        {
            baseStr[i] = find(baseStr[i]-'a') +'a';
        }
        return baseStr;

    }
};