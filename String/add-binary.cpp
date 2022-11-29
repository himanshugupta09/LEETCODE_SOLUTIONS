class Solution {
public:
    string addBinary(string a, string b) {

       string res;
       int i = a.size()-1;
       int j = b.size()-1;
       int c = 0;

       while(i >= 0 ||j >= 0)
       {
           int sum = c;
           if(i >= 0) sum += a[i--]-'0';
           if(j >= 0) sum += b[j--]-'0';
           c = sum>1?1:0;
           res += to_string(sum%2);


       }
       if(c){
           res += to_string(c);
       }
       reverse(res.begin(),res.end());
       return res;
    }
};
