#include &lt;bits/stdc++.h&gt;
using namespace std;
int main ()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin&gt;&gt;t;
    int cas=1;
    while (t--){
        cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;": ";
        string s1;
        cin&gt;&gt;s1;
        int n=s1.size();
        string s2 = s1;
        reverse(s2.begin(),s2.end());
        int dp[n+1][n+1];
        for (int i=0;i&lt;=n;i++){
            for (int j=0;j&lt;=n;j++){
                /*if (i==0 && j==0){
                    dp[i][j]=0;
                    continue;
                }*/
                if (i==0 || j==0){
                    dp[i][j]=0;
                    continue;
                }
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                if (s1[i-1] == s2[j-1])
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
            }
        }
        cout&lt;&lt;(n-dp[n][n])&lt;&lt;endl;
    }
    return 0;
}

