#include <iostream>
#include <vector>

using namespace std;

int getval(vector<vector<int>>& A, int i, int j, int n, int m)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return 0;
    }
    else
    {
        return A[i][j];
    }
}

void findMaxBlock(vector<vector<int>>& A, int r, int c, int n, int m, int sz, vector<vector<bool>>& cnt, int& mxsz)
{
    if (r >= n || c >= m)
    {
        return;
    }

    cnt[r][c] = true;
    sz++;

    if (sz > mxsz)
    {
        mxsz = sz;
    }

    int dir[][2] = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};

    for (int i = 0; i < 8; i++)
    {
        int newi = r + dir[i][0];
        int newj = c + dir[i][1];

        int val = getval(A, newi, newj, n, m);

        if (val > 0 && !cnt[newi][newj])
        {
            findMaxBlock(A, newi, newj, n, m, sz, cnt, mxsz);
        }
    }
    cnt[r][c] = false;
}

int getMaxOnes(vector<vector<int>>& A, int rmax, int cmax)
{
    int mxsz = 0;
    int sz = 0;

    vector<vector<bool>> cnt(rmax, vector<bool>(cmax, false));

    for (int i = 0; i < rmax; i++)
    {
        for (int j = 0; j < cmax; j++)
        {
            if (A[i][j] == 1)
            {
                findMaxBlock(A, i, j, rmax, cmax, 0, cnt, mxsz);
            }
        }
    }

    return mxsz;
}

int main()
{
    vector<vector<int>> A = {{1, 1, 0, 0, 0},
                             {0, 1, 1, 0, 1},
                             {0, 0, 0, 1, 1},
                             {1, 0, 0, 1, 1},
                             {0, 1, 0, 1, 1}};

    cout << "Number of Maximum 1s are " << getMaxOnes(A, 5, 5) << "\n";

    return 0;
}
