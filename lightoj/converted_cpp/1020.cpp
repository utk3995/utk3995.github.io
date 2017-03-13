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
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	#endif
	//ios_base::sync_with_stdio(false);
	int t;
	scanf("%d",&t);
	int cas=1;
	while (t--){
		cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;": ";
        ll n;
        scanf("%lld",&n);
        char s[10];
        scanf("%s",s);
        if (strcmp(s,"Alice")==0){
            if (n%3==1)
                cout&lt;&lt;"Bob"&lt;&lt;endl;
            else
                cout&lt;&lt;"Alice"&lt;&lt;endl;
        }
        else{
            if (n%3==0)
                cout&lt;&lt;"Alice"&lt;&lt;endl;
            else
                cout&lt;&lt;"Bob"&lt;&lt;endl;
        }
	}
	return 0;
}

