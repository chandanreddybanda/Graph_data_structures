#include<bits/stdc++.h>
using namespace std;
typedef struct gnode
{
	int vertex;
	int v;
}*gptr;
int find(int a[],int n)
{
	for(int i=1;i<4;i++)
	if(a[i]==n)
	return i;
}
int indegree(int a[][7],int n)
{
	int count=0;
	for(int i=1;i<7;i++)
	{
		count=count+a[i][n];
	}
	return count;
}
int outdegree(int a[][7],int n)
{
	int count=0;
	for(int i=1;i<7;i++)
	count=count+a[n][i];
	return count;
}
int main()
{
	int a[7][7];
	for(int i=1;i<7;i++)
	for(int j=1;j<7;j++)
	a[i][j]=0;
	a[1][4]=1;a[2][5]=1;a[3][4]=1;a[4][6]=1;a[5][6]=1;
	int b[4];int q=4;
	cout<<"Enter the minimum required elements -> ";
	for(int i=1;i<4;i++)
	cin>>b[i];
	int out;
	do
	{
		cout<<"Enter the number -> ";
		int x,in,temp;
		cin>>x;out=outdegree(a,x);
		for(int i=1;i<7;i++)
		{
			if(a[x][i]==1)
			{
				in=indegree(a,i);
				temp=find(b,x);
				if(in==1)
				{
					b[temp]=i;
					cout<<"Options u can choose now\n";
					for(int i=1;i<q;i++)
					{
						if(b[i]!=-1)
						cout<<b[i]<<" ";
					}
					cout<<endl;
				}
				else
				{
					b[temp]=-1;
					cout<<"Options u can choose now\n";
					for(int i=1;i<q;i++)
					{
						if(b[i]!=-1)
						cout<<b[i]<<" ";
					}
						cout<<endl;
				}
				a[x][i]=0;
			}
		}
	}while(out!=0);
}
