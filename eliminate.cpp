#include<iostream>
using namespace std;
int G[20][20];
int n;
void dft(int,int,int,int a[]);
int check(int);
void slice(int,int,int);
int o[140][20];
int nm=1;
int end();
void change();
int R[20][20];
int check1(int);
int main()
{
	int i,j;
	cout<<"enter the no.of vertices\n";
	cin>>n;
	cout<<"enter the adjacency matrix\n";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>G[i][j];
		}
	}
	cout<<"enter the source vertex\n";
	int s;
	cin>>s;int e[40];
	e[1]=s;
	dft(s,1,1,e);
	int out=1;int p,ch=1;
	for(i=1;i<nm;i++)
	{
		for(j=1;j<=o[i][0];j++)
		{
			cout<<o[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<nm;
	return 0;
}

void dft(int k,int index,int sr,int r[40])
{int i,flag=0;
	for(i=1;i<=n;i++)
	{
		if(G[k][i]==1)
		{
			if(index!=sr)
			{flag=1;
				for(int j=sr+1;j>index+1;j--)
				{
					r[j]=r[j-1];
				}
			}
			sr++;
			r[index+1]=i;G[k][i]=0;G[i][k]=0;
	if(check(i)!=0)
	{if(flag==1)
	{
		dft(i,index+1,sr,r);
		for(int j=index+1;j<sr;j++)
				{
					r[j]=r[j+1];
				}
	}
	else{
	dft(i,sr,sr,r);}
	sr--;
	G[k][i]=1;G[i][k]=1;
	}
	else{
	o[nm][0]=sr;
	for(int m=1;m<=sr;m++)
	{
		o[nm][m]=r[m];
	}
	change();
	nm++;
	sr--;
	G[k][i]=1;G[i][k]=1;
	
	}}}
}

int check(int k)
{
	for(int i=1;i<=n;i++)
	{
		if(G[k][i]==1)
		return 1;
	}
	return 0;
}

int end()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(G[i][j]==1)
			{
				return 1;
			}
		}
	}
	return 0;
}

void slice(int k,int index,int sr)
{int i,flag;
	cout<<"k";
	for(i=1;i<=n;i++)
	{
		if(R[k][i]==1)
		{
			if(index!=sr)
			{flag=1;
				for(int j=sr+1;j>index+1;j--)
				{
					o[sr][j]=o[sr][j-1];
				}
			}
			sr++;o[sr][0]++;
			o[sr][index+1]=i;R[k][i]=0;R[i][k]=0;break;
		}
	}
	if(check1(i)!=0)
	{if(flag==1)
	{
		slice(i,index+1,sr);
	}
	else{
	slice(i,sr,sr);}
	}	
		
}

void change()
{int ch=1,p,i;cout<<"y";
for(i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			R[i][j]=G[i][j];
		}
	}
	while(ch==1)
	{ch=0;
	for(i=1;i<=o[nm][0];i++)
	{
		if(check1(o[nm][i])==1)
		{
			p=o[nm][i];ch=1;break;
		}
	}
	if(ch==1)
	{
	slice(p,i,nm);}
	}
}

int check1(int k)
{
	for(int i=1;i<=n;i++)
	{
		if(R[k][i]==1)
		return 1;
	}
	return 0;
}
