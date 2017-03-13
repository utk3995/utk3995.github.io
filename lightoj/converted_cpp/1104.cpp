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
        double n;
        cin&gt;&gt;n;
        double p = 1.0;
        int ans;
        for (int i=1;p &gt; 0.5 ;i++){
            ans=i;
            p = p*(1.0-((double)i)/n);
        }
        cout&lt;&lt;ans&lt;&lt;endl;
	}
	return 0;
}

