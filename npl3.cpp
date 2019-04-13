#include<bits/stdc++.h>
using namespace std;
int a[10000][10000];
int count(int a[][10000],int l,int n)
{
	int c=0;
	for(int i=1;i<=n;i++)
	{
		if(a[l][i]==1)
		c++;
	}
	return c;
}
int ans(int a[][10000],int x,int n)
{
	if(count(a,x,n)==0)
	return 1;
	else if(count(a,x,n)==2)
	{
		int y=0,z=0;
		for(int i=1;i<=n;i++)
		{
			if(a[x][i]==1)
			{
				if(y==0)
				y=i;
				else
				z=i;
			}
		}
		return count(a,x,n)*(ans(a,y,n)+ans(a,z,n));
	}
	else
	{
		int y=0;
		for(int i=1;i<=n;i++)
		{
			if(a[x][i]==1)
			{
				y=i;
			}
		}
		return count(a,x,n)*(ans(a,y,n));
	}
}
int main()
{
	int n,r;
	cin>>n>>r;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		a[x][y]=1;
	}
	cout<<ans(a,r,n)/2;
}
