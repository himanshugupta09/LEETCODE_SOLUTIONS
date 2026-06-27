class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>stk;
        int n = heights.size();
        int maxArea = 0;
        for(int i=0;i<=n;i++)
        {
            int curr = i == n  ? 0 : heights[i];
            while(!stk.empty() && heights[stk.top()] > curr)
            {
                int h = heights[stk.top()];
                stk.pop();
                int w = stk.empty() ? i : i - stk.top() - 1;
                maxArea = max(maxArea,w*h);
            }
            stk.push(i);
        }
        return maxArea;
    }
};