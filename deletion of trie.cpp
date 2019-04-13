#include<iostream>
#include<cstring>
using namespace std;
typedef
struct trienode{
	int flag;
	union u{
		struct trienode* trptr[5];
		char *data;
	}info;
}*trie_ptr;
struct queue{
            int f;
			int r;
			trie_ptr ele[20];
			int size;  
			  queue()
			  {f=-1;r=-1;size=20;}
			};
int qmt(queue &Q)
{if(Q.f==-1)
return 1;
else 
return 0;
}
int qful(queue &Q)
{if(Q.f==((Q.r)+1)%Q.size)
return 1;
else 
return 0;
}
void entq(queue &Q,trie_ptr x) 
 {if(qful(Q))
 cout<<"q is full\n";
 else{
       if(qmt(Q)==1)
	   {Q.f=0;Q.r=0;}
	   else
	   {
	   	Q.r=((Q.r)+1)%Q.size;
	   }
	   Q.ele[Q.r]=x;
	}
 }
 trie_ptr deq(queue &Q)
 {trie_ptr x;
 if(qmt(Q))
     {cout<<"q is mty";return NULL;
	 }
 else {x=Q.ele[Q.f];
      if(Q.f==Q.r)
	  {Q.f=-1;Q.r=-1;
	   }
	   else{
	        Q.f=(Q.f+1)%Q.size;			
		}return x;
	  }
 }
 void print(trie_ptr t)
 {queue q;trie_ptr dm;dm=new trienode;dm->flag=-1;
 entq(q,t);entq(q,dm);
 	while(!qmt(q))
 	{t=deq(q);
 	if(t->flag!=-1)
 	{
 		if(t->flag==1)
 		{cout<<"***\t";
 		for(int i=1;i<5;i++)
 		if(t->info.trptr[i]!=NULL)
 		entq(q,t->info.trptr[i]);
		}
		else
		cout<<t->info.data<<"  ";	 
	}
 	else{
 	cout<<endl;
	if(!qmt(q))
	entq(q,dm);} 	
	}
 }
int pos(char ch)
{
	if(ch=='a')return 1;
	if(ch=='b')return 2;
	if(ch=='c')return 3;
	if(ch=='*')return 4;
}
int common(char *a,char *b)
{
	for(int i=0;(i<strlen(a)&&i<strlen(b));i++)
		if(a[i]!=b[i])
		return i;
}
void create(trie_ptr t,char *s,int i)
{
	if(t->info.trptr[pos(s[i])]==NULL)
	{
		trie_ptr temp;
		temp=new trienode;
		temp->flag=0;temp->info.data=s;
		t->info.trptr[pos(s[i])]=temp;
	}
	else
	{
		if(t->info.trptr[pos(s[i])]->flag==1)
		create(t->info.trptr[pos(s[i])],s,i+1);	
		else if(t->info.trptr[pos(s[i])]->flag==0)
		{
		char *str;
		str=new char;
		trie_ptr temp;
		str=t->info.trptr[pos(s[i])]->info.data;
		int j,k;j=common(str,s);
			k=j-i;
			while(k>0)
			{k--;
			temp=new trienode;
			temp->flag=1;
			for(int l=1;l<5;l++)
			temp->info.trptr[l]=NULL;
			t->info.trptr[pos(s[i])]=temp;i++;
			t=temp;
			}		
			trie_ptr t1,t2;
			t1=new trienode;t2=new trienode;
			t1->flag=0;t2->flag=0;
			t1->info.data=s;
			t->info.trptr[pos(s[i])]=t1;
			t2->info.data=str;
			t->info.trptr[pos(str[i])]=t2;
		}
	}
}
int count(trie_ptr t)
{int i,c=0;
	for(i=1;i<5;i++)
	if(t->info.trptr[i]!=NULL)
	c++;
return c;	
}
trie_ptr get_tr(trie_ptr t)
{
	for(int i=1;i<5;i++)
	if(t->info.trptr[i]!=NULL)
	return t->info.trptr[i];
}
struct stack
       {int size;
       int top;
       trie_ptr elements[20];
       stack()
       {size=20;top=-1;}
	   };
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
void push(stack &s,trie_ptr x)
{if(stkful(s))
cout<<"stack is full";
else
{s.top++;
s.elements[s.top]=x;
}
}
trie_ptr pop(stack &s)
{
if(stkmt(s))
{cout<<s.top<<"\nstack is empty";
return NULL;}
else
return s.elements[s.top--];
}
void delte(trie_ptr t,char *s)
{
	int i=0;stack stk;
	while(t!=NULL)
	{
		if(t->info.trptr[pos(s[i])]==NULL)
		{cout<<"not found";break;}
		else
		{
			if(t->info.trptr[pos(s[i])]->flag==1)
			{push(stk,t);
			t=t->info.trptr[pos(s[i])];i++;
			}
			else
			{trie_ptr temp;temp=t->info.trptr[pos(s[i])];
				if(strcmp(temp->info.data,s)==0)
				{t->info.trptr[pos(s[i])]=NULL;
				push(stk,t);
				cout<<"deleted!!!";
				break;
				}
				else{
				cout<<"not found";break;}
			}
		}
	}
	if(count(stk.elements[stk.top])==1)
	{trie_ptr temp;temp=new trienode;
	temp=get_tr(stk.elements[stk.top]);
		while(!stkmt(stk))
		{t=pop(stk);
			if(count(t)>1)
			break;
		}
		t->info.trptr[pos(s[stk.top+1])]=temp;
	}
}
int main()
{
	trie_ptr t;t=new trienode;
	t->flag=1;
	for(int i=1;i<5;i++)
	t->info.trptr[i]=NULL;
	char *p,ch;
	do{
		cout<<"\nenter the word :";
		p=new char;
		cin>>p;
		strcat(p,"*");
		create(t,p,0);
		cout<<"to continue y";
		cin>>ch;	
	}while(ch=='y');
cout<<endl;
print(t);
p=new char;
cout<<"enter the word to be deleted;";
cin>>p;
strcat(p,"*");
delte(t,p);
cout<<endl;
print(t);
}
