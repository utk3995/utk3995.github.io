#include&lt;bits/stdc++.h&gt;
using namespace std;

#define ll long long int
#define pii pair&lt;int,int&gt;
#define pll pair&lt;ll,ll&gt;
#define vi vector&lt;int&gt;
#define vl vector&lt;ll&gt;
#define pb push_back
#define mp make_pair
#define fr first
#define se second
#define MOD 1000000007

vector &lt; pii &gt; g[30100];

void clea(int n)
{
    for (int i=0;i&lt;n;i++)
        g[i].clear();

}

pll func(int v, int p)
{
    ll maxans=-1;
    vl mch;
    for (int i=0;i&lt;g[v].size();i++){
        int u = g[v][i].fr;
        ll w = g[v][i].se;
        if (u==p)
            continue;
        pll rec = func(u,v);
        maxans = max(maxans,rec.fr);
        mch.pb(rec.se+w);
    }
    if (mch.size()==0)
        return mp(0,0);
    if (mch.size()==1)
        return mp(mch[0],mch[0]);
    sort(mch.begin(),mch.end());
    maxans = max(maxans,(mch[mch.size()-1]+mch[mch.size()-2]));
    return mp(maxans,mch[mch.size()-1]);
}

int main ()
{
	//freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
    int t;
    cin&gt;&gt;t;
    int cas=1;
    while (t--){
        int n;
        cin&gt;&gt;n;
        clea(n);
        for (int i=0;i&lt;n-1;i++){
            int u,v,w;
            cin&gt;&gt;u&gt;&gt;v&gt;&gt;w;
            g[u].pb(mp(v,w));
            g[v].pb(mp(u,w));
        }
        pll ans = func(0,0);
        cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;": "&lt;&lt;ans.fr&lt;&lt;endl;
    }
    return 0;
}

