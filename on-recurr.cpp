#include<iostream>
using namespace std;
 typedef struct btnode{
 	btnode *lchild;
 	char data;
 	btnode *rchild;
 }*btptr;
 string st;int i=0;
 struct stack{
 	int top;
 	int size;
 	btptr elements[50];
 };
 bool sempty(stack &s)
 {
 	return s.top==-1?true:false;
 } 
 bool sfull(stack &s)
 {
 	return s.top==s.size-1?true:false;
 }
 void push(btptr k,stack &s)
 {
 	if(sfull(s))
 	cout<<"stack is full\n";
 	else
 	s.elements[++s.top]=k;
 }
 btptr pop(stack &s)
 {
 	if(sempty(s))
 	{
 	cout<<"stack is empty\n";
 	return 0;
 }
 	else
 	return s.elements[s.top--];
 }
 void creation(btptr &T)
 {  if(i<st.length())
 	{
	 	T=new(btnode);
	 	T->lchild=NULL;
	 	T->data=st[i];
	 	T->rchild=NULL;
	 	if(st[++i]!='.')
	 	creation(T->lchild);
	 	if(st[++i]!='.')
	 	creation(T->rchild);
	}
 }
 char a[100];int l=0;
 void preorder(btptr &T,stack s)
 {btptr t=T;
 	if(t==NULL)
 	return;
 	else
 	{
 		push(t,s);
 		while(!sempty(s))
 		{
 			t=pop(s);
 			//cout<<t->data;
 			if(T->rchild!=NULL)
 			if(T->rchild->data==t->data)
			l=1;
 			a[l++]=t->data;
 			if(t->lchild==NULL && t->rchild==NULL)
 			{
 				for(int i=0;i<l;i++)
 				cout<<a[i]<<" ";
 				l--;
 				cout<<endl;
			 }
			 
 			if(t->rchild!=NULL)
 			push(t->rchild,s);
 			if(t->lchild!=NULL)
 			push(t->lchild,s);
		}
	 }
 }
 int main()
 {   btptr T;
 stack *s;
    s=new(stack);
    s->top=-1;
    s->size=50;
 	cout<<"enter the string of tree::";
 	cin>>st;
 	creation(T);
 	preorder(T,*s);
 }
