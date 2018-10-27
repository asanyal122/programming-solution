#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main() 
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	long long int n,i;
	stack<int> s;
	while(t)
	{
	cin>>n;
	long long int a[n];
	vector<long long int> mp(n);
	for(i=0;i<n;i++)
	cin>>a[i];
	s.push(0);
	for(i=1;i<n;i++)
	{
		if(s.empty())
		{
			s.push(i);
			continue;
		}
		while(!s.empty()&&a[s.top()]<a[i])
		{
			mp[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty())
	{
		mp[s.top()]=-1;
		s.pop();
	}
	for(i=0;i<n;i++)
	{
		if(mp[i]!=-1)
		cout<<a[mp[i]]<<" ";
		else
		cout<<"-1"<<" ";
	}
	cout<<endl;
	t--;
	}
	return 0;
}
