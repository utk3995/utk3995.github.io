#include &lt;bits/stdc++.h&gt;
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define DSU_SZ 100
int a[100][100];
int ans=0;
vector &lt; pair&lt;int, pair&lt;int,int&gt; &gt; &gt; e;

int n,dad[DSU_SZ+5],rnk[DSU_SZ+5],N;

void init(int nn)
{
    n = nn;
    N=n;
    for (int i = 0; i &lt;=DSU_SZ; i++)
    {
        rnk[i] = 0;
        dad[i] = i;
    }
}
int root(int v)
{
    if (v == dad[v]) return v;
    return dad[v] = root(dad[v]);
}
void join(int v1, int v2)
{
    v1 = root(v1), v2 = root(v2);
    if (v1 == v2) return;
    if (rnk[v1] &lt; rnk[v2]) swap(v1, v2);
    dad[v2] = v1;
    N--;
    if (rnk[v1] == rnk[v2]) rnk[v1]++;
}


int main ()
{
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin&gt;&gt;t;
    int cas=1;
    while (t--){
        int n;
        cin&gt;&gt;n;
        init(n+1);
        ans=0;
        e.clear();
        for (int i=0;i&lt;n;i++){
            for (int j=0;j&lt;n;j++){
                cin&gt;&gt;a[i][j];
                if (i==j){
                    ans+=a[i][j];
                    a[i][j]=0;
                }
                if (a[i][j]!=0){
                    e.pb(mp(a[i][j],mp(i,j)));
                }
            }
        }
        sort(e.begin(),e.end());

        for (int i=0;i&lt;e.size();i++){
            pair &lt; int, pair&lt;int,int&gt; &gt; po=e[i];
            int wt = po.first;
            int fr = po.second.first;
            int se = po.second.second;
            //cout&lt;&lt;wt&lt;&lt;" "&lt;&lt;fr&lt;&lt;"  "&lt;&lt;root(fr)&lt;&lt;"  "&lt;&lt;se&lt;&lt;"  "&lt;&lt;root(se)&lt;&lt;endl;
            //cout&lt;&lt;wt&lt;&lt;" "&lt;&lt;fr&lt;&lt;"  "&lt;&lt;se&lt;&lt;endl;
            if (root(fr)!=root(se)){
                join(se,fr);
            }
            else{
                ans+=wt;
            }
        }
        set &lt;int&gt; ss;
        for (int i=0;i&lt;n;i++)
            ss.insert(root(i));
        //cout&lt;&lt;"*"&lt;&lt;endl;
   //     cout&lt;&lt;ss.size()&lt;&lt;endl;
        if (ss.size()&gt;1)
            ans=-1;
        cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;": "&lt;&lt;ans&lt;&lt;endl;
    }
    return 0;
}

