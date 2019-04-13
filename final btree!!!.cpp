#include<iostream>
using namespace std;
int d=1;
typedef
struct blnode{
	int count;
	struct blnode *pptr;
	int key[5];
	struct blnode *link[6];
	blnode()
	{count=0;}
}*blptr;
struct stack
    {	int size;
        int top;
        blptr elements[20];
	stack()
	{size=20;
	top=-1;}
}s;
int stkful(stack &s)
{
if(s.top==s.size-1)
return 1;
else
return 0;}
int stkmt(stack &s)
{if(s.top==-1)
return 1;
else
return 0;}
void push(stack &s,blptr x)
{if(stkful(s))
cout<<"stack is full";
else
{s.top++;
s.elements[s.top]=x;
}
}
blptr pop(stack &s)
{
if(stkmt(s))
{cout<<s.top<<"\nstack is empty";
return NULL;}
else
return s.elements[s.top--];
}
void print(blptr t)
{
	if(t!=NULL)
	{
		for(int i=0;i<t->count;i++)
		{print(t->link[i]);
		cout<<t->key[i]<<"-"<<t->count<<endl;
		}
		print(t->link[t->count]);
	}
}
//defining Queue and its operations
struct Queue
{
	int f;
	int r;
	int size;
	blptr elements[50];
};
int iseq(Queue& Q)
{
	if(Q.f==-1)
		return 1;
	else
		return 0;
}
int isfq(Queue& Q)
{
	if(Q.f==(Q.r+1)%Q.size)
		return 1;
	else 
		return 0;
}
void enq(Queue& Q,blptr x)
{
	if(isfq(Q))
		cout<<"The queue is full";
	else 
	{
		if(iseq(Q))
		{
			Q.f=0;
			Q.r=0;
			Q.elements[Q.r]=x;
		}
		else
		{
			Q.r=(Q.r+1)%Q.size;
			Q.elements[Q.r]=x;
		}
	}
}
blptr deq(Queue& Q)
{
	blptr x;
	if(iseq(Q))
	{
		cout<<"The queue is empty";
		return NULL;
	}
	else
	{
		x=Q.elements[Q.f];
		if(Q.f==Q.r)
		{
			Q.f=-1;
			Q.r=-1;
		}
		else
		{
			Q.f=(Q.f+1)%Q.size;
		}
		return x;
	}
}
void levelorder(blptr T,int d)
{
	int i;
	Queue Q;
	Q.f=-1;
	Q.r=-1;
	Q.size=20;
	enq(Q,T);
	blptr M;
	M=new blnode;
	M->key[0]='*';
	enq(Q,M);
	while(Q.f!=Q.r)
	{
		M=deq(Q);
		if(M->key[0]=='*')
		{
			cout<<endl;
			enq(Q,M);
			M=deq(Q);
		}
		for(i=0;i<M->count;i++)
		{
			cout<<M->key[i]<<" ";
			if(M->link[i]!=NULL)
			enq(Q,M->link[i]);
		}
		if(M->link[i]!=NULL)
		enq(Q,M->link[i]);
	}
}
int check_leaf(blptr t,int k)
{	if(t->link[0]==NULL)
	return -1;
	else
	{int i=0,count;count=t->count;
	while(k>t->key[i]&&i<count)
	i++;
	return i;
	}
}
blptr tleft(int a[],blptr b[])
{
	blptr tl;int i;
	tl=new blnode;
	for(i=0;i<d;i++)
	{tl->key[i]=a[i];
	tl->link[i]=b[i];
	if(b[i]!=NULL)
	{
	tl->link[i]->pptr=tl;
	}	
	}
	tl->link[i]=b[i];
	if(b[i]!=NULL)
	tl->link[i]->pptr=tl;
	i++;
	for(i;i<(2*d)+2;i++)
	tl->link[i]=NULL;
	tl->count=d;
	return tl;
}
blptr tright(int a[],blptr b[])
{
	blptr tr;int i,j,z;
	tr=new blnode;
	for(j=0,i=d+1;i<(2*d)+1;i++,j++)
	{tr->key[j]=a[i];
	tr->link[j]=b[i];
	if(b[i]!=NULL)
	tr->link[j]->pptr=tr;
	}
	tr->link[j]=b[i];
	if(b[i]!=NULL)
	tr->link[j]->pptr=tr;
	j++;
	for(j;j<(2*d)+2;j++)
	tr->link[j]=NULL;
	tr->count=d;
	return tr;	
}
void overflow(blptr t)
{int i;
	blptr p;
	int ar[(2*d)+1];blptr br[(2*d)+2];
	for(i=0;i<t->count;i++)
	{ar[i]=t->key[i];
	br[i]=t->link[i];
	}
	br[i]=t->link[i];
	blptr tl,tr,temp;
	if(t->pptr==NULL)
	{
		tl=tleft(ar,br);
		tr=tright(ar,br);
		temp=new blnode;
		temp->key[0]=ar[d];
		temp->link[0]=tl;
		temp->link[1]=tr;
		tr->pptr=temp;
		tl->pptr=temp;
		temp->count=1;
		temp->pptr=NULL;
		for(int i=2;i<(2*d)+2;i++)
		temp->link[i]=NULL;
		push(s,temp);
	}
	else
	{int i,n;
	p=t->pptr;
	n=p->count;
	tl=tleft(ar,br);
	tr=tright(ar,br);
	for(i=n;ar[d]<p->key[i-1]&&i>0;i--)
	{
	p->link[i+1]=p->link[i];
	p->key[i]=p->key[i-1];
	}
	p->link[i]=tl;
	p->link[i+1]=tr;
	tl->pptr=p;
	tr->pptr=p;
	p->key[i]=ar[d];
	p->count++;
	push(s,p);
	}	
}
blptr add(blptr t,int k)
{
blptr dm;dm=t;
	if(t==NULL)
	{
		t=new blnode;
		t->key[t->count]=k;
		t->count++;
		t->pptr=NULL;
		for(int i=0;i<(2*d)+2;i++)
		t->link[i]=NULL;
		return t;
	}
	else
	{int x;
	x=check_leaf(dm,k);
	while(x!=-1)
	{
		dm=dm->link[x];
		x=check_leaf(dm,k);
	}
	dm->key[dm->count]=k;
			for(int i=dm->count;i>0;i--)
			{
			if(dm->key[i]<dm->key[i-1])
			swap(dm->key[i],dm->key[i-1]);
			}
			dm->count++;
			while(dm->count==2*d+1)
			{
				overflow(dm);
				dm=pop(s);
			}
			while(dm->pptr!=NULL)
			dm=dm->pptr;
			return dm; 	
	}
}
int main()
{
	blptr t;t=NULL;int k;char ch;
	do{
		cout<<"enter data";
		cin>>k;
		t=add(t,k);
		cout<<"root is\n";
		cout<<t->key[0];
		cout<<"\nelements in tree are\n";
		print(t);
		cout<<endl;
		levelorder(t,d);
		cout<<"\nto continue enter y";
		cin>>ch;
	}while(ch=='y');
return 0;
}
