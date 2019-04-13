#include<iostream>
using namespace std;
int a[20];int l=1;
void create(int n)
{
	int i=l;
	a[l++]=n;
	while(a[i]<a[i/2])
	{
		swap(a[i],a[i/2]);
		i=i/2;
	}
}
int min()
{
	int k=a[1];
	a[1]=a[--  l];
	int i=1;
	while((a[i]>a[2*i]||a[i]>a[2*i+1])&&(i<=l&&2*i<=l&&2*i+1<=l))
	{
		if(a[i]>a[2*i]&&a[i]>a[2*i+1])
		{
			if(a[2*i]<a[2*i+1])
			{
				swap(a[i],a[2*i]);
				i=2*i;
			}
			else
			{
				swap(a[i],a[2*i+1]);
				i=2*i+1;
			}
		}
		else if(a[i]>a[2*i])
		{
			swap(a[i],a[2*i]);
			i=2*i;
		}
		else
		{
			swap(a[i],a[2*i+1]);
			i=2*i+1;
		}
	}
	return k;
}
int main()
{
	while(1)
	{
		int n;
		cin>>n;
		if(n!=-1)
		create(n);
		else
		break;
	}
	while(l!=1)
	{
		cout<<min()<<" ";
	}
}
/*
2
14
5
32
41
18
90
50
64
53
43
87
23
-1
*/
