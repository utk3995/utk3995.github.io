#include <bits/stdc++.h>
using namespace std;
#define V 110
int su1=0;
int su2=0;
int minKey1(int key[], bool mstSet[])
{
   int min = INT_MAX, min_index;
   for (int v = 0; v < V; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;

   return min_index;
}

int printMST1(int parent[], int n, int graph[V][V])
{
   for (int i = 1; i < V; i++)
		if (parent[i]!=-1)
			su1+=graph[i][parent[i]];
}

void primMST1(int graph[V][V])
{
     int parent[V];
     int key[V];
     bool mstSet[V];
     for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false,parent[i]=-1;
     key[0] = 0;
     parent[0] = -1;
     for (int count = 0; count < V-1; count++)
     {
        int u = minKey1(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
          if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }
     printMST1(parent, V, graph);
}


int maxKey(int key[], bool mstSet[])
{
   int ma = INT_MIN, max_index;
   for (int v = 0; v < V; v++)
     if (mstSet[v] == false && key[v] > ma)
         ma = key[v], max_index = v;

   return max_index;
}

int printMST2(int parent[], int n, int graph[V][V])
{
   for (int i = 1; i < V; i++)
		if (parent[i]!=-1)
			su2+=graph[i][parent[i]];
}

void primMST2(int graph[V][V])
{
     int parent[V];
     int key[V];
     bool mstSet[V];
     for (int i = 0; i < V; i++)
        key[i] = INT_MIN, mstSet[i] = false,parent[i]=-1;
     key[0] = 0;
     parent[0] = -1;
     for (int count = 0; count < V-1; count++)
     {
        int u = maxKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
          if (graph[u][v] && mstSet[v] == false && graph[u][v] >  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }
     printMST2(parent, V, graph);
}


int main ()
{
	int cas=1;
	int t;
	cin>>t;
	while (t--){
		su1=0;
		su2=0;
		int n;
		cin>>n;
		int i;
		int graph1[V][V];
		int graph2[V][V];
		memset(graph1,0,sizeof(graph1));
		memset(graph2,0,sizeof(graph2));
		int u,v,w;
		cin>>u>>v>>w;
		while (u!=0 || v!=0 || w!=0){
			if (graph1[u][v]==0 || graph1[u][v]>w){
				graph1[u][v]=graph1[v][u]=w;
			}
			if (graph2[u][v]==0 || graph2[u][v]<w){
				graph2[u][v]=graph2[v][u]=w;
			}
			cin>>u>>v>>w;
		}
		primMST1(graph1);
		primMST2(graph2);
		cout<<"Case "<<cas++<<": ";
		if ((su1%2==0 && su2%2==0) || (su1%2==1 && su2%2==1)){
			cout<<((su1+su2)/2)<<endl;
		}
		else{
			cout<<((su1+su2))<<"/2"<<endl;
		}
	}
	return 0;
}

