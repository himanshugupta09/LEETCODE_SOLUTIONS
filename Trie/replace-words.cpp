class TrieNode
{
    public:
        bool isEnd;
        vector<TrieNode*>child;
        
        TrieNode() : child(26,nullptr){isEnd=false;}
};
class Trie
{
    private:
        TrieNode* root;
public:
    Trie(){root = new TrieNode();}
    
    void insert(string word)
    {
        TrieNode* cur = root;
        for(char c:word)
        {
            if(cur->child[c-'a']==nullptr){
                cur->child[c-'a']=new TrieNode();
            }
            cur = cur->child[c-'a'];
        }
        cur->isEnd=true;
    }
    
    string shortestRoot(string word)
    {
        TrieNode* cur = root;
        for(int i=0;i<word.length();i++)
        {
            char c = word[i];
            if(cur->child[c-'a']==nullptr)
            {
                return word;
            }
            cur = cur->child[c-'a'];
            if(cur->isEnd)
            {
                return word.substr(0,i+1);
            }
        }
        return word;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        istringstream sStream(sentence);
        
        Trie dict;
        for(string word:dictionary)
        {
            dict.insert(word);
        }
        
        string word;
        string newSen;
        
        while(getline(sStream,word,' ')){
            newSen += dict.shortestRoot(word)+" ";
        }
        
        newSen.pop_back();
        return newSen;
    }
};
