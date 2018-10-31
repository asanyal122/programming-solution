#include<iostream>
using namespace std;
class trienode
{
	public:
	trienode *children[26];
	int isend;
};
trienode *getnode(void)
{
	trienode *newnode=new trienode();
	if(newnode)
	{
	newnode->isend=0;
	int i;
	for(i=0;i<26;i++)
	{
		newnode->children[i]=nullptr;
	}
}
	return newnode;
}
int search(trienode *root,string s)
{
	trienode *curr=root;
	int i;
	for(i=0;i<s.length();i++)
	{
		int index=s[i]-'a';
		if(!curr->children[index])
		return 0;
		curr=curr->children[index];
	}
	return (curr->isend&&curr);
}
trienode *insert(trienode *root,string s)
{
	trienode *current=root;
	int i;
	for(i=0;i<s.length();i++)
	{
		int index=s[i]-'a';
		if(!current->children[index])
		{
			current->children[index]=getnode();
		}
		current=current->children[index];
	}
	current->isend=1;
	return root;
}
void display(trienode *root,char s[],int i)
{
	if(root->isend)
	{
		s[i]='\0';
		cout<<s<<endl;
	}
	int j;
	for(j=0;j<26;j++)
	{
		if(root->children[j])
		{
			char ch=j+'a';
			s[i]=ch;
			display(root->children[j],s,i+1);
		}
	}
}
int main(void)
{
	int t,n;
	cin>>t;
	while(t)
	{
		cin>>n;
		int i;
		string a[n];
		for(i=0;i<n;i++)
		cin>>a[i];
		trienode *root=getnode();
		for(i=0;i<n;i++)
		{
			root=insert(root,a[i]);
		}
		string s;
		cin>>s;
	cout<<search(root,s)<<endl;
	char s1[30];
	display(root,s1,0);
		t--;
	}
	return 0;
}
