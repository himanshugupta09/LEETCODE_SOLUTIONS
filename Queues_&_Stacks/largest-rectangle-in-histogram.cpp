class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        
        stack <int>st;
        int area=0;
        
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int h=heights[st.top()];
                st.pop();
                
                if(st.empty()){
                    area=max(area,h*i);
                }
                else{
                    int l=i-st.top()-1;
                    area=max(area,h*l);
                } 
                 
            }
            st.push(i);
        }
        return area;
    }
};
