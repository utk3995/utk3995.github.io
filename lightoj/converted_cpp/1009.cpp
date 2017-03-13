#include &lt;bits/stdc++.h&gt;
using namespace std;
#define vi vector &lt;int&gt;
#define pb push_back

vi g[20100];
bool visit[20100];
bool pre[20100];
vi ff;
vi ss;

void clea()
{
    for (int i=0;i&lt;20100;i++){
        g[i].clear();
        visit[i]=0;
        pre[i]=0;
    }
    ff.clear();
    ss.clear();
}

void dfs(int v,int fl)
{
    if (visit[v] != 0)
        return;
    visit[v]=1;
    int nfl = ((fl==1) ? 2 : 1);
    if (fl == 1)
        ff.pb(v);
    else
        ss.pb(v);
    for (int i=0;i&lt;g[v].size();i++){
        int u = g[v][i];
        dfs(u,nfl);
    }
}

int main ()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin&gt;&gt;t;
    int cas=1;
    while (t--){
        cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;": ";
        int n;
        cin&gt;&gt;n;
        clea();
        int ma=0;
        for (int i=0;i&lt;n;i++){
            int u,v;
            cin&gt;&gt;u&gt;&gt;v;
            g[u].pb(v);
            g[v].pb(u);
            pre[u]=1;
            pre[v]=1;
            ma=max(ma,max(u,v));
        }
        int co=0;
        for (int i=1;i&lt;=ma;i++){
            if (pre[i]==1 && visit[i]==0){
                dfs(i,1);
                co+=max(ff.size(),ss.size());
                ff.clear();
                ss.clear();
            }
        }
        cout&lt;&lt;co&lt;&lt;endl;
    }
    return 0;
}

