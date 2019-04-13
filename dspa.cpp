#include<iostream>
using namespace std;
typedef struct gnode
{
	int x;
	int y;
	int v;
}*gptr;
int main()
{
	gptr g[8];
	int a[8][8];
	for(int i=1;i<8;i++)
	{	
		g[i]=new gnode;
		g[i]->x=9999;
		g[i]->y=9999;
		g[i]->v=0;
		for(int j=1;j<8;j++)
		a[i][j]=0;
	}
	a[1][2]=4;a[1][6]=5;a[2][4]=1;a[2][3]=2;a[3][4]=3;a[3][5]=10;a[4][1]=2;a[4][6]=8;a[4][7]=4;a[4][5]=2;a[5][7]=6;a[7][6]=1;
	int s,d;
	s=1;d=7;
	int c=s;
	g[s]->x=0;
	g[s]->y=s;
	g[s]->v=1;
	while(c!=d)
	{
		int l=9999,m=c;
		for(int i=1;i<8;i++)
		{
			if(a[c][i]!=0 && g[i]->v!=1)
			{
				if(g[i]->x==9999)
				{
					g[i]->x=g[c]->x+a[c][i];
					g[i]->y=c;
				}
				else
				{
					if(g[i]->x>a[c][i])
					{
						g[i]->x=a[c][i]+g[c]->x;
						g[i]->y=c;
					}
				}
			}
			if(l>=g[i]->x)
			{
				l=g[i]->x;
				m=i;
			}
		}
		c=m;cout<<c<<" ";
		g[c]->v=1;	
	}
}
