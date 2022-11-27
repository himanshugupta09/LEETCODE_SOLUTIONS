class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string s,t;
        int i,size1,size2;
        size1=word1.size();
        size2=word2.size();
        for(s="",i=0;i<size1;i++) s+=word1[i];
        for(t="",i=0;i<size2;i++) t+=word2[i];
        if(s==t) return true;
        return false;
        
    }
};
