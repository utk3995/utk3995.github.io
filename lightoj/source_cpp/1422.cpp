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

int dp[120][120];
int n;
int a[120];

int func(int low,int hi)
{
    if (low == hi)
        return 1;
    if (low > hi)
        return 0;
    if (dp[low][hi] != -1)
        return dp[low][hi];
    int ret = func(low+1,hi)+1;
    for (int i=low+1;i<=hi;i++){
        if (a[i]==a[low]){
            ret = min(ret,func(low,i-1)+func(i+1,hi));
        }
    }
    return (dp[low][hi] = ret);
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
        memset(dp,-1,sizeof(dp));
		cout<<"Case "<<cas++<<": ";
        cin>>n;
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<func(0,n-1)<<endl;
	}
	return 0;
}


