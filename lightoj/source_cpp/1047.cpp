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

int n;
ll c[40][3];
ll dp[40][3];

int main ()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int cas=1;
	while (t--){
        memset(dp,0,sizeof(dp));
		cout<<"Case "<<cas++<<": ";
        cin>>n;
        for (int i=0;i<n;i++){
            for (int j=0;j<3;j++){
                cin>>c[i][j];
            }
        }
        dp[0][0] = c[0][0];
        dp[0][1] = c[0][1];
        dp[0][2] = c[0][2];
        for (int i=1;i<n;i++){
            dp[i][0] = min((dp[i-1][1] + c[i][0]),(dp[i-1][2] + c[i][0]));
            dp[i][1] = min((dp[i-1][0] + c[i][1]),(dp[i-1][2] + c[i][1]));
            dp[i][2] = min((dp[i-1][0] + c[i][2]),(dp[i-1][1] + c[i][2]));
        }
        cout<<min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]))<<endl;
	}
	return 0;
}

