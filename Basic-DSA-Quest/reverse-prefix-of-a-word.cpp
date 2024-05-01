class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        int n = word.size();
        int i;
        for(i=0;i<n;i++)
        {
            if(word[i] == ch)
            {
                break;
            }
        }
        if((n-i) > 0){
            i++;
            reverse(word.begin(),word.begin()+i);
        }
        return word;
    }
};
