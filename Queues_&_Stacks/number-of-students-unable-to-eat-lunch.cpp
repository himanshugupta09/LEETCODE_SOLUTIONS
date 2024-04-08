class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        stack<int>st;
        queue<int>q;
        int n = students.size();
        
        for(int i=0;i<n;i++)
        {
            q.push(students[i]);
            st.push(sandwiches[n-i-1]);
        }
        
        int res = 0;
        
        while(!q.empty() && q.size() > res)
        {
            if(st.top() == q.front())
            {
                st.pop();
                q.pop();
                res = 0;
            }
            else
            {
                q.push(q.front());
                q.pop();
                res++;
            }
        }
        return res;
    }
};
