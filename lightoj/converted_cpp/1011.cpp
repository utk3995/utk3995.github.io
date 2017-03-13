#include &lt;bits/stdc++.h&gt;
using namespace std;
int a[20][20];
int n;
int dp[100000][20];

int func(long long int mask,int pos)
{
    if (pos==n)
        return 0;
    if (dp[mask][pos]!=-1)
        return dp[mask][pos];
    int ret=0;
    for (int i=0;i&lt;n;i++){
        if (mask & (1&lt;&lt;i))
            continue;
        ret = max(ret,func((mask | 1&lt;&lt;i),pos+1)+a[pos][i]);
    }
    dp[mask][pos]=ret;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("in.txt","r",stdin);
    int t;
    cin&gt;&gt;t;
    int cas=1;
    while (t--){
        memset(a,0,sizeof(a));
        memset(dp,-1,sizeof(dp));
        cin&gt;&gt;n;
        for (int i=0;i&lt;n;i++){
            for (int j=0;j&lt;n;j++){
                cin&gt;&gt;a[i][j];
            }
        }
        cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;": "&lt;&lt;func(0,0)&lt;&lt;endl;
    }
}

