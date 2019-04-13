#include<iostream>
using namespace std;
typedef struct gnode
{
	int v;
}*gptr;
int indegree(int a[][7],int array[],int k,gptr g[])
{
	for(int i=1;i<7;i++)
	{
		int count=0;
		for(int j=1;j<7;j++)
		{
			if(a[j][i]==1)
			count++;
		}
		if(count==0 && g[i]->v==0)
		{
			g[i]->v=1;
			for(int l=1;l<7;l++)
			a[i][l]=0;
			array[k++]=i;
		}
	}
	return k;
}
int main()
{
	int a[7][7],k=0;
	gptr g[7];
	for(int i=1;i<7;i++)
	{
		g[i]=new(gnode);
		g[i]->v=0;
	}
	for(int i=0;i<7;i++)
	for(int j=0;j<7;j++)
	a[i][j]=0;
	a[5][2]=1;a[4][6]=1;a[2][3]=1;a[3][1]=1;a[4][1]=1;a[5][6]=1;a[2][6]=1;a[6][3]=1;
	int array[7];
	while(k!=6)	
	k=indegree(a,array,k,g);	
	for(int i=0;i<k;i++)
	cout<<array[i]<<" ";
}
