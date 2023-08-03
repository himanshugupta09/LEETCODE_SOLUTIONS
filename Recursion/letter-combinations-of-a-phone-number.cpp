class Solution {
public:
    vector<string> res;
    void getCombinations(string digits, unordered_map<string, string>& numbers, string& temp, int index) {
        if (index == digits.size()) {
            res.push_back(temp);
            return;
        }

        string letters = numbers[digits.substr(index, 1)];
        for (char letter : letters) {
            temp.push_back(letter);
            getCombinations(digits, numbers, temp, index + 1);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<string, string> numbers;
        numbers["2"] = "abc";
        numbers["3"] = "def";
        numbers["4"] = "ghi";
        numbers["5"] = "jkl";
        numbers["6"] = "mno";
        numbers["7"] = "pqrs";
        numbers["8"] = "tuv";
        numbers["9"] = "wxyz";

        string temp;
        if(digits.size() == 0)
        {
            return res;
        }
        getCombinations(digits, numbers, temp, 0);
        return res;
    }
};
