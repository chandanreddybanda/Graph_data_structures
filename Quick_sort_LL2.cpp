#include<iostream>
using namespace std;
typedef struct lnode
{
	int data;
	lnode *next;
}*lptr;
lptr L;
void addback(lptr &L,int k)
{
	if(L==NULL)
	{
	L=new(lnode);
	L->data=k;
	L->next=NULL;
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
void quick(lptr L)
{
	lptr temp=L,l=L;
	while(temp->next!=NULL)
	temp=temp->next;
	int	p=temp->data;int i=0;
	while(l!=temp)
	{
		if(p>l->data)
		i++;
	}
	l=L;int j=i;
	while(j>0)
	l=l->next;
	swap(p,l->data);
	if(i!=0)
	quick(L);
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
	for(int i=10;i>0;i--)
	addback(L,i);
	quick(L);
	display(L);
}
