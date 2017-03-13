#include <bits/stdc++.h>
using namespace std;
int main ()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    int cas=1;
    while (t--){
        cout<<"Case "<<cas++<<": ";
        string s1;
        cin>>s1;
        int n=s1.size();
        string s2 = s1;
        reverse(s2.begin(),s2.end());
        int dp[n+1][n+1];
        for (int i=0;i<=n;i++){
            for (int j=0;j<=n;j++){
                /*if (i==0 && j==0){
                    dp[i][j]=0;
                    continue;
                }*/
                if (i==0 || j==0){
                    dp[i][j]=0;
                    continue;
                }
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                if (s1[i-1] == s2[j-1])
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
            }
        }
        cout<<(n-dp[n][n])<<endl;
    }
    return 0;
}

