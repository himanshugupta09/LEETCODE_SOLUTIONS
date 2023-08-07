class Solution {
public:
    bool binarySearch(vector<int> &a,int target)
    {
        int low = 0,high = a.size()-1;

        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(a[mid] == target)
            {
                return true;
            }
            else if(a[mid] < target)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return 0;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        for(int i=0;i<matrix.size();i++)
        {
            bool ok = binarySearch(matrix[i],target);
            if(ok)
            {
                return true;
            }
        }

        if(matrix.size() == 1 && matrix[0].size() == 1)
        {
            return 1 ? matrix[0][0] == target : 0;
        }
        return 0;
        
    }
};
