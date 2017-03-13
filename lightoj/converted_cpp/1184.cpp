#include &lt;bits/stdc++.h&gt;
using namespace std;

vector&lt;int&gt;graph[1003]; // first n elements (0 to n-1) are set a therefter are set b
int n,m; // n is the left set and m is the right set size.

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
    int match[5+n];
    memset(match,-1,sizeof(match));
    int ans=0;
    for(int i=0;i&lt;m;i++){
        bool seen[n+5];
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
        cin&gt;&gt;m&gt;&gt;n;
        int a[m][3];
        int b[n][3];
        for (int i=0;i&lt;m;i++) {
            cin&gt;&gt;a[i][0]&gt;&gt;a[i][1]&gt;&gt;a[i][2];
        }
        for (int i=0;i&lt;n;i++) {
            cin&gt;&gt;b[i][0]&gt;&gt;b[i][1]&gt;&gt;b[i][2];
            for (int j=0;j&lt;m;j++){
                int f=1;
                if (fabs(a[j][0]-b[i][0])&gt;12)
                    f=0;
                if (fabs(a[j][1]-b[i][1])&gt;5)
                    f=0;
                if ((a[j][2]^b[i][2])==1)
                    f=0;
                if (f==1)
                    graph[j].push_back(i);
            }
        }
        cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;": "&lt;&lt;bpm()&lt;&lt;endl;
    }
    return 0;
}


