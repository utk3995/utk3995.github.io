#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vi vector<int>
#define vl vector< ll >
#define vii vector < pii >
#define si set<int>
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
    for (int i=2;i<MAX;i++){
        if (pr[i]==0){
            prime.pb(i);
            for (int j=2;i*j<MAX;j++){
                pr[i*j]=1;
            }
        }
    }
}

ll primefactorize( ll n )
{
    ll ans=1;
	ll sqrtN = (ll)(sqrt(n));
	for (ll i=0;prime[i]<=sqrtN && i<prime.size();i++){
        ll temp=1;
		//if(n < prime[i])
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
	if (n>1){
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
	cin>>t;
	int cas=1;
	seive();
	while (t--){
		cout<<"Case "<<cas++<<": ";
        ll n;
        cin>>n;
        ll ans=primefactorize(n);
        cout<<ans-1<<endl;
	}
	return 0;
}

