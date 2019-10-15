/*solution spoj akbar*/
#include<iostream>
#include<map>
#include<queue>
#include<vector>
#include<set>
typedef long long int lli;
using namespace std;
 
int main() {
    int test, src, dest, i, nodes, edges, soldier, number, strn, org, temp;
    scanf("%d", &test);
	
    while (test--) 
	{	
		map<lli,lli> mp;
        scanf("%d %d %d", &nodes, &edges, &soldier);
        vector<vector<lli>> graph(nodes+1);
		lli strength[nodes+1],org_strength[nodes+1],visited[nodes+1],parent[nodes+1];
        set<pair<lli,lli>> s;
        for (i = 0; i <= nodes; i++) 
		{
            visited[i] = -1;
            strength[i] = -1;
            org_strength[i] = -1;
            parent[i]=-1;
        }
        for (i = 0; i < edges; i++) 
		{
            scanf("%d %d", &src, &dest);
            graph[src].push_back(dest);
            graph[dest].push_back(src);
        }
        for (i = 0; i < soldier; i++) 
		{
            scanf("%d %d", &number, &strn);
            strength[number] = strn;
            org_strength[number] = strn;
        }
        for(i=1;i<nodes+1;i++)
        {
        	if(strength[i]!=-1)
        {
			s.insert({0,i});
        	visited[i]=0;
        	parent[i]=i;
        }
		}
        lli dist=0;
        bool res=true;
       /* cout<<"printing\n";
         for(auto ii:s)
            {
            	cout<<ii.second<<" ";
			}*/
        while (!s.empty()) 
		{
            auto its=s.begin();
            org=its->second;
            dist=its->first;
            s.erase(its);
            vector<lli>::iterator it;
			//cout<<endl;
            if(1<=strength[org])
            {
            	for(it=graph[org].begin();it!=graph[org].end();it++)
            	{
            		if(parent[*it]==-1)
            		parent[*it]=parent[org];
            		if((parent[*it]!=parent[org]))
            			{
            					res=false;
						}
            		if(visited[*it]==-1)
            		{
            			visited[*it]=1;
						s.insert({dist+1,*it});
					}
					if(strength[org]-1>=0)
            			{
            				strength[*it]=max(strength[org]-1,strength[*it]);
						}
				}
			}
			/*cout<<"\nset\n";
            for(auto ii:s)
            {
            	cout<<ii.second<<" ";
			}*/
        }
        for (i = 1; i <= nodes; i++) 
		{
            // cout << "i: " << i << " strn: " << strength[i] << endl;
           // cout<<visited[i]<<" ";
            if (visited[i]==-1)
			 {
                res=false;
            }
        }
        printf("%s\n",res ? "Yes" : "No");
    }
 
    return 0;
}
