class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        unordered_set<char> opens = {'(', '{', '['};

        unordered_map<char, char> mpp = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char ch : s) {
            if (opens.count(ch)) {
                stk.push(ch);
            } else {
                if (stk.empty() || stk.top() != mpp[ch]) {
                    return false;
                }
                stk.pop();
            }
        }

        return stk.empty();
    }
};