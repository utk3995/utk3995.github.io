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

int dp[55][55][55];

int main ()
{
    //cout &lt;&lt; setprecision(7) &lt;&lt; fixed;
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
        string a,b,c;
        cin&gt;&gt;a&gt;&gt;b&gt;&gt;c;
        int l1=a.size(),l2=b.size(),l3=c.size();
        //dp[0][0][0]=1;
        for (int i=1;i&lt;=l1;i++){
            for (int j=1;j&lt;=l2;j++){
                for (int k=1;k&lt;=l3;k++){
                    dp[i][j][k] = max(dp[i][j][k-1],max(dp[i][j-1][k],max(dp[i-1][j][k],max(dp[i][j-1][k-1],max(dp[i-1][j][k-1],dp[i-1][j-1][k])))));
                    if (a[i-1] == b[j-1] && b[j-1] == c[k-1])
                        dp[i][j][k] = max(dp[i][j][k],1+dp[i-1][j-1][k-1]);
                }
            }
        }
        cout&lt;&lt;dp[l1][l2][l3]&lt;&lt;endl;
	}
	return 0;
}
