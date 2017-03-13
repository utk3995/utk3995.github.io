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

int dp[120][120];
int n;
int a[120];

int func(int low,int hi)
{
    if (low == hi)
        return 1;
    if (low &gt; hi)
        return 0;
    if (dp[low][hi] != -1)
        return dp[low][hi];
    int ret = func(low+1,hi)+1;
    for (int i=low+1;i&lt;=hi;i++){
        if (a[i]==a[low]){
            ret = min(ret,func(low,i-1)+func(i+1,hi));
        }
    }
    return (dp[low][hi] = ret);
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
        memset(dp,-1,sizeof(dp));
		cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;": ";
        cin&gt;&gt;n;
        for (int i=0;i&lt;n;i++){
            cin&gt;&gt;a[i];
        }
        cout&lt;&lt;func(0,n-1)&lt;&lt;endl;
	}
	return 0;
}


