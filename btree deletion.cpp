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
}s,s_del;
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
int check_leaf(blptr t,int k)
{
	int flag=0,x=-1,i;
	for(i=0;i<(2*d)+2;i++)
	{
		if(t->link[i]!=NULL)
		{
		flag=1;break;
		}
	}
	if(!flag)
	return -1;
	else
	{
		if(k<t->key[0])
		{
		return 0;
		}
		else
		{
			for(i=1;i<t->count;i++)
			{
				if(k>t->key[i-1]&&k<t->key[i])
				{x=i;
				break;
				}
			}
		if(x>0)
		{
		return x;
		}
		else
		{
		return t->count;
		}	
		}
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
			{if(dm->key[i]<dm->key[i-1])
			swap(dm->key[i],dm->key[i-1]);
			}
			dm->count++;
			if(dm->count==(2*d)+1)
			{
			overflow(dm);
			if(!stkmt(s))
			{dm=pop(s);
			while(dm->count==2*d+1)
			{
				overflow(dm);
				dm=pop(s);
			}
			}
			if(dm->pptr==NULL)
			{
			return dm;
			}
			else
			{	while(dm->pptr!=NULL)
				{
				dm=dm->pptr;
				}
				return dm;
			}	
			}
			else
			{
			return t;
			}
	}
}
blptr merge(blptr a,blptr b,int mid)
{
	blptr m;int i,j;
	m=new blnode;
	m->count=(a->count)+(b->count)+1;
	for(i=0;i<a->count;i++)
	{m->key[i]=a->key[i];
	m->link[i]=a->link[i];
	}
	m->key[i]=mid;
	m->link[i]=a->link[i];i++;
	for(i,j=0;j<b->count;j++,i++)
	{m->key[i]=b->key[j];
	m->link[i]=b->link[j];
	}
	m->link[i]=b->link[j];
	for(i;i<2*d+2;i++)
	m->link[i]=NULL;
	return m;
}
void delte(blptr b,int k,int ind)
{
	if(k<b->key[ind])
	{	
		push(s_del,b);											//no need of stack coming back is not necesscary
		delte(b->link[ind],k,ind);								//find key has to be written instead
	}
	else if(b->key[ind]==k)
		{
		int chk;
		chk=check_leaf(b,0);
			if(chk!=-1)
			{int l_c,r_c=0,flag=0,s_key;
			  if(b->link[ind+1]!=NULL)
			  r_c=b->link[ind+1]->count;
			  if(b->link[ind]!=NULL)
			  l_c=b->link[ind]->count;
			  		if(!flag&&r_c>d)
			  		{flag=1;s_key=b->link[ind+1]->key[r_c];
			  		b->key[ind]=s_key;							//some function has to be written to get s_key values
					delte(b->link[ind+1],s_key,0);              //some changes can be made havent pushed here  	
					}
					if(!flag&&l_c>d)
					{flag=1;s_key=b->key[0];                        //deltion from non leaf node and key redistribution process
					b->key[ind]=s_key;
					delte(b->link[ind],s_key,0);
					}
					if(!flag)
					{blptr m;int i;                                
					m=merge(b->link[ind],b->link[ind+1],k);                   //deletion from non leaf node and merging of two nodes
					for(i=ind;i<b->count-1;i++)
					b->key[i]=b->key[i+1];
					for(i=ind+1;i<b->count;i++)
					b->link[i]=b->link[i+1];
					b->link[i]=	NULL;i++;
					for(i;i<2*d+2;i++)
					b->link[i]=NULL;
					b->link[ind]=m;b->count--;
					m->pptr=b;
					delte(b->link[ind],k,0);					//when no elements become zero rrot has to be changed
				    }  
			}
			else
			{
			int p_c,l_c,r_c,i;
				p_c=b->count;
				if(p_c>d)
				{
					for(i=ind;i<p_c;i++)
					b->key[i]=b->key[i+1];              //easiest case of deletion in leaf
					b->count--;
				}
				else
				{
					blptr parent,lc,rc;int flag=0,chk,count;
					if(!stkmt(s_del))
					parent=pop(s_del);
					chk=check_leaf(parent,k);
					p_c=parent->count;
					count=b->count;
					if(chk>0)
					lc=parent->link[chk-1];				//has to be removed its of no use 
					if(chk<p_c)
					rc=parent->link[chk+1];
					if(rc!=NULL&&!flag)
					{
						r_c=rc->count;
						if(r_c>d)
						{flag=1;
					     parent->link[chk]->key[count]=parent->key[chk];	
						
						}
					}
				}
			}										
			  	
		}
	else
	{ind++;
	if(ind<b->count)
	delte(b,k,ind);
	else if(ind==b->count)										//it is not as same as m-way so chaenge ur way of thinking implement using findkey function
	{push(s_del,b);
	delte(b->link[ind],k,0);}
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
	cout<<"enter number to be deleted \n";
	cin>>k;
	delte(t,k,0);
	cout<<"elements of tree after deletion are\n";
	levelorder(t,d);
	return 0;
}
