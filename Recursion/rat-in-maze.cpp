//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// User function template for C++

class Solution{
    public:
        void findPaths(vector<vector<int>>& maze, int n, int i, int j, string path, vector<string>& paths) {
        // Check if the current cell is a valid position
        if (i < 0 || i >= n || j < 0 || j >= n || maze[i][j] == 0) {
            return;
        }

        // Check if the destination has been reached
        if (i == n - 1 && j == n - 1) {
            paths.push_back(path);
            return;
        }

        // Mark the current cell as visited
        maze[i][j] = 0;

        // Explore all possible directions: Up, Down, Left, Right
        findPaths(maze, n, i - 1, j, path + 'U', paths); // Up
        findPaths(maze, n, i + 1, j, path + 'D', paths); // Down
        findPaths(maze, n, i, j - 1, path + 'L', paths); // Left
        findPaths(maze, n, i, j + 1, path + 'R', paths); // Right

        // Mark the current cell as unvisited (backtrack)
        maze[i][j] = 1;
    }

    vector<string> findPath(vector<vector<int>>& maze, int n) {
        vector<string> paths;
        findPaths(maze, n, 0, 0, "", paths);
        sort(paths.begin(), paths.end()); // Sort the paths lexicographically
        return paths;
    }
};

    

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
