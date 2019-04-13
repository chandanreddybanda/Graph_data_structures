#include<bits/stdc++.h>
using namespace std;
int ans=0;
string mdif(string s){
	set<char>c;
	string a="";
	for(int i=0;i<s.length();i++)
	{if(s[i]!=' '){c.insert(s[i]);a+=s[i];}}
	ans=c.size();
	return a;
}
int main(){
	int t=1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s[n];pair<int,int> size[n];
		for(int i=0;i<n;i++){
			cin.ignore();
			string a="";
			getline(cin,a);
			s[i]=mdif(a);
			size[i].first=ans;size[i].second=i;
			ans=0;
		}
		sort(size,size+n);
		int y=size[n-1].first-1;
		vector<pair<int,int> > v(size,size+n);
		int x=upper_bound(v.begin(),v.end(),y)-v.begin();
		string final="";
		for(int i=x;i<n;i++){
			final=max(final,s[size[i].second]);
		}
		cout<<final<<endl;
	}
}
