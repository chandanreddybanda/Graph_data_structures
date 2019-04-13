#include<iostream>
using namespace std;
int a[6][6];
typedef struct gnode
{
	int vertex;
	int visit;
}*gptr;int x=1;
int dft(gptr g[],int start,int dest,int s[])
{
	g[start]->visit=1;
	for(int i=1;i<6;i++)
	{
		if(a[start][i]!=0 && g[i]->visit!=1)
		{
			s[x]=(g[i]->vertex);x++;
			if(g[i]->vertex==dest)
			{
				return *s;
			}
		return 	dft(g,i,dest,s);
		}
	}
	x--;
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
	int s[10];
	cout<<"Enter the source vertex and destination vertex -> ";
	int z,y;
	cin>>z>>y;
	s[0]=z;
	*s=dft(g,z,y,s);
	for(int j=0;j<x;j++)
	cout<<s[j]<<" ";
}
