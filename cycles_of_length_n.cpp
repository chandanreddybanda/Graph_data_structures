#include<iostream>
using namespace std;
int a[6][6];
typedef struct gnode
{
	int vertex;
	bool visit;
}*gptr;
void cycle(int v,gptr g[],int n,int first,int &count)
{
	if(n==0)
	{
		if(a[v][first]==1)
		{
			count++;
			cout<<"1";
			return;
		}
		else
		return;
	}
	g[v]->visit=1;
	for(int i=1;i<6;i++)
	{
		if(a[v][i]!=0 && g[i]->visit==0)
		cycle(i,g,n-1,first,count);
	}
	g[v]->visit=0;
}
int main()
{
	gptr g[6];
	for(int i=0;i<6;i++)
	{
		int x,y;
		cin>>x>>y;
		a[x][y]=1;
		a[y][x]=1;
		g[i]=new gnode;
		g[i]->vertex=i;
		g[i]->visit=0;
	}
	int count=0;
	for(int i=1;i<2+1;i++)
	{
		cycle(i,g,4,i,count);
		g[i]->visit=1;
	}
	cout<<count<<" ";
}
