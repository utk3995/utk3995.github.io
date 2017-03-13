#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vi vector<int>
#define vii vector < pii >
#define si set<int>
#define ll long long int
#define pb push_back
#define mp make_pair
#define fr first
#define se second
#define MOD 1000003
#define MAX 10100

int a[110];
ll dp[110][110];
int n;

ll func(int l,int u)
{
    if (l>u){
        return 0;
    }
    if (dp[l][u] != -1)
        return dp[l][u];
    ll ret = INT_MIN;
    ll sum=0;
    for (int i=l;i<=u;i++){
        sum += a[i];
            ret = max(ret , sum - func(i+1,u));
    }
    sum=0;
    for (int i=u;i>=l;i--){
        sum += a[i];
            ret = max(ret , sum - func(l,i-1));
    }
    dp[l][u] = ret;
    return ret;
}

int main ()
{
    //cout << setprecision(7) << fixed;
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int cas=1;
	while (t--){
		cout<<"Case "<<cas++<<": ";
        cin>>n;
        for (int i=0;i<n;i++){
            cin>>a[i];
            for (int j=0;j<n;j++){
                dp[i][j] = dp[i][j] =-1;
            }
        }
        cout<<func(0,n-1)<<endl;
	}
	return 0;
}

