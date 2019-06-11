#include<bits/stdc++.h>
using namespace std;
long long int a[500][500];
long long int visited[500][500];
long long int x[8]={0,0,1,-1,1,1,-1,-1};
long long int y[8]={1,-1,0,0,-1,1,1,-1};

bool issafe(long long int r,long long int c,long long int n,long long int m)
{
	if(r>=0&&r<n&&c>=0&&c<m)
	return true;
	return false;
}

void dfs(long long int r,long long int c,long long int n,long long int m)
{
	long long int i,x_new,y_new;
	for(i=0;i<8;i++)
	{
		x_new=r+x[i];
		y_new=c+y[i];
		if(!visited[x_new][y_new]&&issafe(x_new,y_new,n,m)&&a[x_new][y_new])
		{
			visited[x_new][y_new]=1;
			dfs(x_new,y_new,n,m);
		}
	}
}

long long int count(long long int n,long long int m)
{
	long long int i,j,count=0;
	memset(visited,0,sizeof(visited));
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(!visited[i][j]&&a[i][j])
			{
				dfs(i,j,n,m);
				count++;
			}
		}
	}
	return count;
}

int main(void)
{
	long long int n,m,i,j,t;
	string s;
	cin>>t;
	while(t--)
	{
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>s;
		for(j=0;j<m;j++)
		{
			if(s[j]=='.')
			a[i][j]=0;
			else
			a[i][j]=1;
		}
	}
	cout<<count(n,m)<<endl;
	}
	return 0;
}
