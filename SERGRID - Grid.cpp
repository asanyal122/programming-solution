#include<iostream>
#include<queue>
using namespace std;
long long int a[1001][1001];
long long int visited[1001][1001];
long long int x[4]={-1,1,0,0};
long long int y[4]={0,0,-1,1};


bool isvalid(long long int x,long long int y,long long int n,long long int m)
{
	if(x>=0&&x<n&&y>=0&&y<m)
	return true;
	return false;
}


int main(void)
{
	long long int n,m,i,j,x_top,y_top,x_new,y_new;
	string s;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>s;
		for(j=0;j<m;j++)
		{
			a[i][j]=s[j]-'0';
		}
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			visited[i][j]=0;
		}
	}
	
	queue<pair<int,int>> q;
	q.push(make_pair(0,0));
	visited[0][0]=1;
	long long int value=a[0][0];
	while(!q.empty())
	{
		x_top=q.front().first;
		y_top=q.front().second;
		q.pop();
		for(i=0;i<4;i++)
		{
			x_new=x_top+a[x_top][y_top]*x[i];
			y_new=y_top+a[x_top][y_top]*y[i];
			if(isvalid(x_new,y_new,n,m)&&!visited[x_new][y_new])
			{
				visited[x_new][y_new]=visited[x_top][y_top]+1;
				q.push(make_pair(x_new,y_new));
			}
		}
	}
	if(visited[n-1][m-1]>0)
	cout<<visited[n-1][m-1]-1;
	else
	cout<<-1;
	return 0;
}
