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
        string s;
        cin>>s;
        int n=s.size();
        bool dp[n][n];
        for (int i=0;i<n;i++){
            dp[i][i]=true;
        }
        for (int l=2;l<=n;l++){
            for (int i=0;i<n-l+1;i++){
                int j=i+l-1;
                if (j == i+1)
                    dp[i][j] = (s[i] == s[j]);
                else
                    dp[i][j] = (s[i] == s[j]) && (dp[i+1][j-1]);
            }
        }
        int co[n];
        for (int i=0;i<n;i++){
            co[i]=INT_MAX;
            if (dp[0][i] == true)
                co[i]=1;
            for (int j=0;j<i;j++){
                if (dp[j+1][i] == true)
                    co[i] = min(co[j]+1,co[i]);
            }
        }
        cout<<co[n-1]<<endl;
	}
	return 0;
}

