#include<iostream>
using namespace std;
int g[6][6],vi[6];
void dft(int s,int d,string st)
{
	vi[s]=1;
	for(int i=1;i<6;i++)
	{
		if(g[s][i]==1 && vi[i]!=1)
		{
			st=st+char(s);
				if(s==d)
				{
					for(int j=0;j<st.length();j++)
					cout<<"->"<<int(st[j]);
				}
			dft(i,d,st);
		}
	}
}
int main()
{
	int s,d;
		for(int i=0;i<6;i++)
     	{
			int x,y;
			cin>>x>>y;
			g[x][y]=1;
		}
		string st="";
		cin>>s>>d;
		dft(s,d,st);
	
}
