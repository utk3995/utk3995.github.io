#include &lt;bits/stdc++.h&gt;
using namespace std;
#define pii pair&lt;int,int&gt;
#define vi vector&lt;int&gt;
#define vii vector &lt; pii &gt;
#define ll long long int
#define si set&lt;int&gt;
#define pb push_back
#define se second
#define fr first
#define mp make_pair
#define ll long long int
#define MOD 1e9+7
#define pb push_back
#define mp make_pair
#define vi vector &lt;int&gt;
const int MAX=1e4+5;

vi adj[MAX];
bool vis[MAX];
int disc[MAX];
int low[MAX];
int color[MAX];
int parent[MAX];
int col=0;
vector &lt; pair &lt; int,int &gt; &gt; ans;


void bridge (int u)
{
    static int time=0;
    vis[u] = true;
    disc[u] = low[u] = ++time;
    for (int i=0;i&lt;adj[u].size();i++){
        int v=adj[u][i];
        if (!vis[v]){
            parent[v]=u;
            bridge(v);
            low[u] = min(low[u],low[v]);
            if (low[v] &gt; disc[u]){
                ans.pb(mp(min(u,v),max(u,v)));
                //cout&lt;&lt;u&lt;&lt;" "&lt;&lt;v&lt;&lt;endl;
            }
        }
        else if (v!=parent[u])
            low[u]=min(low[u],disc[v]);
    }
}

void func(int n)
{
    for (int i=0;i&lt;n;i++){
        parent[i] = 0;
        vis[i] = false;
    }
    for (int i=0;i&lt;n;i++){
        if (!vis[i])
            bridge(i);
    }
}

void clea()
{
    col=0;
    ans.clear();
    for (int i=0;i&lt;MAX;i++){
        adj[i].clear();
        vis[i]=false;
        disc[i]=low[i]=color[i]=parent[i]=0;
    }
}


int nn;

int main ()
{
    //freopen("input.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--){
        clea();
        printf("Case %d:\n",cas++);
        scanf("%d",&nn);
        for (int i=0;i&lt;nn;i++){
            int u;
            scanf("%d",&u);
            char ss[10010];
            scanf("%s",ss);
            int kk=0;
            for (int i=1;i&lt;strlen(ss)-1;i++)
                kk=kk*10+(ss[i]-&apos;0&apos;);
            //cout&lt;&lt;u&lt;&lt;"  "&lt;&lt;kk&lt;&lt;endl;
            for (int j=0;j&lt;kk;j++){
                int foo;
                scanf("%d",&foo);
                adj[u].pb(foo);
            }
        }
        func(nn);
        printf("%d critical links\n",ans.size());
        sort(ans.begin(),ans.end());
        for (int i=0;i&lt;ans.size();i++)
            printf("%d - %d\n",ans[i].fr,ans[i].se);
    }
    return 0;
}

