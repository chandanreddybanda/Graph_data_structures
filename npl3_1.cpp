#include<bits/stdc++.h>
using namespace std;
long long int a[100000][100000];
typedef struct bnode
{
	bnode *lchild;
	int data;
	bnode *rchild;
}*bptr;
bptr T;
void create(bptr &T,int ch)
{
	if(T==NULL)
	{
		T=new(bnode);
		T->data=ch;
		T->lchild=NULL;
		T->rchild=NULL;
	}
	else
	{
		if(ch>T->data)
		create(T->rchild,ch);
		else
		create(T->lchild,ch);
	}
}
int per(bptr T)
{
	if(T->lchild==NULL&&T->rchild==NULL)
	return 1;
	else if(T->lchild==NULL)
	return per(T->rchild);
	else if(T->rchild==NULL)
	return per(T->lchild);
	else
	return 2*per(T->lchild)*per(T->rchild);
}
int send(bptr &T,int n,int r,long long int a[][100000])
{
	create(T,r);
	for(int i=1;i<=n;i++)
	{
		if(a[r][i]==1)
		send(T,n,i,a);
	}
}
int main()
{
	bptr T=NULL;	
	int n,r;
	cin>>n>>r;
	a[n][n];
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		a[x][y]=1;
	}
	send(T,n,r,a);
	cout<<per(T)%1000000007;
}
