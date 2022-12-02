class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pascal;
        for(int i=1;i<=rowIndex+1;i++){
            long long int c = 1;
            vector<int> temp;
            for(int j=1;j<=i;j++){
                temp.push_back(c);
                c = c*(i-j)/j;
            }pascal.push_back(temp);
            temp.clear();
        }
        return pascal[rowIndex];
    }
};
