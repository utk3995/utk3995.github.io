#include &lt;bits/stdc++.h&gt;
using namespace std;
int n,m;
vector &lt;int&gt; g[1050];
int dp[1050][2];
int vis[1050];

int func(int i,int f)
{
    vis[i]=1;
    if (dp[i][f]!=-1)
        return dp[i][f];
    dp[i][0]=0;
    dp[i][1]=1;
    for (int j=0;j&lt;g[i].size();j++){
        int v=g[i][j];
        if (vis[v]==0){
            dp[i][0] += max(func(v,0),func(v,1));
            dp[i][1] += func(v,0);
        }
    }
    return dp[i][f];
}

int main ()
{
   // freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin&gt;&gt;t;
    int cas=1;
    while (t--){
        memset(dp,-1,sizeof(dp));
        memset(vis,0,sizeof(vis));
        cin&gt;&gt;n&gt;&gt;m;
        for (int i=0;i&lt;1050;i++)
            g[i].clear();
        for (int i=0;i&lt;m;i++){
            int x,y;
            cin&gt;&gt;x&gt;&gt;y;
            x--,y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        int ans=0;
        for (int i=0;i&lt;n;i++){
            if (vis[i]==0){
                ans+=max(func(i,0),func(i,1));
            }
        }
        cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;": "&lt;&lt;ans&lt;&lt;endl;
    }
    return 0;
}

