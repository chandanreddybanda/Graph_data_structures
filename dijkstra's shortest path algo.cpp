#include<iostream>
using namespace std;
int a[10][10];
int n;
struct vertex
{
	int flag;
	int d;
	int p;
	vertex()
	{
		flag=0;
		d=1000;
		p=-1;
	}
}v[10];
int find()
{
	int temp=1000,t;//cout<<i;
	for(int j=0;j<n;j++)
	{
		if(v[j].flag==0&&temp>v[j].d)
		{
			temp=v[j].d;
			t=j;
		}
	}
	return t;
}
int main()
{
	cout<<"Enter no of vertices:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"Whether "<<i+1<<" and "<<j+1<<" had a link:1/0:";
			cin>>a[i][j];
		}
	}
	int s,e;
	cout<<"Enter starting and ending elements:";
	cin>>s>>e;
	cout<<endl;
	int l=s;
	while(s!=e)
	{
		if(v[s-1].flag==0)
		{
			v[s-1].flag=1;
			for(int i=0;i<n;i++)
			{
				if(a[s-1][i]>0&&v[i].flag==0)
				{
					int len;
					if(v[s-1].d==1000)
					len=a[s-1][i];
					else
					len=a[s-1][i]+v[s-1].d;
					if(v[i].d==1000||v[i].d>len)
					{
						v[i].d=len;
						v[i].p=s;
					}
        		}
			}
			int f=find();
			s=f+1;
		}
	}
	s=l;
	int r[n];
	int c=0;
	while(e!=s)
	{
		r[c++]=e;
		e=v[e-1].p;
	}
	r[c++]=s;
	for(int i=c-1;i>=0;i--)
	{
		if(i>0)
		cout<<r[i]<<"->";
		else
		cout<<r[i];
	}
	return 0;
}


