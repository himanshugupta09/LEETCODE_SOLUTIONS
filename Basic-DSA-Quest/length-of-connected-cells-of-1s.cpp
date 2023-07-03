#include<bits/stdc++.h>
using namespace std;


/*
Finding the length of connected cells of 1s (regions) in an matrix of Os and
1s: Given a matrix, each of which may be 1 or 0. The filled cells that are connected form a
region. Two cells are said to be connected if they are adjacent to each other horizontally,
vertically or diagonally. There may be several regions in the matrix. How do you find the
largest region (in terms of number of cells) in the matrix?

*/

int getval(vector<vector<int>>& A,int i,int j,int n,int m)
{
    if(i < 0 || i >= n || j < 0 || j >= m)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void findMaxBlock(vector<vector<int>>& A,int r,int c,int n,int m,int sz,vector<vector<bool>>& cnt,int mxsz)
{
    if(r >= n || c >= m)
    {
        return;
    }

    cnt[r][c] = true;
    sz++;

    if(sz > mxsz)
    {
        mxsz = sz;
    }

    int dir[][2] = {{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};

    for(int i=0;i<8;i++)
    {
        int newi = r + dir[i][0];
        int newj = c + dir[i][1];

        int val = getval(A,newi,newj,n,m);

        if(val > 0 && (cnt[newi][newj]) == false)
        {
            findMaxBlock(A,newi,newj,n,m,sz,cnt,mxsz);
        }
    }
    cnt[r][c] = false;
}


int getMaxOnes(vector<vector<int>>& A,int rmax,int cmax)
{
    int mxsz = 0;
    int sz = 0;

    vector<vector<bool>>cnt(rmax,vector<bool>(cmax,false));

    for(int i=0;i<rmax;i++)
    {
        for(int j=0;j<cmax;j++)
        {
            if(A[i][j] == 1)
            {
                findMaxBlock(A,i,j,rmax,cmax,0,cnt,mxsz);
            }
        }
    }

    return mxsz;
}


int main()
{
    int A[][5] = {{1,1,0,0,0},{0,1,1,0,1},{0,0,0,1,1},{1,0,0,1,1},{0,1,0,1,1}};

    cout  << "Number of Maximum 1s are " << getMaxOnes(A,5,5) << "\n";

    return 0;
}

/*
At each level of the recurrence tree, the number of problems is double from the
previous level, while the amount of work being done in each problem is half from the previous
level. Formally, the i
th
level has 2

i problems, each requiring 2

n–i work. Thus the i
th
level requires

exactly 2

n work. The depth of this tree is n, because at the i
th
level, the originating call will be

T(n – i). Thus the total complexity for T(n) is T(n2
n
).
*/
