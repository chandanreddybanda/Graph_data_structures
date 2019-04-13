#include<iostream>
using namespace std;
int indegree(int g[][5],int n)
{
	int count=0;
	for(int i=0;i<5;i++)
	{
		count=count+g[i][n-1];
	}
	cout<<"\nIndegree -> "<<count;
}
int outdegree(int g[][5],int n)
{
	int count=0;
	for(int i=0;i<5;i++)
	{
		count=count+g[n-1][i];
	}
	cout<<"\nOutdegree -> "<<count;
}
int cycles(int g[][5],int n,int x,int a[],int j)
{
	int i=0;
	while(i!=5)
	{
		if(g[x][i]==1)
		{
			if(i==n-1)
			{
				cout<<n<<" ";
				for(int k=0;k<j;k++)
				cout<<a[k]<<" ";
				break;
			}
			else
			{
				a[j++]=i+1;
				cycles(g,n,i,a,j);
			}
		}
		i++;
	}
}
int main()
{
	int v=5;
	int g[7][7];
	for(int i=0;i<7;i++)
	for(int j=0;j<7;j++)
	g[i][j]=0;g[0][1]=1;g[1][2]=1;g[2][0]=1;g[2][3]=1;g[0][3]=1;g[1][4]=1;g[4][3]=1;
	int n;
	cout<<"Enter the vertex number -> ";
	cin>>n;
	indegree(g,n);
	outdegree(g,n);
	cout<<endl;
	for(int y=1;y<6;y++)
	{	
		int a[5];
		cycles(g,y,y-1,a,0);
		cout<<endl;
	}
}
