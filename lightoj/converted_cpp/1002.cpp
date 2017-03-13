#include &lt;bits/stdc++.h&gt;
using namespace std;
int mat[510][510];
int main ()
{
    int cas=1;
    int t;
    scanf("%d",&t);
    while (t--){
        memset(mat,-1,sizeof(mat));
        char foo;
        scanf("%c",foo);
        int n,m,i,j;
        scanf("%d %d",&n,&m);
        int visited[n];
        int cost[n];

        for (i=0;i&lt;n;i++){
            cost[i]=999999;
            visited[i]=0;
        }

        while (m--){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            if (mat[u][v]==-1)
                mat[u][v]=mat[v][u]=w;
            else if (mat[u][v]&gt;w)
                mat[u][v]=mat[v][u]=w;
        }
        int h;
        scanf("%d",&h);
        priority_queue &lt; pair&lt;int,int&gt; , vector&lt; pair&lt;int,int&gt; &gt; , greater&lt; pair&lt;int,int&gt; &gt; &gt; q; //min_heap priority queue
        q.push(make_pair(0,h)); //
        cost[h]=0;
        //visited[h]=1;
        while (!q.empty()){
            pair&lt;int,int&gt; po=q.top();
            q.pop();
            int ve=po.second,co=po.first;
            if (visited[ve])
                continue;
            visited[ve]=1;
            for (i=0;i&lt;n;i++){
                if (mat[ve][i]&gt;0 && visited[i]==0){
                    /*if (cost[ve]&lt;mat[ve][i] && mat[ve][i]&lt;cost[i])
                        cost[i]=mat[ve][i];
                    else if (mat[ve][i]&lt;cost[ve] && cost[ve]&lt;cost[i])
                        cost[i]=cost[ve];*/
                    cost[i]=min(cost[i],max(cost[ve],mat[ve][i]));
                    q.push(make_pair(cost[i],i));
                }
            }
        }
        cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;":"&lt;&lt;endl;
        for (i=0;i&lt;n;i++){
            if (cost[i]!=999999)
                cout&lt;&lt;cost[i]&lt;&lt;endl;
            else
                cout&lt;&lt;"Impossible"&lt;&lt;endl;
        }
    }
    return 0;
}

