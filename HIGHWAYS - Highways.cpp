#include<iostream>
#include<list>
#include<vector>
#include<queue>
# define INF 0x3f3f3f3f 
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int t;
	cin>>t;
	while(t--)
	{
		long long int n,e,i,u,p,w,src,d;
		cin>>n>>e>>src>>d;
	vector<vector<pair<long long int,long long int>>> v(n+1);
	for(i=0;i<e;i++)
	{
		cin>>u>>p>>w;
		v[u].push_back(make_pair(p,w));
		v[p].push_back(make_pair(u,w));
	}
	/*for(i=0;i<n;i++)
	{
		for(auto it=v[i].begin();it!=v[i].end();it++)
		{
			cout<<i<<" "<<(it->first)<<" "<<(it->second)<<endl;
		}
	}*/
	priority_queue<long long int,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>>> pq;
	vector<long long int> dist(n+1,INF);
	long long int label;
	dist[src]=0;
	pq.push(make_pair(dist[src],src));
	while(!pq.empty())
	{
		u=pq.top().second;
		if(u==d)
		{
			cout<<pq.top().first<<endl;
			break;
		}
		pq.pop();
		for(auto it=v[u].begin();it!=v[u].end();it++)
		{
			w=it->second;
			label=it->first;
			if(dist[label]>dist[u]+w)
			{
				dist[label]=dist[u]+w;
				pq.push(make_pair(dist[label],label));
			}
		}
	}
		if(dist[d]==INF)
		cout<<"NONE\n";
	}
	return 0;
}
