#include<iostream>
using namespace std;
typedef struct gnode
{
	int data;
	int v;
	int value;
}*gptr;
int r=0;
void sdft(gptr h[],int b[][11],int c)
{
	for(int i=1;i<11;i++)
	{
		if(b[c][i]!=0 && h[i]->v==0)
		{
			h[i]->v=1;
			cout<<h[i]->data<<" ";r++;
			b[c][i]=0;
			b[i][c]=0;
			sdft(h,b,i);
		}
	}
}
int z=1;
void dft(gptr g[],int a[][11],int c)
{
	for(int i=1;i<11;i++)
	{
		if(a[c][i]!=0 && g[i]->v==0)
		{
			g[i]->v=1;
			a[c][i]=0;
			a[i][c]=0;
			dft(g,a,i);
		}
	}
	g[c]->value=z;z++;
}
int main()
{
	gptr g[11],h[11];
	int a[11][11];
	int b[11][11];
	for(int i=11;i>0;i--)
	{
		g[i]=new gnode;
		g[i]->data=i;
		g[i]->v=0;
		g[i]->value=0;
		h[i]=new gnode;
		h[i]->data=i;
		h[i]->v=0;
		h[i]->value=0;
	}
	for(int i=1;i<11;i++)
	for(int j=1;j<11;j++)
	{
		a[i][j]=0;
		b[i][j]=0;
	}
	for(int i=0;i<15;i++)
	{
		int x,y;
		cin>>x>>y;
		a[x][y]=1;
		b[y][x]=1;
	}
	int c=2;
	g[c]->v=1;
	while(z<=10)
	{
		dft(g,a,c);
		while(g[c]->v==1)
		c++;
	}
	for(int i=1;i<11;i++)
	h[i]->value=g[i]->value;
	int m=10;
	while(m>=0)
	{
		for(int i=1;i<11;i++)
		{
			if(g[i]->value==m)
			{
				g[i]->v=1;
				cout<<i<<" ";
				sdft(h,b,i);
				cout<<endl;
			}
		}
		m=m-r;
		r=0;
	}
}
