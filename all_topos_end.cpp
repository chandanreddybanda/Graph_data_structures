#include<iostream>
using namespace std;
int g[100][100];
int N;
int indegree(int n)
{
	int count=0;
	for(int i=1;i<N;i++)
	{
		if(g[i][n]==1)
		count++;
	}
	return count;
}
int v[100],b[100],m=0;
void all()
{
	for(int i=1;i<N;i++)
	{
		if(indegree(i)==0&&v[i]==0)
		{
			v[i]=1;
			b[m++]=i;
			int te[N],k=0;
			for(int j=1;j<N;j++)
			{
				if(g[i][j]==1)
				te[k++]=j;
				g[i][j]=0;
			}
			if(m==N-1)
			{
				for(int j=0;j<m;j++)
				cout<<b[j]<<" ";
				cout<<endl;
			}
			all();
			for(int j=0;j<k;j++)
			g[i][te[j]]=1;
			v[i]=0;
			m--;
		}
	//	cout<<endl;
	}
}
int main()
{
	N=8;
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a][b]=1;
		g[b][a]=1;
	}
	all();
}
/*
1 3
3 5
2 4
4 5
*/
