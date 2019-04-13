#include<bits/stdc++.h>
using namespace std;
int part(int a[],int low,int high)
{
	if(low<high)
	{
	int p=a[low];
	int l=low+1,h=high;
	while(l<=h)
	{
		while(a[l]<p)
		l++;
		while(a[h]>p)
		h--;
		if(l<=h)
		swap(a[l],a[h]);
	}
	swap(a[low],a[h]);
	part(a,low,h);
	part(a,h+1,high);
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	int low=0,high=n-1;
	part(a,low,high);
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
}
