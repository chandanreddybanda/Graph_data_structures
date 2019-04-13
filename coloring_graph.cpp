#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
vector<vector<int> > g;
int visi[200009];
int lol(int color,int cur){
	for(int i=0;i<g[cur].size();i++){
		if(visi[g[cur][i]]){
			if(ans[g[cur][i]]==color)
			return 0;
		}
	}
	return 1;
}
bool start(int c,int cur){
	int fla=1;
	for(int i=0;i<g[cur].size();i++){
		if(!visi[g[cur][i]]){
			for(int k=1;k<=c;k++){
				visi[g[cur][i]]=1;
				if(lol(k,g[cur][i])){
					ans[g[cur][i]]=k;
					//cout<<g[cur][i]<<" "<<k<<endl;
					if(start(c,g[cur][i]))
					return 1;
					ans[g[cur][i]]=0;
				}
				visi[g[cur][i]]=1;
			}
			fla=0;
		}
	}
	if(lol(ans[cur],cur))
	return 1;
	return 0;
}
int main(){
	int n,m;
	cin>>n>>m;
	g.resize(n+1);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int c;
	c=n+1;
	ans.resize(n+1);bool z=1;
	for(int i=1;i<=n;i++){
		start(c,i);
	}
	for(int i=1;i<=n;i++)
	if(ans[i]==0)
	{z=0;break;}
	if(z){
		for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	}
	else
	cout<<"Looser"<<endl;
}
/*
10 15
1 2
2 3
1 4
3 4
3 1
4 5
6 3
2 6
3 5
7 6
8 6
10 9
8 10
9 8
7 8
*/
