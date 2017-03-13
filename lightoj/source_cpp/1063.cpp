#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vi vector<int>
#define vii vector < pii >
#define si set<int>
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
	for (int jj=0;jj<adj[i].size();jj++){
		int j = adj[i][jj];
		if(!visited[j])
		{
			child++;
			parent[j]=i;
			articulate(j);
			low[i]=min(low[i],low[j]);
			if(parent[i]==-1&&child>1)
				ap[i]=true;
			if(parent[i]!=-1&&low[j]>=disc[i])
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
	for(int i=1;i<=n;i++)
		if(!visited[i])
			articulate(i);
	for(int i=1;i<=n;i++)
		if(ap[i]){
			//cout<<i<<endl;
			ans++;
		}
}

void clea(int n)
{
    ans=0;
    for (int i=0;i<=n+1;i++){
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
	cin>>t;
	int cas=1;
	while (t--){
		cout<<"Case "<<cas++<<": ";
		int n,m;
        cin>>n>>m;
        clea(n);
        for (int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        func(n);
        cout<<ans<<endl;
	}
	return 0;
}

