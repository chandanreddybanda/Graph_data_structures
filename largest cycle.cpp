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
int n,count=0;
int a[10][10];
int o[20][20];
bool check(stack s,int l){
	for(int i=0;i<=s.top;i++){
		if(s.elements[i]==l)
		return true;
	}
	return false;
}
int p=0;
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
				int j=1;
				while(!stkemp(s1))
				{
					int t;t=pop(s1);o[p][j++]=t;o[p][0]++;
					push(s,t);
				}
				if(count<o[p][0])
				count=o[p][0];
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
	for(int i=0;i<p;i++)
	{
		if(count==o[i][0])
		{
			for(int j=1;j<=count;j++)
			cout<<o[i][j]<<" ";
			cout<<endl;
	    }
	}
	return 0;
}

