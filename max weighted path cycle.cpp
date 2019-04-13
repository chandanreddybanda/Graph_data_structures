#include<iostream>
using namespace std;
struct stack{
	int size;
	int top;
	stack()
	{
		size=30;
		top=-1;
	}
	int elements[50];
};
int stkemp(stack s){
	if(s.top==-1)
	return 1;
	else 
	return 0;
}
int stkful(stack s){
	if(s.top==s.size-1){
		return 1;
	}
	else return 0;
}
void push(stack &s,int k){
	if(stkful(s)){
		cout<<"stack is full"<<endl;
	}
	else
	s.elements[++s.top]=k;
}
int pop(stack &s){
	if(stkemp(s)){
		cout<<"stack is empty";
	}
	else{
		int c=s.elements[s.top--];
		return c;
	}
}
int temp,flag=0;
int n;int p=0,count=0,l[20];
int a[10][10],O[15][15];
bool check(stack s,int l){
	for(int i=0;i<=s.top;i++){
		if(s.elements[i]==l)
		return true;
	}
	return false;
}
void cycle(int v,stack s)
{
	for(int i=0;i<n;i++)
	{
		if(a[v-1][i]>0)
		{
			if(s.elements[s.top]!=v)
			push(s,v);
			if(i==temp-1)
			{
				push(s,i+1);
				stack s1;
				while(!stkemp(s))
				{
					push(s1,pop(s));
				}
				int j=1;
				while(!stkemp(s1))
				{
					int t;t=pop(s1);O[p][j++]=t;O[p][0]++;
					push(s,t);
				}
				p++;
				pop(s);
			}
			else{
				if(!check(s,i+1))
				cycle(i+1,s);
			}
		    
		}
	}
}
void pathlen(){
	for(int i=0;i<p;i++){
		l[i]=0;
		for(int j=1;j<O[i][0];j++){
			l[i]=l[i]+a[O[i][j]-1][O[i][j+1]-1];
		}
		if(count<l[i])count=l[i];
	}
}
int main()
{
	cout<<"Enter number of vertices -> ";
	cin>>n;
	stack s;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	int v;
	for(v=1;v<=n;v++){
		temp=v;
		cycle(v,s);
	}
	pathlen();
	for(int i=0;i<p;i++){
		if(count==l[i]){
			for(int j=1;j<=O[i][0];j++){
				cout<<O[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}

