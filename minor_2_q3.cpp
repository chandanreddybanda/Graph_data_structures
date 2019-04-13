#include<iostream>
using namespace std;
int G[20][20];
int R[20][20];
int visit[12]={0,0,0,0,0,0,0,0,0,0,0,0};
int n;
int num[12],count=0;
struct stack{
	int size=-1;
	int elem[50];
}t;
void dft();
void rdft();
void rem();
void rrem();
void reverse();
void push(int);
int pop();
int isempty();
int o[10];int s;
int p=0,cmp[10][10];
int main()
{
	int i,j;
	cout<<"enter the no.of vertices\n";
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			G[i][j]=0;
		}
	}
	for(int i=0;i<15;i++)
	{
		int x,y;
		cin>>x>>y;
		G[x][y]=1;
	}
	cin>>s;
	visit[s]=1;
	dft();
		for(i=1;i<=n;i++)
		{
			if(visit[i]==0)
			{
				s=i;visit[i]=1;
				dft();
			}
		}
		reverse();
		for(i=1;i<=n;i++)
		{visit[i]=0;
		}
		int r=0;int P[20][20];
		for(i=1;i<=n;i++)
		{
		for(j=1;j<=n;j++)
			{
			P[i][j]=0;
			}
		}
		for(int z=count;z>0;z--)
		{
		if(visit[num[z]]==0)
			{r++;p++;cout<<endl;s=num[z];cout<<s<<" ";
			cmp[p][0]=0;cmp[p][++cmp[p][0]]=s;push(s);visit[s]=1;rdft();
				for(i=1;i<p;i++)
				{for(j=1;j<=cmp[i][0];j++)
				{for(int k=1;k<=cmp[p][0];k++)
			{
			if(G[cmp[i][j]][cmp[p][k]]==1)
			{
				P[i][p]=1;
			}
			if(G[cmp[p][k]][cmp[i][j]]==1)
			{
				P[p][i]=1;
			}}
			}}
		}}
		cout<<r;
		cout<<endl;
		for(i=1;i<=p;i++)
		{
			for(j=1;j<=cmp[i][0];j++)
			{
				cout<<cmp[i][j]<<" ";
			}
			cout<<endl;
		}
		for(i=1;i<=p;i++)
		{cout<<endl;
			for(j=1;j<=p;j++)
			{
				cout<<P[i][j]<<" ";
			}
		}
	return 0;
}

void dft()
{int flag=0;
	for(int i=1;i<=n;i++)
	{
		if(G[s][i]>0&&visit[i]==0)
		{
			flag=1;
			//cout<<i<<" ";
			visit[i]=1;push(s);s=i;
			break;
		}
	}
	if(flag==1)
	{
		dft();
	}
	else{num[++count]=s;
		rem();
	}
}

void rem()
{
	if(isempty()!=0)
		{int k=pop();
		s=k;
		dft();
		}
}

void reverse()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			R[i][j]=G[j][i];
		}
	}
}

void rdft()
{int flag=0;
	for(int i=1;i<=n;i++)
	{
		if(R[s][i]>0&&visit[i]==0)
		{
			flag=1;
			cout<<i<<" ";cmp[p][++cmp[p][0]]=i;visit[i]=1;push(i);s=i;
			break;
		}
	}
	if(flag==1)
	{
		rdft();
	}
	else{
		rrem();
	}
}

void rrem()
{
	if(isempty()!=0)
		{int k=pop();
		s=k;
		rdft();
		}
}

void push(int k)
{
	t.elem[++t.size]=k;
}

int pop()
{
	return t.elem[t.size--];
}

int isempty()
{
	if(t.size==-1)
	{
		return 0;
	}
	else{
		return 1;
	}
}


