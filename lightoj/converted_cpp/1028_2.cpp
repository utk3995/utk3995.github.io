#include &lt;bits/stdc++.h&gt;
using namespace std;
#define pii pair&lt;int,int&gt;
#define vi vector&lt;int&gt;
#define vl vector&lt; ll &gt;
#define vii vector &lt; pii &gt;
#define si set&lt;int&gt;
#define ll long long int
#define pb push_back
#define mp make_pair
#define fr first
#define se second
#define MAX 1000100
#define MOD 1000003
vl prime;
int pr[MAX];

void seive()
{
    for (int i=2;i&lt;MAX;i++){
        if (pr[i]==0){
            prime.pb(i);
            for (int j=2;i*j&lt;MAX;j++){
                pr[i*j]=1;
            }
        }
    }
}

ll primefactorize( ll n )
{
    ll ans=1;
	ll sqrtN = (ll)(sqrt(n));
	for (ll i=0;prime[i]&lt;=sqrtN && i&lt;prime.size();i++){
        ll temp=1;
		//if(n &lt; prime[i])
        //    break;
		if (n%prime[i] == 0){
			while (n%prime[i] == 0){
				n=n/prime[i];
                temp++;
			}
			ans*=temp;
			sqrtN = (ll)(sqrt(n));
		}

	}
	if (n&gt;1){
		ans=ans*2;
	}
    return ans;
}

int main ()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	int t;
	cin&gt;&gt;t;
	int cas=1;
	seive();
	while (t--){
		cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;": ";
        ll n;
        cin&gt;&gt;n;
        ll ans=primefactorize(n);
        cout&lt;&lt;ans-1&lt;&lt;endl;
	}
	return 0;
}

