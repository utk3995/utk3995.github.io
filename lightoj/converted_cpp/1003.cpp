#include &lt;bits/stdc++.h&gt;
using namespace std;
vector &lt; vector&lt;int&gt; &gt; G(10010);
int visited[10010]; // 0 white 1 gray 2 black
int flag=1;

void dfs(int v)
{
    int i;
    visited[v]=1;
    if (flag==0)
        return;
    for (i=0;i&lt;G[v].size();i++){
        if (visited[G[v][i]]==1){
            flag=0;
            return;
            //cout&lt;&lt;v&lt;&lt;"  "&lt;&lt;G[v][i]&lt;&lt;endl;
        }
        else if (visited[G[v][i]]==0){
            dfs(G[v][i]);
        }
    }
    visited[v]=2;
}

int main ()
{
    //freopen("input.txt","r",stdin);
    int t;
    cin&gt;&gt;t;
    int cas=1;
    while (t--){
        int n,i;
        cin&gt;&gt;n;
        int co=0;
        for (i=0;i&lt;10010;i++){
            G[i].clear();
            visited[i]=0;
        }
        flag=1;
        map &lt;string,int&gt; m;
        while (n--){
            string str1,str2;
            cin&gt;&gt;str1&gt;&gt;str2;
            if (m.find(str1)==m.end())
                m[str1]=co++;
            if (m.find(str2)==m.end())
                m[str2]=co++;
            G[m[str1]].push_back(m[str2]);
        }

        for (i=0;i&lt;co;i++){
            if (visited[i]==0){
                dfs(i);
            }
        }
        if (flag==0)
            cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;": No"&lt;&lt;endl;
        else
            cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;": Yes"&lt;&lt;endl;
    }
}

