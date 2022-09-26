int Solution::solve(vector<vector<int> > &A) {
    int N = A.size();
    int i = 0;
    if(N == 0) return 0; 
    
    for(i = 1; i<N; i++){
        A[i][0] += min(A[i-1][1], A[i-1][2]); 
        
        A[i][1] += min(A[i-1][0], A[i-1][2]);
        A[i][2] += min(A[i-1][0], A[i-1][1]);
    }
    
    
    
    return min(min(A[i-1][0], A[i-1][1]), A[i-1][2]);
}
