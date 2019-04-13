#include<bits/stdc++.h>
using namespace std;
//find articulation points in undirected graph using DFS (Tarjans algo)
 
int visited[100],disc[100],low[100],ap[100],parent[100],tm1;
vector<int> v[100];
void dfs(int ver){
	visited[ver] = 1;
	disc[ver] = tm1; 	low[ver] = tm1;
	int i;
	int child=0;
	tm1++;
	for (i=0;i<v[ver].size();i++){
		if(visited[v[ver][i]]==0){
			dfs(v[ver][i]);
			parent[v[ver][i]] = ver;
 			low[ver] = min(low[ver],low[v[ver][i]]);
			child++;
			if(parent[ver]==-1 && child>1){
				ap[ver] = 1;
			}
			 if(parent[ver]!=-1 && disc[ver]<=low[v[ver][i]]){
				ap[ver] = 1;
			}
		}
		else if(v[ver][i]!=parent[ver]){
			low[ver] = min(low[ver],low[v[ver][i]]);
		}
	}
}
int main(){
 
	int t,x,y,i,j,e,n;
	cin>>t;
	while (t--){
		cin>>n>>e;
		for (i=0;i<e;i++){
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		memset(ap,0,sizeof(ap));
		memset(visited,0,sizeof(visited));
		parent[0] = -1;
		tm1=0;
		dfs(0);
		for (i=0;i<n;i++){
			if(ap[i]){
				cout <<i<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}
