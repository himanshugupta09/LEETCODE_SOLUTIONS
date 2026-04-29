class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();

        unordered_map<char,int> freq;

        const set<char> vowels = {'e','o','u','i','a'};

        unordered_map<char, int> order;

        int order_num = 0;

        for (auto ch : s) {
            if (!vowels.contains(ch)) continue;
           
            freq[ch]++;

            if (!order.contains(ch))
            {
                order[ch] = order_num++;
            }                      
        }

        vector<pair<int,char>> sorted;

        for (const auto& [ch, count] : freq)
        {
            sorted.emplace_back(count, ch);
        }    

        sort(begin(sorted), end(sorted), [&](const auto& l, const auto& r){
            if (l.first == r.first)
            {
                return order[l.second] < order[r.second];
            }
            return l.first >= r.first;
        });

        int i{};

        for (auto& ch : s)
        {
            if (!vowels.contains(ch)) continue;           

            ch = sorted[i].second;
            sorted[i].first--;
            if (sorted[i].first == 0) i++;
        }

        return s;
    }
};