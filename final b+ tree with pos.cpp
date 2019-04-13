#include<iostream>
using namespace std;
int d=1,position=0;
union u{
	int pos;
	struct blnode *link;
};
typedef
struct blnode{
	bool leaf;
	int count;
	struct blnode *pptr;
	int key[5];
	u link[6]; 
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

		for(int i=0;i<t->count;i++)
		{if(!t->leaf)
		print(t->link[i].link);
		if(!t->leaf)
		cout<<t->key[i]<<"-"<<t->count<<endl;
		else
		cout<<t->key[i]<<"-"<<t->count<<"and position is"<<t->link[i].pos<<endl;
		}
		if(!t->leaf)
		print(t->link[t->count].link);
	
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
			if(!M->leaf)
			enq(Q,M->link[i].link);
		}
		if(!M->leaf)
		enq(Q,M->link[i].link);
	}
}
int check_leaf(blptr t,int k)
{
	if(t->leaf)
	return -1;
	else
	{int i=0;
	while(k>t->key[i]&&i<t->count)
	i++;
	return i;
	}
}
blptr tleft(int a[],u b[],bool l,blptr t)
{
	t->count=d;
	return t;
}
blptr tright(int a[],u b[],bool l)
{
	blptr tr;int i,j,z;
	tr=new blnode;
		if(l)
		{
		for(j=0,i=d;i<(2*d)+1;i++,j++)
		{tr->key[j]=a[i];
		tr->link[j].pos=b[i].pos;
		}
		tr->count=d+1;
		tr->leaf=true;
		for(j=d+1;j<2*d+2;j++)
		tr->link[j].link=NULL;
		return tr;
		}
		else
		{
		for(j=0,i=d+1;i<(2*d)+1;i++,j++)
		{tr->key[j]=a[i];
		tr->link[j].link=b[i].link;
		tr->link[j].link->pptr=tr;
		}
		tr->link[j].link=b[i].link;
		tr->link[j].link->pptr=tr;
		tr->leaf=false;
		tr->count=d;	
		return tr;
		}
}
void overflow(blptr t)
{int i;
	blptr p;
	int ar[(2*d)+1];u br[(2*d)+2];
	 for(i=0;i<t->count;i++)
	 {
	  ar[i]=t->key[i];
	  br[i]=t->link[i];
	 }
	br[i]=t->link[i];
	blptr tr,temp;
	if(t->pptr==NULL)
	{
		t=tleft(ar,br,t->leaf,t);
		cout<<"@@";
		tr=tright(ar,br,t->leaf);
		temp=new blnode;
		temp->leaf=false;
		temp->key[0]=ar[d];
		temp->link[0].link=t;
		temp->link[1].link=tr;
		if(t->leaf)
		{t->link[2*d].link=tr;
		tr->link[2*d].link=NULL;
		}
		tr->pptr=temp;
		t->pptr=temp;
		temp->count=1;
		temp->pptr=NULL;
		push(s,temp);
	}
	else
	{int i,n;
	p=t->pptr;
	n=p->count;
	t=tleft(ar,br,t->leaf,t);
	cout<<"##";
	tr=tright(ar,br,t->leaf);
	for(i=n;ar[d]<p->key[i-1]&&i>0;i--)
	{
	p->link[i+1]=p->link[i];
	p->key[i]=p->key[i-1];
	}
	p->link[i].link=t;
	p->link[i+1].link=tr;
	if(t->leaf)
	{t->link[2*d].link=tr;
	tr->link[2*d].link=br[2*d+1].link;
	}
	t->pptr=p;
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
		t->leaf=true;
		t->key[t->count]=k;
		t->link[t->count].pos=position;
		position++;
		t->count++;
		t->pptr=NULL;
		for(int i=0;i<2*d+2;i++)
		t->link[i].link=NULL;
		return t;
	}
	else
	{int x;
	x=check_leaf(dm,k);
	while(x!=-1)
	{
		dm=dm->link[x].link;
		x=check_leaf(dm,k);
	}
	dm->key[dm->count]=k;
	if(dm->count==2*d)
	dm->link[2*d+1].link=dm->link[2*d].link;
	dm->link[dm->count].pos=position;
	position++;
			for(int i=dm->count;i>0;i--)
			{
				if(dm->key[i]<dm->key[i-1])
				{
				swap(dm->key[i],dm->key[i-1]);
				swap(dm->link[i],dm->link[i-1]);
				}
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
		cout<<"\n\n";
		blptr x=t;
	while(!x->leaf)
	x=x->link[0].link;
	while(x!=NULL)
	{print(x);
	cout<<endl;
	x=x->link[2*d].link;
	}
		cout<<"\nto continue enter y";
		cin>>ch;
	}while(ch=='y');
	
	return 0;
}
//check for the input 4 1 8 2 9 3 6 5 7 10
