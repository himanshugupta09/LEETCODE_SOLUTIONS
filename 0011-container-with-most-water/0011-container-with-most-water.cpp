class Solution {
public:
    int maxArea(vector<int>& height) {

        int maxVolume = INT_MIN;
        int i = 0;
        int j = height.size()-1;
        while(i < j)
        {
            int area = (j-i)*min(height[i],height[j]);
            maxVolume = max(maxVolume,area);
            if(height[i] < height[j])
            {
                i++;
            }
            else if(height[i] > height[j])
            {
                j--;
            }
            else
            {
                i++;
                j--;
            }
        }
        return maxVolume;
        
    }
};