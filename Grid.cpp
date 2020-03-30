#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

is_valid(lli i,lli j,lli n,lli m)
{
	return (i>=0&&i<n&&j>=0&&j<m);
}

int main(void)
{
	lli n,m,q,si,sj,di,dj,i,j;
	cin>>n>>m>>q;
	string s[n];
	lli visited[n][m];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			visited[i][j]=-1;
		}
	}
	
	
	for(i=0;i<n;i++)
	{
		cin>>s[i];
	}
	
	lli x[4]={-1,0,0,1};
	lli y[4]={0,1,-1,0};
	cin>>si>>sj;
	si--;sj--;
	queue<pair<lli,lli>> qbfs;
	qbfs.push(make_pair(si,sj));
	visited[si][sj]=0;
	while(!qbfs.empty())
	{
		si=qbfs.front().first;
		sj=qbfs.front().second;
		qbfs.pop();
		for(i=0;i<4;i++)
		{
			di=si+x[i];
			dj=sj+y[i];
			
			if(is_valid(di,dj,n,m)&&s[di][dj]=='O'&&visited[di][dj]==-1)
			{
				qbfs.push(make_pair(di,dj));
				visited[di][dj]=visited[si][sj]+1;
			}
		}
	}
	
	for(i=0;i<q;i++)
	{
		cin>>di>>dj;
		di--;dj--;
		cout<<visited[di][dj]<<endl;
	}
	return 0;
}
