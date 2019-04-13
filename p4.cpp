#include<iostream>
using namespace std;
int mi(int a,int b,int c)
{
	if(min(min(a,b),c)==a)
	return 0;
	else if(min(min(a,b),c)==b)
	return 1;
	else
	return 2;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	int i=0,c=0;
	while(i<n&&i+2<n)
	{
		i=i+mi(a[i],a[i+1],a[i+2]);
		c=c+a[i];
		i++;
	}
	cout<<c;
}

