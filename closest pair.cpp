#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long int ll;

class point
{
	public:
	ll x,y,z;
};

db min_dist=99999999999.99;
ll a,b;

point arr[500001],strip[500001];

int cmpx(const void *a1,const void *a2)
{
	point *p1=(point *)a1,*p2=(point *)a2;
	return (p1->x-p2->x);
}

int cmpy(const void *a1,const void *a2)
{
	point *p1=(point *)a1,*p2=(point *)a2;
	return (p1->y-p2->y);
}

db dist(point p1,point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

void brutedist(ll l,ll r,ll n)
{
	ll i,j;
	for(i=l;i<r;i++)
	{
		for(j=i+1;j<=r;j++) 
		{
			if(min_dist>dist(arr[l],arr[r]))
			{
				min_dist=dist(arr[l],arr[r]);
				a=arr[l].z;
				b=arr[r].z;
			}
		}
	}
}

void cp(ll l,ll r)
{
	//cout<<"call"<<l<<" "<<r;
	if(r-l+1<=3)
	{
		brutedist(l,r,r-l+1);
		return;
	}
	
	ll mid=l+(r-l)/2;
	ll i,j;
	point midpoint=arr[mid];
	cp(l,mid);
	cp(mid+1,r);
	for(i=l;i<=r;i++)
	{
		strip[i]=arr[i];
	}
	qsort(strip+l,r-l+1,sizeof(point),cmpy);
	for(i=l;i<r;i++)
	{
		for(j=i+1;j<=r&&(strip[j].y-strip[i].y)<min_dist;j++)
		{
			if(min_dist>dist(strip[i],strip[j]))
			{
				min_dist=dist(strip[i],strip[j]);
				a=strip[i].z;
				b=strip[j].z;
			}
		}
	}
	return;
}

int main(void)
{
	ll n,i,j;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>arr[i].x>>arr[i].y;
		arr[i].z=i;
	}
	qsort(arr,n,sizeof(point),cmpx);
	cp(0,n-1);
	cout<<min(a,b)<<" "<<max(a,b)<<" "<< fixed<<setprecision(6)<<min_dist<<endl;
	return 0;
}
