#include &lt;bits/stdc++.h&gt;
using namespace std;

int dp[70][2][10];

bool isvowel(char ch)
{
    if (ch == &apos;A&apos; || ch == &apos;E&apos; || ch == &apos;I&apos; || ch == &apos;O&apos; || ch == &apos;U&apos;)
        return true;
    return false;
}

bool isques(char ch)
{
    if (ch == &apos;?&apos;)
        return true;
    return false;
}

int func(string s, int pos, int counttillnow, int vowcons)
{
    if (counttillnow == 0){
        return 0;
    }
    if (pos == s.size()){
        return 1;
    }
    if (dp[pos][vowcons][counttillnow] != -1)
        return dp[pos][vowcons][counttillnow];
    int ret;
    if (isques(s[pos]) == 0){
        if (isvowel(s[pos])){
            if (vowcons == 1)
                ret = func(s,pos+1,counttillnow-1,1);
            else
                ret = func(s,pos+1,2,1);
        }
        else{
            if (vowcons == 1)
                ret = func(s,pos+1,4,2);
            else
                ret = func(s,pos+1,counttillnow-1,2);
        }
    }
    else{
        int retc,retv;
        if (vowcons == 1){
            retc = func(s,pos+1,4,2);
            retv = func(s,pos+1,counttillnow-1,1);
        }
        else{
            retc = func(s,pos+1,counttillnow-1,2);
            retv = func(s,pos+1,2,1);
        }
        if (retc == 0 && retv == 0)
            ret = 0;
        else if (retc == 1 && retv == 1)
            ret = 1;
        else
            ret = 2;
    }
    dp[pos][vowcons][counttillnow] = ret;
    return ret;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    int t;
    cin&gt;&gt;t;
    int cas=1;
    while (t--){
        memset(dp,-1,sizeof(dp));
        cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;": ";
        string s;
        cin&gt;&gt;s;
        int l=s.size();
        int ret;
        if (isques(s[0]) == 0){
            if (isvowel(s[0]))
                ret = func(s,1,2,1);
            else
                ret = func(s,1,4,2);
        }
        else{
                int ret1,ret2;
                ret1 = func(s,1,2,1);
                ret2 = func(s,1,4,2);
                if (ret1 == 0 && ret2 == 0)
                    ret = 0;
                else if (ret1 == 1 && ret2 == 1)
                    ret = 1;
                else
                    ret = 2;
        }
        if (ret == 0) cout&lt;&lt;"BAD"&lt;&lt;endl;
        else if (ret == 1) cout&lt;&lt;"GOOD"&lt;&lt;endl;
        else cout&lt;&lt;"MIXED"&lt;&lt;endl;
    }
}

