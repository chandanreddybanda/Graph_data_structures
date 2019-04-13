#include<iostream>
#include<string>
using namespace std;
const int n=26;
typedef struct trie
{
	struct trie *ptr[n];
	bool tag;
}*tptr;
tptr getnode()
{
	tptr temp=new trie;
	temp->tag=false;
	for(int i=0;i<n;i++)
	{
		temp->ptr[i]=NULL;
	}
	return temp;
}
tptr T=getnode();
void create(tptr &T,string s)
{
	tptr temp=T;
	for(int i=0;i<s.length();i++)
	{
		int index=s[i]-'a';
		if(!temp->ptr[index])
		{
			temp->ptr[index]=getnode();
		}
		temp=temp->ptr[index];
	}
	temp->tag=true;
}
bool search(tptr T,string s)
{
	tptr temp=T;
	for(int i=0;i<s.length();i++)
	{
		int index=s[i]-'a';
		if(!temp->ptr[index])
		{
			return false;
		}
		temp=temp->ptr[index];
	}
	return (temp!=NULL&&temp->tag);
}
int main()
{
	while(1)
	{
		string s;
		cout<<"Enter string:";
		cin>>s;
		if(s=="0")break;
		create(T,s);
	}
		while(1)
	{
		string s;
		cout<<"Enter string to be searched:";
		cin>>s;
		if(s=="0")break;
		if(search(T,s))
		{
			cout<<"The required string is found\n";
		}
		else
		cout<<"The required string is not found\n";
	}
	return 0;
}
