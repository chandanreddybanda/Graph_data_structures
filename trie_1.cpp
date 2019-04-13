#include<iostream>
using namespace std;
char cha[3]={'a','b','c'};
typedef struct gnode
{
	bool tag;
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
int comp(string k,string c)
{
	int i=0;
	for(i=0;i<min(k.length(),c.length());i++)
	if(k[i]!=c[i])
	break;
	return i;
}
void create(gptr &T,string c)
{
	gptr G=T;
	int i=0;
	while(G->ptr[ind(c[i])]!=NULL)
	{
		G=G->ptr[ind(c[i])];
		if(G->tag==1)
		{
		//	G=G->ptr[ind(c[i])];
			i++;
		}
		else if(G->tag==0)
		{
			string k=G->s;
			int j=comp(k,c);
			G->tag=1;
			G->s="";
			int l=j-i;
			while(l>1)
			{
				G->ptr[ind(c[++i])]=get();
				G=G->ptr[ind(c[i])];
				l--;
				if(l==2)
				{
					G->ptr[0]=get();
					G->ptr[0]->tag=0;
					G->ptr[0]->s=k;
				}
			}
			G->tag=0;
			G->s=c;
			break;
		}
	}
	if(G->ptr[ind(c[i])]==NULL)
	{
		G->ptr[ind(c[i])]=get();
		G->ptr[ind(c[i])]->tag=0;
		G->ptr[ind(c[i])]->s=c;
	}
}
void print(gptr T)
{
	if(T!=NULL)
	{
		for(int i=0;i<4;i++)
		{
			print(T->ptr[i]);
			if(T->tag==0)
			{
				cout<<T->s<<" ";
			}
		}
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
		else
		create(T,r);
	}
	print(T);
//cout<<T->ptr[3]->s;
}
