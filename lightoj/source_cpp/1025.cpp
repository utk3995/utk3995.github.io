#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[60][60];

ll func(string s,int start,int finish)
{
    if (start > finish)
        return 0;
    if (start == finish)
        return 1;
    if (dp[start][finish] != -1)
        return dp[start][finish];
    if (s[start] == s[finish])
        dp[start][finish] = 1 + func(s,start+1,finish-1) + func(s,start+1,finish) + func(s,start,finish-1) - func(s,start+1,finish-1);
    else
        dp[start][finish] = func(s,start+1,finish) + func(s,start,finish-1) - func(s,start+1,finish-1);
    return dp[start][finish];
}

int main ()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    int cas=1;
    while (t--){
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<cas++<<": ";
        string s;
        cin>>s;
        ll ans = func(s,0,s.size()-1);
        cout<<ans<<endl;
    }
}

