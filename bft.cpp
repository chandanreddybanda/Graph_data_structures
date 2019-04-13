#include<iostream>
using namespace std;
typedef struct gnode
{
	int data;
	int v;
}*gptr;
void dft(gptr g[],int a[][6],int c)
{
	static int m=0;
	for(int i=1;i<5;i++)
	{
		if(a[c][i]!=0)
		{
			if(g[i]->v==0)
			{
				g[i]->v=1;
				cout<<g[i]->data<<" ";
				m=m+1;
				dft(g,a,i);
			}	
		}
	}
}
int main()
{
	gptr g[6];
	int a[6][6];
	for(int i=5;i>0;i--)
	{
		g[i]=new gnode;
		g[i]->data=i;
		g[i]->v=0;
	}
	int zz;
	cin>>zz;
	for(int i=0;i<zz;i++)
	{
		int aa,bb;char cc;
		cin>>aa>>bb>>cc;
		a[aa][bb]=int(cc);
	}
	int c;
	cout<<"Enter current position -> ";
	cin>>c;
	g[c]->v=1;
	cout<<c<<" ";
	dft(g,a,c);
}
