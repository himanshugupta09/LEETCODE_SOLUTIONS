class Solution {

    struct TrieNode{
        char c;
        int las;
        string word;
        TrieNode* childNode[26];
    };

    struct TrieNode *getNode(char c){
        TrieNode* newNode = new TrieNode;
        newNode->c = c;
        newNode->las = 0;
        newNode->word = "";


        for(int i=0;i<26;i++)
        {
            newNode->childNode[i] = NULL;

        }
        return newNode;

    }

    TrieNode* root = getNode('/');

    void insert(string s)
    {
        TrieNode* curNode = root;

        int id,i = 0;

        while(s[i])
        {
            id = s[i]-'a';

            if(curNode->childNode[id] == NULL)
            {
                curNode->childNode[id] = getNode(s[i]);
            }
            curNode = curNode->childNode[id];
            i++;

        }

        curNode->las += 1;
        curNode->word  = s;

    }


    void help(vector<vector<char>> &board,int i,int j,int r,int c,vector<string> &res,TrieNode *curNode)
    {


        //Base case
        //If the trie doesn't have the current char OR cell is Visited
        int index = board[i][j]-'a';
        if(board[i][j]=='$' || curNode->childNode[index]==NULL)  
            return;

        curNode = curNode->childNode[index];

        if(curNode->las > 0)
        {
            res.push_back(curNode->word);
            curNode->las -= 1;

        }   

        char ch = board[i][j];
        board[i][j] = '$';

        if(i>0)     //TOP
        {
            help(board,i-1,j,r,c,res,curNode);

        }
        if(i<r-1)   //DOWN
        {
            help(board,i+1,j,r,c,res,curNode);
        }
        if(j>0)     //LEFT
        {
            help(board,i,j-1,r,c,res,curNode);
        }    
        if(j<c-1)   //RIGHT
        {
            help(board,i,j+1,r,c,res,curNode);
        }
        
        board[i][j] = ch;   





    }


public:
     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

      int r = board.size();
      int c = board[0].size();

      for(int i=0;i<words.size();i++)
      {
          insert(words[i]);
      }  

      vector<string> res;
    for(int i=0;i<r;++i)
    {
        for(int j=0;j<c;++j)
        {
            help(board,i,j,r,c,res,root);
        }
    }    
        return res;



    }
};


static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();


