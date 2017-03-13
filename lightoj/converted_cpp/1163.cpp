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
        unsigned ll x;
        cin&gt;&gt;x;
        if (x%9 == 0){
            cout&lt;&lt;(x/9)*10-1&lt;&lt;" "&lt;&lt;(x/9)*10&lt;&lt;endl;
        }
        else{
            cout&lt;&lt;(x*10)/9&lt;&lt;endl;
        }
	}
	return 0;
}


