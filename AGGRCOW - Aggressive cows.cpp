#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(void)
{
	ll t,n,c,i,j,gap;
	cin>>t;
	while(t--)
	{
		cin>>n>>c;
		ll s[n];
		for(i=0;i<n;i++)
		{
			cin>>s[i];
		}
		sort(s,s+n);
		ll l=0,r=(s[n-1]-s[0])/c+1,mid,ans=-1,place;
		while(l<=r)
		{
			mid=l+(r-l)/2;
			//cout<<"mid "<<mid<<endl;
			place=0;
			for(i=1;i<c;i++)
			{
				place=lower_bound(s,s+n,s[place]+mid)-s;
				if(place==n)
				{
					break;
				}
			}
			if(i==c)
			{
				ans=max(ans,mid);
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
