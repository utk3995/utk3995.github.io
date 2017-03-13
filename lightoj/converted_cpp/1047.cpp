#include &lt;bits/stdc++.h&gt;
using namespace std;
#define pii pair&lt;int,int&gt;
#define vi vector&lt;int&gt;
#define vii vector &lt; pii &gt;
#define si set&lt;int&gt;
#define ll long long int
#define pb push_back
#define mp make_pair
#define fr first
#define se second
#define MOD 1000003
#define MAX 10100

int n;
ll c[40][3];
ll dp[40][3];

int main ()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	int t;
	cin&gt;&gt;t;
	int cas=1;
	while (t--){
        memset(dp,0,sizeof(dp));
		cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;": ";
        cin&gt;&gt;n;
        for (int i=0;i&lt;n;i++){
            for (int j=0;j&lt;3;j++){
                cin&gt;&gt;c[i][j];
            }
        }
        dp[0][0] = c[0][0];
        dp[0][1] = c[0][1];
        dp[0][2] = c[0][2];
        for (int i=1;i&lt;n;i++){
            dp[i][0] = min((dp[i-1][1] + c[i][0]),(dp[i-1][2] + c[i][0]));
            dp[i][1] = min((dp[i-1][0] + c[i][1]),(dp[i-1][2] + c[i][1]));
            dp[i][2] = min((dp[i-1][0] + c[i][2]),(dp[i-1][1] + c[i][2]));
        }
        cout&lt;&lt;min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]))&lt;&lt;endl;
	}
	return 0;
}

