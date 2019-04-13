#include<iostream>
using namespace std;
int a[11][11];
int h;
typedef struct gnode
{
	int vertex;
	bool visit;
}*gptr;
void shit(gptr g[],int x,int b[]);
void sta(gptr g[],int b[],int l)
{
	for(int i=l;i<h;i++)
	shit(g,b[i],b);
}
void shit(gptr g[],int x,int b[])
{
	g[x]->visit=1;int l=h;
	for(int i=1;i<11;i++)
	{
		if(a[x][i]!=0&&g[i]->visit!=1)
		{
			g[i]->visit=1;
			b[h++]=i;
		}
	}
	if(l!=h)
	sta(g,b,l);
}
int main()
{
	int b[11];
	cout<<"Enter number of edges -> ";
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int s,t;
		cin>>s>>t;
		a[s][t]=1;
		//a[t][s]=1;
	}
	int x=1;
	gptr g[11];
	for(int i=0;i<11;i++)
	{
		b[i]=0;
		g[i]=new gnode;
		g[i]->vertex=i;
		g[i]->visit=0;
	}
	h=1;
	b[h-1]=1;
	shit(g,1,b);
	for(int i=0;i<11;i++)
	{
		cout<<b[i]<<" ";
	}
}
