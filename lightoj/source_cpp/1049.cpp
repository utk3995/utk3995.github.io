#include <bits/stdc++.h>
using namespace std;
int n;
int g[110][110];
bool visited[110];

void clea(int n)
{
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            g[i][j]=INT_MAX;
        }
    }
}

void visfa(int n)
{
    for (int i=1;i<=n;i++)
        visited[i]=false;
}

int dfs(int v,int pa)
{
    if (visited[v])
        return 0;
    visited[v]=true;
    for (int i=1;i<=n;i++){
        if (g[v][i]!=INT_MAX && i!=pa){
            return (g[v][i] + dfs(i,v));
        }
    }
}

int main ()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    int cas=1;
    while (t--){
        cout<<"Case "<<cas++<<": ";
        cin>>n;
        clea(n);
        vector < int > pa;
        for (int i=0;i<n;i++){
            int a,b,c;
            cin>>a>>b>>c;
            g[a][b]=0;
            g[b][a]=c;
            if (a==1 || b==1)
                pa.push_back((a==1 ? b : a));
        }
        int c1,c2;
        visfa(n);
        //visited[1]=true;
        c1 = dfs(1,pa[0]);
        visfa(n);
        //visited[1]=true;
        c2 = dfs(1,pa[1]);
        cout<<min(c1,c2)<<endl;
    }
    return 0;
}
