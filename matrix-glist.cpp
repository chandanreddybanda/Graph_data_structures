#include<iostream>
using namespace std;
struct adnode;
typedef struct gnode
{
	int data;
	gnode *vnext;
	adnode *alist;
}*gptr;
typedef struct adnode
{
	gnode *av;
	adnode *avnext;
}*adj;
gptr search(gptr G,int k)
{
	while(G->data!=k)
	G=G->vnext;
	return G;
}
void createvlist(gptr &G,int k)
{
	if(G==NULL)
	{
		G=new(gnode);
		G->data=k;
		G->alist=NULL;
		G->vnext=NULL;
	}
	else
	{
		gptr g=G;
		while(g->vnext!=NULL)
		g=g->vnext;
		gptr l;
		l=new(gnode);
		l->data=k;
		l->alist=NULL;
		l->vnext=NULL;
		g->vnext=l;
	}
}
void adjacentvlist(gptr G,int v,int key)
{
	gptr h=search(G,key);
	gptr l=search(G,v);
	adj a=l->alist;
	if(a==NULL)
	{
		a=new(adnode);
		a->av=h;
		a->avnext=NULL;
		l->alist=a;
	}
	else
	{
		while(a->avnext!=NULL)
		a=a->avnext;
		adj b;
		b=new(adnode);
		b->av=h;
		b->avnext=NULL;
		a->avnext=b;
	}
}
void print(gptr G)
{
	while(G!=NULL)
	{
		cout<<G->data<<" -> ";
		adj c=G->alist;
		while(c!=NULL)
		{
			cout<<c->av->data<<" ";
			c=c->avnext;
		}
		G=G->vnext;cout<<endl;
	}
}
int main()
{
	int g[5][5];
	for(int i=0;i<5;i++)
	for(int j=0;j<5;j++)
	g[i][j]=0;
	g[0][1]=1;g[1][2]=1;g[2][0]=1;g[2][3]=1;g[0][3]=1;g[1][4]=1;g[4][3]=1;
	gptr G=NULL;
	int ch=1;
	for(int i=0;i<5;i++)
	{
		createvlist(G,ch);
		ch=ch+1;
	}
	gptr h=G;
	for(int i=0;i<5;i++)
	{
		int k=0;
		while(k!=5)
		{
			if(g[i][k]==1)
			adjacentvlist(G,h->data,k+1);
			k++;
		}
		h=h->vnext;
	}
	print(G);
}
