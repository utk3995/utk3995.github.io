#include <bits/stdc++.h>
using namespace std;
vector < vector<int> > G(10010);
int visited[10010];
stack <int> s;

int dfs(int v,int flag)
{
    int i,u;
    visited[v]=1;
    for (i=0;i<G[v].size();i++){
        u=G[v][i];
        if (visited[u]==0)
            dfs(u,1);
    }
    if (flag==1)
        s.push(v);

}

int main ()
{
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    int cas=1;
    while (t--){
    int n,e,i;
    cin>>n>>e;
    for (i=0;i<=10010;i++)
        G[i].clear(),visited[i]=0;
    while (!s.empty())
        s.pop();
    while (e--){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
    }
    for (i=1;i<=n;i++){
        if (visited[i]==0)
            dfs(i,1);
    }

    memset(visited,0,sizeof(visited));
    int co=0;

    while (!s.empty()){
        i=s.top();
        s.pop();
        if (visited[i]==0)
            dfs(i,0),co++;
    }
    printf("Case %d: %d\n",cas++,co);
    //cout<<co<<endl;
    }
    return 0;
}

