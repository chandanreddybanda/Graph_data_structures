#include<bits/stdc++.h>
using namespace std;
char cha[4]={'a','b','c','d'};
typedef struct gnode
{
	bool tag;
	gnode *ptr[5];
	string s;
}*gptr;
gptr get()
{
	gptr temp=new gnode;
	temp->tag=1;
	for(int i=0;i<5;i++)
	temp->ptr[i]=NULL;
	temp->s="";
	return temp;
}
int ind(char c)
{
	for(int i=0;i<4;i++)
	if(c==cha[i])
	return i+1;
}
void create(gptr T,string c)
{
	int len=c.length();
	if(T->ptr[ind(c[0])]==NULL)
	{
		string st="";
		for(int i=0;i<len;i++)
		{
			T->ptr[ind(c[i])]=get();
			st=st+c[i];
			T->ptr[ind(c[i])]->s=st;
			if(i!=len-1)
			T=T->ptr[ind(c[i])];
		}
		T->tag=0;
	}
	else
	{
		int i=0;
		while(T->ptr[ind(c[i])]!=NULL)
		T=T->ptr[ind(c[i++])];
		string st=T->s;
		for(int j=i;j<len;j++)
		{
			T->ptr[ind(c[i])]=get();
			st=st+c[i];
			T->ptr[ind(c[i])]->s=st;
			if(i!=len-1)
			T=T->ptr[ind(c[i])];
		}
		T->tag=0;
	}
}
void print(gptr T)
{
	if(T!=NULL)
	{
		for(int i=1;i<5;i++)
		print(T->ptr[i]);
		cout<<T->s<<endl;
	}
}
int main()
{
	gptr T=get();
	while(1)
	{
		string r;
		cin>>r;
		if(r=="0")
		break;
		create(T,r);
	}	print(T);
}
/*abb
abc
abbb
acd
abb
ac
ab*/
