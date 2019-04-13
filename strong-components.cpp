#include<iostream>
using namespace std;
int n;
int **G;
int *v;
int t[10],x=1,g[10][10],vi[10];
void dft(int s)
{
	v[s-1]=1;
	for(int i=0;i<n;i++)
	{
		if(v[i]==0&&G[s-1][i]==1)
		dft(i+1);
	}
	t[s]=x++;
}
void sdft(int s)
{
	cout<<s<<" ";
	t[s]=0;
	vi[s-1]=1;
	for(int i=0;i<n;i++)
	{
		if(vi[i]==0&&g[s-1][i]==1)
		sdft(i+1);
	}
}
bool check()
{
	for(int i=1;i<=10;i++)
	{
		if(t[i]==0)
		return true;
	}
	return false;
}
int main()
{
	int s,m,d;
	cout<<"Enter no of vertices:";
	cin>>n;
	v=new int[n];
	G=new int*[n];
	for(int i=0;i<n;i++)
	{
		G[i]=new int[n];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{

			G[i][j]=0;
		}
		v[i]=0;
	}
	for(int i=0;i<15;i++)
	{
		cin>>m>>d;
		G[m-1][d-1]=1;
		g[d-1][m-1]=1;
	}
	cout<<"Enter starting point:";
	cin>>s;
	dft(s);
	while(check())
	{
	    dft(x);
}
	
	cout<<endl;
	int h=n,x;
	
   for(int m=10;m>0;m--)
   {
   	  	for(int i=1;i<=10;i++)
   	  	{
   	  	
   	  		if(t[i]==m)
   	  		{
   	  			sdft(i);
   	  			cout<<endl;
		    }
		}
	
   }
	
	return 0;
}
/*
5
0
1
1
1
0
1
0
1
0
1
1
1
0
1
0
1
0
1
0
1
0
1
0
1
0
*/
