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

int dp[110][110];
ll y[110];
ll w,n;

int func(int pos,int kr)
{
    if (kr == 0){
        return 0;
    }
    else if (pos == n){
        return 0;
    }
    if (dp[pos][kr] != -1)
        return dp[pos][kr];
    int up = upper_bound(y,y+n,y[pos]+w)-y;
    int ret = up-pos;
    dp[pos][kr] = max(ret + func(up,kr-1) , func(pos+1,kr));
    //cout&lt;&lt;pos&lt;&lt;"  "&lt;&lt;kr&lt;&lt;"  "&lt;&lt;dp[pos][kr]&lt;&lt;endl;
    return dp[pos][kr];
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
        int k;
        cin&gt;&gt;n&gt;&gt;w&gt;&gt;k;
        int foo;
        for (int i=0;i&lt;n;i++){
            cin&gt;&gt;foo&gt;&gt;y[i];
        }
        sort(y,y+n);
        cout&lt;&lt;func(0,k)&lt;&lt;endl;
	}
	return 0;
}

