#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
long int read(int *tree,int val)
{
	long int sum=0;
	while(val>=1)
	{
		sum+=tree[val];
		val=val-((-val)&val);
	 } 
	 return sum;
}
void update(int *tree,int val,int n)
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
	int t;
	cin>>t;
	int n,i;
	while(t)
	{
		cin>>n;
		char s[n+1];
		int a[n],b[n];
		char x='a';
		for(i=0;i<n;i++)
		{
				cin>>a[i];
				b[i]=a[i];
		}
		//cin>>x;
		sort(b,b+n);
		for(i=0;i<n;i++)
		{
			a[i]=(lower_bound(b,b+n,a[i])-b)+1;
		}
		/*for(i=0;i<n;i++)
		cout<<a[i]<<" ";cout<<endl;*/
		int tree[n+1]={0};
		long int count=0;
		int small[n]={0};
		int big[n]={0};
		for(i=0;i<n;i++)
		{
			small[i]=read(tree,a[i]-1);
			update(tree,a[i],n);
		}
		for(i=1;i<n+1;i++)
		tree[i]=0;
		for(i=n-1;i>=0;i--)
		{
			update(tree,a[i],n);
			big[i]=n-i-read(tree,a[i]);
		}
		for(i=0;i<n;i++)
		{
			count+=small[i]*big[i];
		}
		cout<<count<<endl;
		/*for(i=1;i<n+1;i++)
		cout<<tree[i]<<" ";*/
		t--;
	}
	return 0;
}
