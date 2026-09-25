class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        unordered_set<string>union_set;
        unordered_set<string>current_set = {""};

        stack<pair<unordered_set<string>, unordered_set<string>>> st;
        vector<string>ans;

        for(int i=0;i<expression.size();i++)
        {
            if(expression[i] == '{')
            {
                st.push({union_set,current_set});
                current_set = {""};
                union_set.clear();
            }
            else if(expression[i] == '}')
            {
                unordered_set<string>block_result = union_set;
                for(auto s:current_set) block_result.insert(s);
                auto past_state = st.top();
                st.pop();
                union_set = past_state.first;
                unordered_set<string> new_current_set;
                for (string past_str : past_state.second) {
                    for (string block_str : block_result) {
                        new_current_set.insert(past_str + block_str);
                    }
                }
                current_set = new_current_set;
            }
            else if(expression[i] == ',')
            {
                for(string s:current_set)
                {
                    union_set.insert(s);
                }
                current_set = {""};
            }
            else
            {
                unordered_set<string> next_current_set;
                for (string s : current_set) {
                    next_current_set.insert(s + expression[i]);
                }
                current_set = next_current_set;
            }
        }
        for(auto i:current_set)
        {
            ans.push_back(i);
        }
        for(auto i:union_set)
        {
            ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
}; 