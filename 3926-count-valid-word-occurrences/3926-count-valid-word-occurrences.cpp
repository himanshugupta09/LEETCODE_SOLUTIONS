class Solution {
public:
    bool isLow(char ch){
        if(ch>='a' && ch<='z')return true;
        return false;
    }
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        unordered_map<string,int>mp;
        string curr="";
        string s="";
        for(string str:chunks)s+=str;
        int  n=s.size();
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(isLow(ch))curr+=ch;
            else if(ch=='-'){
               if(curr.size()!=0 && i+1<n && isLow(s[i+1]))curr+='-';
               else{
                    if(curr.size()!=0){
                    mp[curr]++;
                    curr="";
                }
               }
            }
            else{
                if(curr.size()!=0){
                    mp[curr]++;
                    curr="";
                }
            }
        }
        
        if(curr.size()!=0)mp[curr]++;
        vector<int>ans;
        for(string str:queries){
            if(mp.find(str)!=mp.end())ans.push_back(mp[str]);
            else ans.push_back(0);
        }
        return ans;
    }
};