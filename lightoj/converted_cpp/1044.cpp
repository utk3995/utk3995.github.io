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
        string s;
        cin&gt;&gt;s;
        int n=s.size();
        bool dp[n][n];
        for (int i=0;i&lt;n;i++){
            dp[i][i]=true;
        }
        for (int l=2;l&lt;=n;l++){
            for (int i=0;i&lt;n-l+1;i++){
                int j=i+l-1;
                if (j == i+1)
                    dp[i][j] = (s[i] == s[j]);
                else
                    dp[i][j] = (s[i] == s[j]) && (dp[i+1][j-1]);
            }
        }
        int co[n];
        for (int i=0;i&lt;n;i++){
            co[i]=INT_MAX;
            if (dp[0][i] == true)
                co[i]=1;
            for (int j=0;j&lt;i;j++){
                if (dp[j+1][i] == true)
                    co[i] = min(co[j]+1,co[i]);
            }
        }
        cout&lt;&lt;co[n-1]&lt;&lt;endl;
	}
	return 0;
}

