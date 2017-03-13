#include &lt;bits/stdc++.h&gt;
using namespace std;
#define pii pair&lt;int,int&gt;
#define vi vector&lt;int&gt;
#define vii vector &lt; pii &gt;
#define si set&lt;int&gt;
#define ll long long int
#define pb push_back
#define mp make_pair
#define fr first
#define se second
#define MOD 1000003
#define MAX 10100

int parent[MAX];
vi adj[MAX];
int disc[MAX];
int low[MAX];
bool visited[MAX];
bool ap[MAX];
int ans=0;

void articulate(int i)
{
	static int timee=0;
	int child=0;
	visited[i]=true;
	disc[i]=low[i]=++timee;
	for (int jj=0;jj&lt;adj[i].size();jj++){
		int j = adj[i][jj];
		if(!visited[j])
		{
			child++;
			parent[j]=i;
			articulate(j);
			low[i]=min(low[i],low[j]);
			if(parent[i]==-1&&child&gt;1)
				ap[i]=true;
			if(parent[i]!=-1&&low[j]&gt;=disc[i])
				ap[i]=true;
		}
		else if(j!=parent[i])
			low[i]=min(low[i],disc[j]);
	}
}

void func(int n)
{
	fill(visited,visited+n+2,false);
	fill(parent,parent+n+2,-1);
	fill(ap,ap+n+2,false);
	for(int i=1;i&lt;=n;i++)
		if(!visited[i])
			articulate(i);
	for(int i=1;i&lt;=n;i++)
		if(ap[i]){
			//cout&lt;&lt;i&lt;&lt;endl;
			ans++;
		}
}

void clea(int n)
{
    ans=0;
    for (int i=0;i&lt;=n+1;i++){
        parent[i] = -1;
        visited[i] = false;
        ap[i] = false;
        adj[i].clear();
        low[i] = disc[i] = 0;
    }
}



int main ()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	int t;
	cin&gt;&gt;t;
	int cas=1;
	while (t--){
		cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;": ";
		int n,m;
        cin&gt;&gt;n&gt;&gt;m;
        clea(n);
        for (int i=0;i&lt;m;i++){
            int u,v;
            cin&gt;&gt;u&gt;&gt;v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        func(n);
        cout&lt;&lt;ans&lt;&lt;endl;
	}
	return 0;
}

