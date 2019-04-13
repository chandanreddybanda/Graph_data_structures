#include<iostream>
using namespace std;
typedef struct gnode
{
	int vertex;
	int visit;
}*gptr;
int B[8][8];int x=1;
int dft(gptr g[],int start,int dest,int s[])
{
	g[start]->visit=1;
	for(int i=1;i<8;i++)
	{
		if(B[start][i]!=0 && g[i]->visit!=1)
		{
			s[x]=g[i]->vertex;
			x++;
			if(g[i]->vertex==dest)
			{
				return *s;
			}
			return dft(g,i,dest,s);
		}
	}
	x--;
}
int find(int S[],int i)
{
	if(S[i]<0)
	{
		return i;
	}
	else
	{
		return find(S,S[i]);
	}
}
void unio(int S[],int i,int j)
{
	S[find(S,j)]=find(S,i);
}

int main()
{
	int n,S[8],G[8][8],A[20];
	gptr g[8];
	for(int i=1;i<=7;i++)
	for(int j=1;j<=7;j++)
	{
	G[i][j]=0;
	B[i][j]=0;
	S[i]=-1;
	g[i]=new gnode;
	g[i]->vertex=i;
	g[i]->visit=0;
	}
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int p,q,w;
		cin>>p>>q>>w;A[i]=w;
		G[p][q]=G[q][p]=w;
	}
	
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<n+1-i;j++)
		{
			if(A[j]>A[j+1])
			{
				swap(A[j],A[j+1]);
			}
		}
	}
	int y=1;int c=1;int f;
	while(c!=7)
	{
		f=0;
		for(int i=1;i<=7;i++)
		{
			for(int j=i;j<=7;j++)
			{
				if(A[y]==G[i][j]&&find(S,i)!=find(S,j))
				{
					B[i][j]=B[j][i]=A[y];
					y++;
					unio(S,i,j);
					c++;
					f=1;
					break;
				}
			}
			if(f==1)break;
		}
		if(f==0)y++;
	}
	int aa,bb,dd,ee;
	for(int i=1;i<=7;i++)
	{
		for(int j=1;j<=7;j++)
		{
			if(G[i][j]==A[y])
			{
				aa=i;bb=j;
			}
		}
		cout<<endl;
	}
	int s[20];
	s[0]=aa;
	*s=dft(g,aa,bb,s);int cc=-1;
	for(int i=0;i<x-1;i++)
	{
		if(B[s[i]][s[i+1]]>cc)
		{
			cc=B[s[i]][s[i+1]];
			dd=s[i];
			ee=s[i+1];
		}
	}
	B[dd][ee]=0;
	B[ee][dd]=0;
	B[aa][bb]=A[y];
	B[bb][aa]=A[y];
	for(int i=1;i<8;i++)
	{
		for(int j=1;j<8;j++)
		cout<<B[i][j]<<" ";
		cout<<endl;
	}
}

