#include<iostream>
using namespace std;
int main()
{
	long long int n,k,c=0;
	cin>>n>>k;
	long long a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	long long int i=0;
	while(i<n)
	{
		if(a[i]<k)
		{
			for(long long int j=i+1;j<n;j++)
			{
				if(k-a[i]>a[j])
				c++;
			}
		}i++;
	}
	cout<<c;
}
