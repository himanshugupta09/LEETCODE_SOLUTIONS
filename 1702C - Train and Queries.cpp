#include<iostream>
#include<map>
#include<utility>
using namespace std;

void ans()
{
	int n,k;
	cin>>n>>k;
	map<int, pair<int, int>>stat;
	
	for(int i=0;i<n;i++)
	{
		int a;cin>>a;
		if(!stat.count(a)){
			stat[a].first = i;
			stat[a].second = i;
			
		}
		else{
			stat[a].second = i;
		}
	}
	for(int i=0;i<k;i++)
	{
		int a,b;cin>>a>>b;
		if(!stat.count(a) or !stat.count(b) or stat[a].first > stat[b].second){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n";
		}
	}
	
}

int main()
{
	int t;cin>>t;
	while(t--)
	{
		ans();
	}
	return 0;
}
