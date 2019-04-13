#include<bits/stdc++.h>
using namespace std;
int s[1000];
int main()
{
	int n,h;
	cin>>n>>h;
	int a[n];
	for(int j=0;j<n;j++)
	cin>>a[j];
	int i=0;
	while(1)
	{
		cin>>s[i++];
		if(s[i]==0)
		break;
	}
	int p=0;
	for(int k=0;k<i;k++)
	{
		int ch=s[k];
		switch(ch)
		{
			case 1:if(p!=0)p=p-1;break;
			case 2:if(p!=n-1)p=p+1;break;
			case 3:if(a[p]!=0)a[p]=a[p]-1;break;
			case 4:if(a[p]<h)a[p]=a[p]+1;break;
			case 0:break;
			default :break;
		}
	}
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
}
