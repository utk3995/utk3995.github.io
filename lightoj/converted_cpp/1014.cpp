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
#define MOD 1000003

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
		cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;": ";
        ll p,l;
        cin&gt;&gt;p&gt;&gt;l;
        p=p-l;
        vector &lt; ll &gt; ans;
        for (ll i=1;i*i&lt;=p;i++){
            if (p%i == 0){
                if (i &gt; l)
                    ans.pb(i);
                if (p/i &gt; l && i*i != p)
                    ans.pb(p/i);
            }
        }
        if (ans.size() &gt;= 1 ){
            sort(ans.begin(),ans.end());
            for (int i=0;i&lt;ans.size()-1;i++){
                cout&lt;&lt;ans[i]&lt;&lt;" ";
            }
            cout&lt;&lt;ans[ans.size()-1]&lt;&lt;endl;
        }
        else
            cout&lt;&lt;"impossible"&lt;&lt;endl;
	}
	return 0;
}

