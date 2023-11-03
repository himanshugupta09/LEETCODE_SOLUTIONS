#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> buildArray(std::vector<int>& target, int n) {
        std::vector<int> stk;
        std::vector<std::string> res;
        int i = 1;
        while (i <= n) {
            if (stk == target) {
                break;
            }
            if (std::find(target.begin(), target.end(), i) != target.end()) {
                stk.push_back(i);
                res.push_back("Push");
            } else {
                res.push_back("Push");
                res.push_back("Pop");
            }
            i++;
        }
        return res;
    }
};

