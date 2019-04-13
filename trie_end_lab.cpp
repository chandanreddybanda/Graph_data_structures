#include<iostream>
using namespace std;
typedef struct tnode
{
	tnode *p[26];
	bool tag;
}*tptr;
tptr get()
{
	tptr t;
	t=new tnode;
	t->tag=false;
	for(int i=0;i<26;i++)
	t->p[i]=NULL;
	return t;
}
void create(tptr root,string key)
{
	tptr t=root;
	for(int i=0;i<key.length();i++)
	{
		int ind=int(key[i])-'a';
		if(t->p[ind]==NULL)
		{
			t->p[ind]=get();
		}
		//if(i!=key.length()-1)
		t=t->p[ind];
	}
	t->tag=true;
}
char c[20];int l=0;
void print(tptr root)
{
	if(root!=NULL)
	{
		for(int i=0;i<26;i++)
		{
			if(root->p[i]!=NULL)
			{
				c[l++]=char(i+'a');
				if(root->p[i]->tag==true)
				{
					for(int j=0;j<l;j++)
					cout<<c[j]<<" ";
					cout<<endl;
				}
				print(root->p[i]);
			}
		}
		l--;
	}
}
int input(tptr root)
{
	if(root->tag==true)
	return true;
	else
	return false;
}
int isitfreenode(tptr root)
{
	for(int i=0;i<26;i++)
	{
		if(root->p[i])
		return 0;
	}
	return 1;
}
bool delh(tptr root,string key,int level,int len)
{
	if(root)
	{
		if(level==len)
		{
			if(root->tag)
			{
				root->tag=false;
				if(isitfreenode(root))
				return true;
				return false;
			}
		}
		else
		{
			int ind=key[level]-'a';
			if(delh(root->p[ind],key,level+1,len))
			{
				root->p[ind]=NULL;
			//	return (!leafnode(root)&&isitfreenode(root));
			}
		}
	}
	return false;
}
void dl(tptr root,string s)
{
	int len=s.length();
	if(len>0)
	delh(root,s,0,len);
}
int main()
{
	tptr root=get();
	for(int i=0;i<5;i++)
	{
		string s;
		cin>>s;
		create(root,s);
	}
	print(root);
	string s;
	cin>>s;
	dl(root,s);
	l=0;
	print(root);
}
/*abbc
bac
cabb
bacb
bbca*/
/*a
ab
abc
ac
bac*/
