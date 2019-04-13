#include<iostream>
using namespace std;
typedef struct lnode
{
	int data;
	lnode *next;
}*lptr;
void add(lptr &L,int k)
{
	if(L==NULL)
	{
		lptr T;
		T=new(lnode);
		T->data=k;
		T->next=L;
		L=T;
	}
	else
	{
		lptr T,R;
		R=L;
		T=new(lnode);
		while(R->next!=NULL)
		{
			R=R->next;
		}
		T->data=k;
		R->next=T;
		T->next=NULL;
		R=T;
	}
}
void addmid(lptr &L,int v,lptr &h)
{
	lptr l=L;lptr k=L;
	while(l!=NULL)
	{
		if(l->data==v)
		break;
		else
		l=l->next;
	}
	lptr m=h;
	if(k==l)
	{
		while(h->next!=NULL)
		h=h->next;
		h->next=l;
		l=m;
	}
	else
	{
		while(k->next!=l)
		k=k->next;
		k->next=m;
		while(m->next!=NULL)
		m=m->next;
		m->next=l->next;
	}
}
int check(int a[][7],int b[])
{
	int k=0;
	for(int i=1;i<7;i++)
	{
		int count=0;
		for(int j=1;j<7;j++)
		{
			if(a[i][j]==1)
			count=count+1;
		}
		if(count%2!=0)
		{
			b[k++]=i;
		}
	}
}
int order(int a[][8],int v)
{
	int count=0;
	for(int i=1;i<8;i++)
	{
		if(a[v][i]==1)
		count++;
	}
	return count;
}
int sdft(int a[][8],int v,int current,lptr &L)
{
	add(L,v);
	for(int i=1;i<8;i++)
	{
		if(a[v][i]==1)
		{
			a[v][i]=0;
			a[i][v]=0;
			if(current!=i)
			{
				sdft(a,i,current,L);
				break;
			}
			else
			break;
		}
	}
}
int dft(int a[][8],int v,int current,lptr &L)
{
	sdft(a,v,current,L);
	add(L,current);
}
int splice(int a[][8],lptr &L,lptr &h)
{
	lptr l=L;
	while(l!=NULL)
	{
		if(order(a,l->data)!=0)
		{
			dft(a,l->data,l->data,h);
			//addmid(l,l->data,h);
		}
		l=l->next;
	}
}
void display(lptr &L)
{
	lptr K;
	K=L;
	while(K!=NULL)
	{
		cout<<K->data<<" ";
		K=K->next;
	}
}
int main()
{
	lptr L=NULL;
	int g[8][8];
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++)
	g[i][j]=0;
	g[1][5]=1;g[5][1]=1;g[1][7]=1;g[7][1]=1;g[7][5]=1;g[5][7]=1;g[3][4]=1;g[4][3]=1;g[3][2]=1;g[2][3]=1;g[1][2]=1;g[2][1]=1;g[2][4]=1;g[4][2]=1;g[1][6]=1;g[6][1]=1;g[2][6]=1;g[6][2]=1;g[6][5]=1;g[5][6]=1;g[4][5]=1;g[5][4]=1;g[4][6]=1;g[6][4]=1;
	dft(g,6,6,L);display(L);
	lptr h=NULL;
	splice(g,L,h);
	
}
