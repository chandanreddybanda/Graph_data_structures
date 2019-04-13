#include<bits/stdc++.h>
using namespace std;
void search(int a[][7],int v,int *p)
{
	for(int i=1;i<7;i++)
	{
		for(int j=1;j<7;j++)
		{
			if(a[i][j]==v)
			{
				p[0]=i;
				p[1]=j;
			}
		}
	}
}int s[20];
int find(int i)
{
	if(s[i]==0)
	return i;
	else
	return s[i];
}
void unio(int i,int j)
{
	if(s[i]==0)
	s[i]=j;
	else if(s[j]==0)
	s[j]=i;
	else
	s[find(i)]=j;
}
int sameset(int x,int y)
{
	if(find(x)==find(y))
	return 1;
	else
	return 0;
}
int main()
{
	int a[7][7];int c[9];int b[7][7];
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<7;j++)
		{
			a[i][j]=0;
			b[i][j]=0;
		}
	}
	for(int i=0;i<9;i++)
	{
		int x,y,l;
		cin>>x>>y>>l;
		a[x][y]=l;
		a[y][x]=l;
		cout<<"done\n";
		unio(x,y);
		cout<<"2\n";
		c[i]=l;
	}
	sort(c,c+9);
	for(int i=0;i<9;i++)
	{
		int p[2];
		search(a,c[i],p);
		if(sameset(p[0],p[1])==0)
		{
			b[p[0]][p[1]]=c[i];
		}
	}
	for(int i=1;i<7;i++)
	{
		for(int j=1;j<7;j++)
		cout<<b[i][j]<<" ";
		cout<<endl;
	}
	
}
