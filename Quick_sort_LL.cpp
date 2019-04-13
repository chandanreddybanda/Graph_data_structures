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
void  quick(lptr L,lptr low,lptr high)
{
	lptr l=low->next;
	lptr h=high;
	lptr p=low;
	if(low!=high)
	{
		while(l!=h)
		{
			while(p->data>l->data)
			l=l->next;cout<<"k";
			while(p->data<h->data)
			{
				lptr temp=low;
				while(temp->next!=h)
				temp=temp->next;
				h=temp;
			}
			swap(l->data,h->data);
		}
		swap(p->data,h->data);
		quick(L,low,h);
		quick(L,h->next,high);
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
	for(int i=10;i>0;i--)
	addback(L,i);
	lptr low=L;
	lptr high,k=low;
	while(k->next!=NULL)
	k=k->next;
	high=k;
	quick(L,low,high);
	display(L);
}
