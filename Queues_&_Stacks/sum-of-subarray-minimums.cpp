class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1000000007;
        stack<int>s;

        /* 
        For Solving the Problem we used the concept of Monotone Stack

        1. Firslty we have taken a stack and iterated through the array.
        2. if stack is empty then we push element into stack else we make Comparision from top of stack and current array element.
        3. if Curr_ele is less than our top then we pop till not stack is empty and calculated subarrays by the formula as
           =>>==>>>
           cnt = (md-left_mini)*(right_mini)
           
           where -> left_mini is the top of stack if stack is not empty
                 -> right_mini is the index of the element in array that is less than out top of stack
        4. We add this cnt in our result.

        */



        long  res = 0;

        for(int i=0;i<=arr.size();i++)
        {

            while(!s.empty() && (i == arr.size() || arr[s.top()] >= arr[i]))
            {
                int md = s.top();
                s.pop();
                int left_min = s.empty() ? -1 : s.top();
                int right_min = i;

                long  cnt = (md-left_min)*(right_min-md)%MOD;

                res += (cnt*arr[md])%MOD;
                res%=MOD;

            }
            s.push(i);

        }

        return (int)(res);

        



    }
};
