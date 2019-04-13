#include<iostream>
using namespace std;
int degree(int g[][7],int v)
{
	int count=0;
	for(int i=1;i<7;i++)
	count=count+g[i][v];
	return count;
}
void bft(int g[][7],int v)
{
	cout<<v<<"/";
	for(int i=1;i<=6;i++)
	{
		if(g[v][i]==1)
		{
			g[v][i]=0;
			g[i][v]=0;
			bft(g,i);
		}
	}
}
int main()
{
	int g[7][7];
	for(int i=0;i<7;i++)
	for(int j=0;j<7;j++)
	g[i][j]=0;
	g[3][4]=1;g[4][3]=1;g[3][2]=1;g[2][3]=1;g[1][2]=1;g[2][1]=1;g[2][4]=1;g[4][2]=1;g[1][6]=1;g[6][1]=1;g[2][6]=1;g[6][2]=1;g[6][5]=1;g[5][6]=1;g[4][5]=1;g[5][4]=1;g[4][6]=1;g[6][4]=1;
	bft(g,5);
}
