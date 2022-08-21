class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
		int n = target.size(), m = stamp.size();
		vector<int> ans;
		for(int i = 0; i < n; ++i) {
			int j = 0;
			int k = i;
			while(k < n && j < m && stamp[j] == target[k]) {
				k++;
				j++;
				}
				if(j == m) {
					ans.push_back(i);
					for(int itr = i; itr < i + m; ++itr) {
						target[itr] = '?';
						}
					}
			}
			//cout << target << endl;
			for(int i = 0; i < n; ++i) {
				int j = 0;
				int k = i;
				bool ok = true;
				while(k < n && j < m) {
					if(stamp[j] == target[k] || target[k] == '?') {
						if(target[k] != '?') ok = false;
						k++; j++;
						}
					else break;
					}
					if(j == m && ok == false) {
						ans.push_back(i);
						for(int itr = i; itr < i + m; ++itr) {
							target[itr] = '?';
							}
						}
				}
				for(int i = n - 1; i >= 0; --i) {
					int j = 0;
					int k = i;
					bool ok = true;
					while(k < n && j < m) {
						if(stamp[j] == target[k] || target[k] == '?') {
							if(target[k] != '?') ok = false;
							k++;
							j++;
							}
							else break;
						}
						if(j == m && ok == false) {
							ans.push_back(i);
							for(int itr = i; itr < i + m; ++itr) {
								target[itr] = '?';
								}
							}
					}
					for(auto it : target) {
						if(it != '?') {
							ans.clear();
							break;
							}
						}
						reverse(ans.begin(), ans.end());
						return ans;
    }
};
