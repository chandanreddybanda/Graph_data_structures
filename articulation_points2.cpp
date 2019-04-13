#include<bits/stdc++.h>
using namespace std;
int visited[100],num[100],low[100],parent[100],a_p[100],t;
int g[100][100];
void dfs(int v,int n)
{
	visited[v] = 1;
	num[v] = t; 
	low[v] = t;
	int i;
	int child=0;
	t++;
	for (i=0;i<n;i++)
	{
		if(g[v][i]==1&&visited[i]==0)
		{
			dfs(i,n);
			parent[i] = v;
 			low[v] = min(low[v],low[i]);
			child++;
			if(parent[v]==-1 && child>1)
			{
				a_p[v] = 1;
			}
			 if(parent[v]!=-1 && num[v]<=low[i])
			{
				a_p[v] = 1;
			}
		}
		else if(i!=parent[v])
		{
			low[v] = min(low[v],low[i]);
		}
	}
}
int main()
{
	
	int t,x,y,i,j,e,n;
	cin>>n>>e;
	for (i=0;i<e;i++)
	{
		cin>>x>>y;
		g[x][y]=1;
		g[y][x]=1;
	}
	for(int i=0;i<100;i++)
	a_p[i]=0;
	for(int i=0;i<100;i++)
	visited[i]=0;
	parent[0] = -1;
	t=0;
	dfs(0,n);
	for (i=0;i<n;i++)
	{
		if(a_p[i])
		cout <<i<<" ";
	}
}
