
class Solution 
{
	public:
	int solve(int n,string s)
	{
		//code here
		unordered_map<char,int>mp;
		mp['a'] = mp['i'] = mp['e'] = mp['o'] = mp['u'] = 1;
		
		for(char &c:s)
		{
		    c = '0' + mp[c];
		}
		int cnt1 = 0,cnt2 = 0;
		
		for(int i=0;i<n;i++)
		{
		    int x = s[i] - '0';
		    if(x  != (i%2))
		    {
		        cnt1++;
		        
		    }
		    if(x == (i%2))
		    {
		        cnt2++;
		    }
		}
		
		return min(cnt1,cnt2);
		
	}
};
