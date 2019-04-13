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
int n;
int a[10][10];
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
		if(a[v-1][i]==1)
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
				while(!stkemp(s1))
				{
					int t;t=pop(s1);cout<<t<<" ";
					push(s,t);
				}
				cout<<endl;
				pop(s);
			}
			else{
				if(!check(s,i+1))
				cycle(i+1,s);
			}
		    
		}
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
		cout<<"cycles of "<<v<<" : "<<endl;
		temp=v;
		cycle(v,s);
	}
	return 0;
}

