#include<iostream>
using namespace std;

void create (int ** G,int n)
{
   for (int i=0; i<n; i++)
    {
      for (int j=0; j<n; j++)         // initializing every element to zero
	    G[i][j] = 0; 	
    }
        
   while (1)
   {
   	    int i,j;char k;
        //cout<<"Enter the vertex numbers having an edge between them : ";
        cin>>i>>j>>k;
        if  (i==j)           break;
        else         G[i-1][j-1]=int(k);      
   }
}

int indegree (int ** G,int v,int n)
{
	int count=0;
	for (int i=0; i<n; i++)
	  if (G[i][v]==1)                   count++;               
	return count;
}

int l=0;
void top (int **G,int n,int v[],int arr[])
{
	int H[n][n];
	for (int i=0; i<n; i++)
	for (int j=0; j<n; j++) 
	H[i][j] = G[i][j];
	if (l==n)
	{
		for (int i=0; i<n; i++)
		cout<<arr[i];
		cout<<endl;
	}
	else
	{
       for (int i=0; i<n; i++)
	    {
	      if  ( (indegree(G,i,n)==0)  &&   (v[i]==0) )
	      {
	        for (int j=0; j<n; j++)  
	   	    G[i][j]=0;
            v[i] = 1;                   
            arr[l] = i+1;
            l++;
            top (G,n,v,arr);        
            v[i]=0;
            for (int i=0; i<n; i++) 
		    for (int j=0; j<n; j++) 
	        G[i][j] = H[i][j];
		  }
	    }
	}
   l = l-1;
}

int main()
{
   int n;
  // cout<<"Enter the number of vertices in your graph : ";
   cin>>n;
   int** G;                  
   G = new int*[n];
   for (int  i=0;i<n;i++)             G[i] = new int[n];
   
   create (G,n);
   //cout<<"All topological sorting sequences are given by : "<<endl;
	
	int v[n],arr[n];  
	for (int i=0; i<n; i++)          v[i]=0; 
	top (G,n,v,arr);
	
    return 0;
}
