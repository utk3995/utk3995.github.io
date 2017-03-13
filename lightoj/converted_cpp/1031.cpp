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

int a[110];
ll dp[110][110];
int n;

ll func(int l,int u)
{
    if (l&gt;u){
        return 0;
    }
    if (dp[l][u] != -1)
        return dp[l][u];
    ll ret = INT_MIN;
    ll sum=0;
    for (int i=l;i&lt;=u;i++){
        sum += a[i];
            ret = max(ret , sum - func(i+1,u));
    }
    sum=0;
    for (int i=u;i&gt;=l;i--){
        sum += a[i];
            ret = max(ret , sum - func(l,i-1));
    }
    dp[l][u] = ret;
    return ret;
}

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
		cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;": ";
        cin&gt;&gt;n;
        for (int i=0;i&lt;n;i++){
            cin&gt;&gt;a[i];
            for (int j=0;j&lt;n;j++){
                dp[i][j] = dp[i][j] =-1;
            }
        }
        cout&lt;&lt;func(0,n-1)&lt;&lt;endl;
	}
	return 0;
}

