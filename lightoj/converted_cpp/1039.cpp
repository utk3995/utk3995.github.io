#include &lt;bits/stdc++.h&gt;
using namespace std;
#define ll long long int
#define vi vector &lt;int&gt;
#define si set &lt;int&gt;
#define mp make_pair
#define pb push_back
#define fr first
#define se second
#define pii pair &lt;int,int&gt;

int f[50][3][26];
queue &lt; pair&lt;string,int&gt; &gt; q;
map &lt;string,bool&gt; ma;
int n;

void clea()
{
    while (!q.empty())
        q.pop();
    memset(f,0,sizeof(f));
    ma.clear();
}

bool che(string s)
{
    bool ret = true;
    for (int i=0;i&lt;n;i++){
        if (f[i][0][s[0]] == 1 && f[i][1][s[1]] && f[i][2][s[2]])
            return false;
    }
    return true;
}


int main ()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin&gt;&gt;t;
    int cas=1;
    while (t--){
        clea();
        string st,en;
        cin&gt;&gt;st;
        cin&gt;&gt;en;
        cin&gt;&gt;n;
        string fo[3];
        for (int i=0;i&lt;n;i++){
            cin&gt;&gt;fo[0]&gt;&gt;fo[1]&gt;&gt;fo[2];
            for (int j=0;j&lt;fo[0].size();j++)
                f[i][0][fo[0][j]]=1;
            for (int j=0;j&lt;fo[1].size();j++)
                f[i][1][fo[1][j]]=1;
            for (int j=0;j&lt;fo[2].size();j++)
                f[i][2][fo[2][j]]=1;
        }
        int ans=-1;
        if (che(st) && che(en))
            q.push(mp(st,0));
        while (!q.empty()){
            pair &lt;string,int&gt; po=q.front();
            q.pop();
            if (po.fr==en){
                ans=po.se;
                break;
            }
            if (ma.find(po.fr)!=ma.end())
                continue;
            ma[po.fr]=true;
            for (int i=0;i&lt;3;i++){
                string ne1=po.fr;
                string ne2=po.fr;
                if (po.fr[i]==&apos;a&apos;){
                    ne1[i]=&apos;z&apos;;
                    ne2[i]=&apos;b&apos;;
                }
                else if (po.fr[i]==&apos;z&apos;){
                    ne1[i]=&apos;y&apos;;
                    ne2[i]=&apos;a&apos;;
                }
                else {
                    ne1[i]=po.fr[i]-1;
                    ne2[i]=po.fr[i]+1;
                }
                if (che(ne1))
                    q.push(mp(ne1,po.se+1));
                if (che(ne2))
                    q.push(mp(ne2,po.se+1));
            }
        }
        cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;": "&lt;&lt;ans&lt;&lt;endl;
    }
    return 0;
}

