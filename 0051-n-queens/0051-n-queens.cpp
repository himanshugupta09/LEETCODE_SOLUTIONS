class Solution {
public:
    bool isSafe1(int row,int col,vector<string> board,int n){
        int duprow = row;
        int dupcol = col;
        
        while(row>=0 && col>= 0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        
        
        col = dupcol;
        row = duprow;
        while(col>=0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
            
        }
        
        
        return true;
    }
    
    
    
    
    
public:
    void solve(int col,vector<string> &board,vector<vector<string>> &ans,vector<int> &leftRow,
        vector<int> &upperDiagonal,vector<int> &lowerDiagonal,int n){
        
        
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row = 0;row<n;row++){
            if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1+col-row] == 0){
                
                
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1+col-row] = 1;
                solve(col+1,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row+col] = 0;
                upperDiagonal[n-1+col-row] = 0;
                
            }
            
    }
        
        
    }
         
public:
    vector<vector<string>> solveNQueens(int n)
    {
       vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i] = s;
        }
        
        vector<int> leftRow(n,0),upperDiagonal(2*n-1,0),lowerDigonal(2*n-1,0);
        solve(0,board,ans,leftRow,upperDiagonal,lowerDigonal,n);
        return ans;
       
    }
        
    };