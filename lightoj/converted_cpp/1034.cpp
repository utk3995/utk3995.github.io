#include &lt;bits/stdc++.h&gt;
using namespace std;
vector &lt; vector&lt;int&gt; &gt; G(10010);
int visited[10010];
stack &lt;int&gt; s;

int dfs(int v,int flag)
{
    int i,u;
    visited[v]=1;
    for (i=0;i&lt;G[v].size();i++){
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
    cin&gt;&gt;t;
    int cas=1;
    while (t--){
    int n,e,i;
    cin&gt;&gt;n&gt;&gt;e;
    for (i=0;i&lt;=10010;i++)
        G[i].clear(),visited[i]=0;
    while (!s.empty())
        s.pop();
    while (e--){
        int u,v;
        cin&gt;&gt;u&gt;&gt;v;
        G[u].push_back(v);
    }
    for (i=1;i&lt;=n;i++){
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
    //cout&lt;&lt;co&lt;&lt;endl;
    }
    return 0;
}

