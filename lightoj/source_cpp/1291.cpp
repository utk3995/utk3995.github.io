#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1e9+7
#define pb push_back
#define mp make_pair
#define vi vector <int>
const int MAX=1e4+5;
vi adj[MAX];
set <int> nadj[MAX];
set <int> g[MAX];
bool vis[MAX];
int disc[MAX];
int low[MAX];
int color[MAX];
int parent[MAX];
int col=0;


void bridge (int u)
{
    static int time=0;
    vis[u] = true;
    disc[u] = low[u] = ++time;
    for (int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if (!vis[v]){
            parent[v]=u;
            bridge(v);
            low[u] = min(low[u],low[v]);
            if (low[v] > disc[u]){
                //cout<<u<<" "<<v<<endl;
                g[u].erase(v);
                g[v].erase(u);
            }
        }
        else if (v!=parent[u])
            low[u]=min(low[u],disc[v]);
    }
}

void dfs(int u)
{
    vis[u]=true;
    color[u]=col;
    set<int>::iterator it;
    for (it=g[u].begin();it != g[u].end();it++){
        if (!vis[*it])
            dfs(*it);
    }
}


int func(int n)
{
    for (int i=0;i<n;i++){
        parent[i] = 0;
        vis[i] = false;
    }
    for (int i=0;i<n;i++){
        if (!vis[i])
            bridge(i);
    }
    memset(vis,false,sizeof(vis));
    for (int i=0;i<n;i++){
        if (!vis[i]){
            col++;
            dfs(i);
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<adj[i].size();j++){
            if (color[adj[i][j]]!=color[i]){
                nadj[color[i]].insert(color[adj[i][j]]);
                nadj[color[adj[i][j]]].insert(color[i]);
            }
        }
    }
    int ans=0;
    for (int i=0;i<=col;i++){
        if (nadj[i].size()==1)
            ans++;
    }
    return (ceil(ans+1)/2);
}

void clear(int n)
{
    col=0;
    for (int i=0;i<MAX;i++){
        adj[i].clear();
        nadj[i].clear();
        g[i].clear();
        vis[i]=false;
        disc[i]=low[i]=color[i]=parent[i]=0;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    int cas=1;
    while (t--){
        int n,m;
        cin>>n>>m;
        clear(n);
        for (int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
            g[u].insert(v);
            g[v].insert(u);
        }
        cout<<"Case "<<cas++<<": "<<func(n)<<endl;
    }
}

