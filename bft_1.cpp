#include<iostream>
using namespace std;
struct queue
{
int front;
int size;
int rear;
int ele[50];
}q;
int s[10];

void enque(queue *q,int x)
{
if(q->front==-1)
q->front=0;
q->rear=(q->rear+1)%q->size;
q->ele[q->rear]=x;
}
int deque(queue *q)
{
int x;
x=q->ele[q->front];
if(q->front==q->rear)
{
q->rear=-1;
q->front=-1;
}
else
{
q->front=(q->front+1)%q->size;
}
return x;
}
void bft(int g[][6],int v)
{
cout<<v<<"/";
s[v]=1;
for(int i=1;i<=5;i++)
{
if(g[v][i]==1&&s[i]==0)
{
enque(&q,i);
s[i]=1;
}
}
while(q.front!=-1&&q.rear!=-1)
{
int u=deque(&q);
bft(g,u);
}
}
int main()
{
q.front=-1;
q.rear=-1;
q.size=30;
for(int i=0;i<10;i++)
s[i]=0;
	int g[6][6];
	for(int i=0;i<6;i++)
	{
	for(int j=0;j<6;j++)
	g[i][j]=0;
	}
	g[1][2]=1;g[1][4]=1;g[1][3]=1;g[2][5]=1;g[2][1]=1;g[2][3]=1;g[3][1]=1;g[3][2]=1;g[3][4]=1;g[4][3]=1;g[4][5]=1;g[4][1]=1;g[5][2]=1;g[5][4]=1;
	bft(g,1);
}
