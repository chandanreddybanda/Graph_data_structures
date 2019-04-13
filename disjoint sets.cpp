#include<iostream>
using namespace std;
int s[10];
int find(int i)
{
	if(s[i]==0)
	return i;
	else
	return find(s[i]);
}
void unio(int i,int j)
{
	if(s[i]==0)
	s[i]=j;
	else if(s[j]==0)
	s[j]=i;
	else
	s[find(i)]=j;
}
int main()
{
	int x,y,ch=1;
	while(ch!=6)
	{
		cout<<"enter sets \n";
		cin>>x>>y;
		unio(x,y);
		ch++;
	}
	cout<<"enter digitsto search";
	cin>>x>>y;
	if(find(x)==find(y))
	cout<<"in same set\n";
	else
	cout<<"not in same set/n";
}
