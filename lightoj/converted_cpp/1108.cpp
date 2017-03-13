#include &lt;bits/stdc++.h&gt;
using namespace std;

#define MAX 1050

int n;// no. of nodes
int m;// no. of edges

vector &lt; pair&lt;int,int&gt; &gt; g[MAX];
vector &lt;int&gt; rg[MAX];
vector &lt; pair&lt; int , pair &lt;int,int&gt; &gt; &gt; e;
vector &lt;int&gt; an;
int dis[MAX];
bool vis[MAX];

int f=0;
stack &lt;int&gt; st;

void dfs(int v)
{
    vis[v]=1;
    f=1;
    for (int i=0;i&lt;rg[v].size();i++){
        int u=rg[v][i];
        if (!vis[u])
            dfs(u);
    }
}


int main ()
{
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
	int t;
	cin&gt;&gt;t;
	int cas=1;
	while (t--){
        //char ch=getchar();
        cin&gt;&gt;n&gt;&gt;m;
        f=0;
        for (int i=0;i&lt;n;i++){
            g[i].clear();
            rg[i].clear();
            dis[i]=1000000;
            vis[i]=0;
        }
        an.clear();
        e.clear();

        for(int i=0;i&lt;m;i++){
            int x,y,w;
            cin&gt;&gt;x&gt;&gt;y&gt;&gt;w;
            g[x].push_back(make_pair(y,w));
            e.push_back(make_pair(w,make_pair(y,x)));
            rg[y].push_back(x);
        }

        //dis[1]=0;


        //Relax all edges n-1 times.
        for (int i=1;i&lt;n;i++){
            for (int j=0;j&lt;m;j++){
                int x = e[j].second.first;
                int y = e[j].second.second;
                int w = e[j].first;
                if (dis[x] != INT_MAX && dis[x] + w &lt; dis[y])
                    dis[y] = dis[x] + w;
            }
        }

        //check for -ve weight cycle

        for (int j=0;j&lt;m;j++){
            int x = e[j].second.first;
            int y = e[j].second.second;
            int w = e[j].first;
            if (dis[x] != INT_MAX && dis[x] + w &lt; dis[y]){
                an.push_back(x);
                f=1;
            }
        }

        for (int j=0;j&lt;an.size();j++){
            if (!vis[an[j]])
                dfs(an[j]);
        }


        cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;":";
        if (f==0)
            cout&lt;&lt;" impossible"&lt;&lt;endl;
        else{
            for (int i=0;i&lt;n;i++){
                if (vis[i])
                    cout&lt;&lt;" "&lt;&lt;i;
            }
            cout&lt;&lt;endl;
        }
	}
	return 0;
}


