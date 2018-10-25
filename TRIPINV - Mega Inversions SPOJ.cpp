#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
long long int read(long long int *tree,long long int val)
{
	long long int sum=0;
	while(val>=1)
	{
		sum+=tree[val];
		val=val-((-val)&val);
	 } 
	 return sum;
}
void update(long long int *tree,long long int val,long long int n)
{
	while(val<=n)
	{
		tree[val]++;
		val=val+((-val)&val);
	 } 
	 return;
}
int main(void)
{
	long long int n,i;
		cin>>n;
	long long int a[n];
		for(i=0;i<n;i++)
		{
				cin>>a[i];
		}
		//cin>>x;
		/*for(i=0;i<n;i++)
		cout<<a[i]<<" ";cout<<endl;*/
		long long int tree[n+1]={0};
		long long int count=0;
		long long int small[n]={0};
		long long int big[n]={0};
		for(i=0;i<n;i++)
		{
			big[i]=i-read(tree,a[i]);
			update(tree,a[i],n);
		}
		for(i=1;i<n+1;i++)
		tree[i]=0;
		for(i=n-1;i>=0;i--)
		{
			small[i]=read(tree,a[i]-1);
			update(tree,a[i],n);
		}
		for(i=0;i<n;i++)
		{
			count+=small[i]*big[i];
		}
		cout<<count<<endl;
		//for(i=1;i<n;i++)
		//cout<<small[i]<<" ";
	return 0;
} 
