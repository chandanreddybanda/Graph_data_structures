/* disjoint sets find-union */
#include <iostream>
using namespace std;
struct gnode{
	int w;
	int u;
	int v;
}G[10];
int *s;
int n;
int find(int i){
//	cout<<"i:"<<i<<endl;
	if(s[i]==-1)
	return i;
	else
	return find(s[i]);
}
void uni_on(int i,int j){
	if(s[i]==-1){
		s[i]=j;
	}
	else if(s[j]==-1){
		s[j]=i;
	}
	else{
		s[find(i)]=j;
	}
}
int sameset(int i,int j){
	if(find(i)==find(j))
	return 1;
	else
	return 0;
}
int main(){
	cout<<"enter number of vertices :";
	cin>>n;s=new int[n];
	for(int i=0;i<n;i++)
	s[i]=-1;
	cout<<"enter number of edges :";int ed;cin>>ed;int i=0;
	while(i<ed){
		cout<<"enter u:";cin>>G[i].u;
		cout<<"enter v:";cin>>G[i].v;
		cout<<"enter w:";cin>>G[i].w;i++;
	}
	int x,y=0,min=9999;int count=0;
	while(y<ed){
	for(int i=0;i<ed;i++){
		if(min>G[i].w)
		{
		min=G[i].w;x=i;
	}
	}
//	cout<<"min:"<<min;cout<<" x:"<<x<<endl;
	int a=find(G[x].u-1),b=find(G[x].v-1);
		if(a!=b){
		uni_on(G[x].u-1,G[x].v-1);
		count=count+G[x].w;
		}
		G[x].w=9999;
	y++;min=9999;
}
cout<<"total weight :"<<count;
	return 0;
}
