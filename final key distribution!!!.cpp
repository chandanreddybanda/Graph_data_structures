#include<iostream>
using namespace std;
int d=1;
typedef
struct blnode{
	int count;
	struct blnode *pptr;
	int key[3];
	struct blnode *link[4];
	blnode()
	{count=0;
	}
}*blptr;
struct stack
    {	int size;
        int top;
        blptr elements[20];
	stack()
	{size=20;
	top=-1;
	}
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
blptr peep(stack &s)
{if(stkmt(s))
return NULL;
else
return s.elements[s.top];
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
blptr tleft(int a[],blptr b[])
{
	int z;
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
void overflow(blptr t)
{int i;
	blptr p;
	int ar[(2*d)+1],x;blptr br[(2*d)+2];
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
	{
	int i,n,x,flag=0,q,count;
	p=t->pptr;
	x=check_leaf(p,ar[d]);
	if(x<2*d&&!flag)
	{
		if(p->link[x+1]!=NULL)
		{
			count=p->link[x+1]->count;
			if(count<2*d)
			{flag=1;q=p->key[x];
			blptr rc;rc=p->link[x+1];
			for(int i=count;i>0;i--)
			{rc->key[i]=rc->key[i-1];
			rc->link[i+1]=rc->link[i];
			}
			if(rc->link[0]!=NULL)
			{rc->link[1]=rc->link[0];
			rc->link[0]=t->link[2*d+1];
			}
			rc->key[0]=q;
			rc->count++;
			p->key[x]=ar[2*d];
			t->count--;
			push(s,p);
			}
		}
	}
	if(x>0&&!flag)
	{
		count=p->link[x-1]->count;
		if(count<2*d)
		{
		flag=1;q=p->key[x-1];
		blptr lc;lc=p->link[x-1];
		lc->key[count]=q;
		lc->count++;
		p->key[x-1]=ar[0];
		if(t->link[0]!=NULL)
		{
		lc->link[count+1]=t->link[0];	
		}	
		for(int i=0;i<2*d;i++)
		{t->key[i]=t->key[i+1];
		t->link[i]=t->link[i+1];
		}
		t->link[2*d]=t->link[2*d+1];
		t->count--;
		push(s,p);
		}
	}
	if(!flag)
	{
	n=p->count;
	for(i=n;ar[d]<p->key[i-1]&&i>0;i--)
	{
	p->link[i+1]=p->link[i];
	p->key[i]=p->key[i-1];
	}
	tl=tleft(ar,br);
	tr=tright(ar,br);
	p->link[i]=tl;
	p->link[i+1]=tr;
	tl->pptr=p;
	tr->pptr=p;
	p->key[i]=ar[d];
	p->count++;
	push(s,p);
	}
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
			{if(dm->key[i]<dm->key[i-1])
			swap(dm->key[i],dm->key[i-1]);
			}
			dm->count++;
			while(dm->count==2*d+1)
			{overflow(dm);
			dm=pop(s);
			}
			while(dm->pptr!=NULL)
			dm=dm->pptr;
	return dm;
	}
}
int main()
{
	blptr t,x;t=NULL;int k;char ch;
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
