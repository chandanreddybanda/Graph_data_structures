#include<bits/stdc++.h>
using namespace std;
char cha[3]={'a','b','c'};int f;
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
	int i;
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
		//gptr temp1=G->ptr[ind(c[i])];
		if(G->ptr[ind(c[i])]->tag==1)
		{
			G=G->ptr[ind(c[i])];
			i++;
		}
		else if(G->ptr[ind(c[i])]->tag==0)
		{
			string k=G->ptr[ind(c[i])]->s;
			int j=comp(k,c);
			G->ptr[ind(c[i])]->tag=1;
			G->ptr[ind(c[i])]->s="";
			int l=j-i;
			int f=0;
			while(l>1)
			{cout<<".";
				G->ptr[ind(c[i])]->ptr[ind(c[++i])]=get();
				G=G->ptr[ind(c[i])];//G->ptr[ind(c[i])]=G->ptr[ind(c[i])]->ptr[ind(c[i])];
				l--;
				if(l==2)
				{
					f=1;
					G->ptr[ind(c[i])]->ptr[0]=get();
					G->ptr[ind(c[i])]->ptr[0]->tag=0;
					G->ptr[ind(c[i])]->ptr[0]->s=k;
				}
			}
			if(f==0)
			{
				G->ptr[0]=get();
				G->ptr[0]->tag=0;
				G->ptr[0]->s=k;
			}
			G->ptr[ind(c[i])]->tag=0;
			G->ptr[ind(c[i])]->s=c;
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

void search(gptr &T,string a)
{
	static int i=0;
	if(T!=NULL&&i<a.length())
	{
		for(int j=0;j<3;j++)
		{
			search(T->ptr[ind(a[i++])],a);
			if(T->tag==0)
			{cout<<T->s<<endl;f=1;}
			string temp=T->ptr[0]->s;
			/*if(T->ptr[0]!=NULL&&strcmp(a,temp)==0)
			{cout<<T->ptr[0]->s;f=1;}*/
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

	//cout<<T->ptr[2]->s;
	/*cout<<T->ptr[1]->ptr[1]->ptr[0]->s<<" ";
	cout<<T->ptr[1]->ptr[1]->ptr[2]->s;	*/
	while(1)
	{
		string q;cin>>q;
		if(q=="0")break;f=0;
		search(T,q);
		if(f==0)cout<<"not found ";
	}
}
