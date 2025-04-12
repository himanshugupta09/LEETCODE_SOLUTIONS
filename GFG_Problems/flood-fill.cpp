//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isValid(int dx, int dy, int n, int m, vector<vector<int>>& image) {
        // Check if the cell is within bounds and is not already the target color (0 or something else)
        return dx >= 0 && dx < n && dy >= 0 && dy < m && image[dx][dy] != 0;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int, int>> q;
        
        int originalColor = image[sr][sc];
        
        // If the original color is the same as the newColor, no need to change anything
        if (originalColor == newColor) {
            return image;
        }
        
        q.push({sr, sc});
        image[sr][sc] = newColor;  // Start by changing the color of the start pixel.

        int delta[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // Directions: right, left, down, up

        // Process the queue
        while (!q.empty()) {
            pair<int, int> po = q.front();
            q.pop();
            int x = po.first;
            int y = po.second;

            // Check all four directions
            for (int i = 0; i < 4; i++) {
                int dx = x + delta[i][0];
                int dy = y + delta[i][1];

                // Only push to the queue if the neighboring cell is valid and has the same color as the original color
                if (dx >= 0 && dx < n && dy >= 0 && dy < m && image[dx][dy] == originalColor) {
                    image[dx][dy] = newColor;  // Change the color of the neighboring cell
                    q.push({dx, dy});  // Add to the queue for further processing
                }
            }
        }

        return image;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
