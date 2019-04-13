#include<iostream>
using namespace std;
int maxx(int a,int b,int c)
{
	if(a>=b&&a>=c)
	return 1;
	else if(b>=a&&b>=c)
	return 0;
	else
	return -1;
}
void find(int a[][7],int b[],int x,int v)
{
	for(int i=1;i<x;i++)
	{
		for(int j=i;j<x;j++)
		{
			if(a[b[i]][b[j]]!=0)
			{
				int m=maxx(a[v][b[i]],a[b[i]][b[j]],a[v][b[j]]);
				if(m==1)
				{
					a[v][b[i]]=0;
					a[b[i]][v]=0;
				}
				else if(m==0)
				{
					a[b[i]][b[j]]=0;
					a[b[j]][b[i]]=0;
				}
				else
				{
					a[v][b[j]]=0;
					a[b[j]][v]=0;
				}
			}
		}
	}
}
void kalaba(int a[][7],int v)
{
	int b[7];
	for(int i=1;i<7;i++)
	b[i]=0;
	int j=1;
	for(int i=1;i<7;i++)
	{
		if(a[v][i]!=0)
		b[j++]=i;
	}
	find(a,b,j,v);
}
int main()
{
	int a[7][7];
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<7;j++)
		a[i][j]=0;
	}
	for(int i=0;i<9;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=z;
		a[y][x]=z;
	}
	for(int i=6;i>0;i--)
	kalaba(a,i);
	for(int i=1;i<7;i++)
	{
		for(int j=1;j<7;j++)
		cout<<a[i][j]<<" ";
		cout<<endl;
	}
}
