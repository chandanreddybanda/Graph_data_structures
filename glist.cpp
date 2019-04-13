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
	gptr G=NULL;
	int ch=1;
	for(int i=0;i<5;i++)
	{
		createvlist(G,ch);
		ch=ch+1;
	}
	gptr g=G;char k;
	for(int i=0;i<5;i++)
	{
		do
		{
			cout<<"Enter the elments adjacent to "<<g->data<<" -> ";
			int c;
			cin>>c;
			adjacentvlist(G,g->data,c);
			cout<<"Enter n to exit -> ";
			cin>>k;
		}while(k!='n');
		g=g->vnext;
	}
	print(G);
}
