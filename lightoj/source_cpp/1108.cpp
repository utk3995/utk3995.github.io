#include <bits/stdc++.h>
using namespace std;

#define MAX 1050

int n;// no. of nodes
int m;// no. of edges

vector < pair<int,int> > g[MAX];
vector <int> rg[MAX];
vector < pair< int , pair <int,int> > > e;
vector <int> an;
int dis[MAX];
bool vis[MAX];

int f=0;
stack <int> st;

void dfs(int v)
{
    vis[v]=1;
    f=1;
    for (int i=0;i<rg[v].size();i++){
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
	cin>>t;
	int cas=1;
	while (t--){
        //char ch=getchar();
        cin>>n>>m;
        f=0;
        for (int i=0;i<n;i++){
            g[i].clear();
            rg[i].clear();
            dis[i]=1000000;
            vis[i]=0;
        }
        an.clear();
        e.clear();

        for(int i=0;i<m;i++){
            int x,y,w;
            cin>>x>>y>>w;
            g[x].push_back(make_pair(y,w));
            e.push_back(make_pair(w,make_pair(y,x)));
            rg[y].push_back(x);
        }

        //dis[1]=0;


        //Relax all edges n-1 times.
        for (int i=1;i<n;i++){
            for (int j=0;j<m;j++){
                int x = e[j].second.first;
                int y = e[j].second.second;
                int w = e[j].first;
                if (dis[x] != INT_MAX && dis[x] + w < dis[y])
                    dis[y] = dis[x] + w;
            }
        }

        //check for -ve weight cycle

        for (int j=0;j<m;j++){
            int x = e[j].second.first;
            int y = e[j].second.second;
            int w = e[j].first;
            if (dis[x] != INT_MAX && dis[x] + w < dis[y]){
                an.push_back(x);
                f=1;
            }
        }

        for (int j=0;j<an.size();j++){
            if (!vis[an[j]])
                dfs(an[j]);
        }


        cout<<"Case "<<cas++<<":";
        if (f==0)
            cout<<" impossible"<<endl;
        else{
            for (int i=0;i<n;i++){
                if (vis[i])
                    cout<<" "<<i;
            }
            cout<<endl;
        }
	}
	return 0;
}


