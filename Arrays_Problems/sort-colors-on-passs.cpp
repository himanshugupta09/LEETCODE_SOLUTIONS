// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int z = 0;
//         int o = 0;
//         int t = 0;
        
        
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i] == 0)
//             {
//                 z++;
//             }
//             else if(nums[i] == 1)
//             {
//                 o++;
//             }
//             else
//             {
//                 t++;
//             }
//         }
        
//         int i=0;
//         while(i < nums.size())
//         {
//             if(z > 0)
//             {
//                 nums[i] = 0;
//                 z--;
//             }
//             else if(o > 0)
//             {
//                 nums[i] = 1;
//                 o--;
//             }
//             else
//             {
//                 nums[i] = 2;
//                 t--;
//             }
//             i++;
//         }
//         //return nums;
        
        
//     }
// };


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
