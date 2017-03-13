#include &lt;bits/stdc++.h&gt;
using namespace std;

vector&lt;int&gt;graph[1003];
int n,m;
map &lt;int,int&gt; ma;

bool check(int i,bool *seen,int *match)
{
    for(int j=0;j&lt;graph[i].size();j++){
        if(!seen[graph[i][j]]){
            seen[graph[i][j]]=true;
            if(match[graph[i][j]]&lt;0||check(match[graph[i][j]],seen,match)){
                match[graph[i][j]]=i;
                return true;
            }
        }
    }
    return false;
}

int bpm()
{
    int match[n+3+m];
    memset(match,-1,sizeof(match));
    int ans=0;
    for(int i=0;i&lt;n;i++){
        bool seen[n+m+5];
        memset(seen,false,sizeof(seen));
        if(check(i,seen,match))
        ans++;
    }
    return ans;
}

int main()
{
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin&gt;&gt;t;
    int cas=1;
    while (t--){
        for (int i=0;i&lt;1003;i++)
            graph[i].clear();
        cin&gt;&gt;n;
        int a[n];
        for (int i=0;i&lt;n;i++) {
            cin&gt;&gt;a[i];
        }
        cin&gt;&gt;m;
        int b[m];
        for (int i=0;i&lt;m;i++){
            cin&gt;&gt;b[i];
            for (int j=0;j&lt;n;j++){
                if (b[i]%a[j]==0)
                    graph[j].push_back(n+i);
            }
        }
        /*for (int i=0;i&lt;n;i++){
            cout&lt;&lt;a[i]&lt;&lt;" : ";
            for (int j=0;j&lt;graph[i].size();j++){
                cout&lt;&lt;graph[i][j]&lt;&lt;"  ";
            }
            cout&lt;&lt;endl;
        }
        cout&lt;&lt;endl&lt;&lt;endl;*/
        cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;": "&lt;&lt;bpm()&lt;&lt;endl;
    }
    return 0;
}

//graph[i].push_back(j);
//cout&lt;&lt;bpm()&lt;&lt;endl;

