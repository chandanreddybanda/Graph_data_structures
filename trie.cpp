#include<bits/stdc++.h>
using namespace std;
char cha[3]={'a','b','c'};
typedef struct gnode
{
	int tag;
	gnode *ptr[4];
	string s;
}*gptr;
gptr get()
{
	gptr temp=new gnode;
	temp->tag=1;
	for(int i=0;i<4;i++)
	temp->ptr[i]=NULL;
	temp->s="";
	return temp;
}
int ind(char c)
{
	for(int i=0;i<3;i++)
	if(c==cha[i])
	return i+1;
}
int strcmp(string a,string b)
{
	int f=0;
	if(a.length()!=b.length())
	return 0;
	else
	for(int i=0;i<a.length();i++)
	{
		if(a[i]!=b[i])
		{
			f=1;break;
		}
	}
	if(f==1)return 0;
	else return 1;
}
void create(gptr T,string c)
{
	if(T->ptr[ind(c[0])]==NULL)
	{
		string str="";
		for(int i=0;i<c.length();i++)
		{
			T->ptr[ind(c[i])]=get();
			str=str+c[i];
			T->ptr[ind(c[i])]->s=str;
			T=T->ptr[ind(c[i])];
		}//cout<<"/"<<T->s<<"/";
		T->tag=0;
	}
	else
	{
		int x;
		for(int i=0;i<c.length();i++)
		{
			if(T->ptr[ind(c[i])]!=NULL)
			T=T->ptr[ind(c[i])];
			else
			{
				x=i;break;
			}
		}
		string str=T->s;
		for(int i=x;i<c.length();i++)
		{
			T->ptr[ind(c[i])]=get();
			str=str+c[i];
			T->ptr[ind(c[i])]->s=str;
			T=T->ptr[ind(c[i])];
		}//cout<<"/"<<T->s<<"/";
		T->tag=0;
	}
}
void print(gptr T)
{
	if(T!=NULL)
	{
		for(int i=0;i<3;i++)
		{
			print(T->ptr[i+1]);
		}
		if(T->tag==0)
		cout<<T->s<<" ";
	}
}
void search(gptr T,string r)
{
	if(T!=NULL)
	{
		for(int i=0;i<3;i++)
		{
			search(T->ptr[i+1],r);
		}
		if(T->tag==0&&strcmp(r,T->s)==1)
		cout<<T->s<<" ";
	}	
}
void del(gptr T,string r)
{
	if(T!=NULL)
	{
		for(int i=0;i<3;i++)
		{
			del(T->ptr[i+1],r);
		}
		if(strcmp(r,T->s)==1)
		T->tag=1;
	}
}
int main()
{
	gptr T=get();
	while(1)
	{
		string r;cin>>r;
		if(r=="0")break;
		create(T,r);
	}
	print(T);
	while(1)
	{
		string r;cin>>r;
		if(r=="0")break;
		search(T,r);
	}
	while(1)
	{
		string r;cin>>r;
		if(r=="0")break;
		del(T,r);
	}print(T);
	
	return 0;
}
