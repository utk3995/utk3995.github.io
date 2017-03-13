#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vi vector<int>
#define vii vector < pii >
#define si set<int>
#define ll long long int
#define pb push_back
#define mp make_pair
#define MOD 1000000007

ll fact[2001000];

void precompute()
{
    fact[0]=1;
    for (ll i=1;i<2001000;i++)
        fact[i] = (fact[i-1]*i)%MOD;
}

ll x,y;

void extenedEuclid(ll a, ll b){
    ll tx,ty;
    if( b == 0){
        x = a;
        y = 0;
        return;
    }
    extenedEuclid(b, a % b);
    tx = y;
    ty = x - a/b*y;
    x = tx;
    y = ty;
}

ll invmod(ll a)
{
    extenedEuclid(a,MOD);
    ll xx=x;
    while (xx<0) xx+=MOD;
    xx=xx%MOD;
    return xx;
}

ll C(ll n,ll r)
{
    ll nf = fact[n];
    ll rf = fact[r];
    ll nmrf = fact[n-r];
    ll inr = invmod(rf);
    ll innmr = invmod(nmrf);
    ll ans = (((nf*inr)%MOD)*innmr)%MOD;
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
    precompute();
    while (t--){
        cout<<"Case "<<cas++<<": ";
        ll n,k;
        cin>>n>>k;
        cout<<C(n+k-1,k-1)<<endl;
    }
    return 0;
}

