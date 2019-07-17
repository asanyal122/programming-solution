/* LUCIFER */
#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<utility>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdlib>

using namespace std;
long long int prime[501];
void sieve()
{
	long long int i,j;
	memset(prime,1,sizeof(prime));
	prime[0]=prime[1]=0;
	for(i=2;i<501;i++)
	{
		if(prime[i])
		{
		for(j=2*i;j<=500;j+=i)
		{
			prime[j]=0;
		}
		}
	}
}
string tostring(long long n)
{
   string s;
   while(n!=0)
  {
      s+=(n%10)+'0';
      n/=10;
   }
    reverse(s.begin(), s.end());
    return s;
}

long long dp[12][2][83][83]; //dp[index][smaller][remainder]

//For integers, the sum of digits can't be greater than 82

long long k;

string s;

long long dp_solve(string &s,int index,bool smaller,int es,int os,string s1)
{
	
 if(index==s.length())
 {
 	
        if(es>os&&prime[es-os])
        {
        	//cout<<s1<<endl;
            return 1;
        }
     return 0;
 }
  if(dp[index][smaller][es][os]!=-1)
      {
       return dp[index][smaller][es][os];

      }
    else
    {
        int limit=9;

        if(smaller)
        {
            limit=s[index]-'0';
        }
        long long init_count=0;

        for(int i=0;i<=limit;i++)
        {
            bool ns;
            s1+=(i+'0');
            if(i<s[index]-'0')
            {   
                ns=0;
            }
            else
            {
                ns=smaller;
            }
			if((s.length()-index)%2==0)
            init_count+=dp_solve(s, index+1, ns,es+i,os,s1);
            else
            init_count+=dp_solve(s, index+1, ns,es,os+i,s1);
			s1.pop_back();
        }

        dp[index][smaller][es][os]=init_count;
        return init_count;

    }

}


int main()
{
		sieve();
	  int t;
	  cin>>t;
	  while(t--)
	  {
      int a,b; //Find numbers between A and B whose sum of digits is divisible by K
      cin>>a>>b;

      //If A and B are ints, then the sum of the digits can't be greater than 82
        

        string s=tostring(a-1);
        string s2=tostring(b);
		string s1="";
        memset(dp,-1,sizeof(dp));
        long long a1=dp_solve(s,0,1,0,0,s1); //Solving for a-1

		s1="";
        memset(dp,-1,sizeof(dp));
        long long a2=dp_solve(s2, 0, 1, 0,0,s1); //Solving for b

        cout<<a2-a1<<endl;
		}

    return 0;
}
