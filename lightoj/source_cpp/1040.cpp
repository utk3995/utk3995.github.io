#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define DSU_SZ 100
int a[100][100];
int ans=0;
vector < pair<int, pair<int,int> > > e;

int n,dad[DSU_SZ+5],rnk[DSU_SZ+5],N;

void init(int nn)
{
    n = nn;
    N=n;
    for (int i = 0; i <=DSU_SZ; i++)
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
    if (rnk[v1] < rnk[v2]) swap(v1, v2);
    dad[v2] = v1;
    N--;
    if (rnk[v1] == rnk[v2]) rnk[v1]++;
}


int main ()
{
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    int cas=1;
    while (t--){
        int n;
        cin>>n;
        init(n+1);
        ans=0;
        e.clear();
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cin>>a[i][j];
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

        for (int i=0;i<e.size();i++){
            pair < int, pair<int,int> > po=e[i];
            int wt = po.first;
            int fr = po.second.first;
            int se = po.second.second;
            //cout<<wt<<" "<<fr<<"  "<<root(fr)<<"  "<<se<<"  "<<root(se)<<endl;
            //cout<<wt<<" "<<fr<<"  "<<se<<endl;
            if (root(fr)!=root(se)){
                join(se,fr);
            }
            else{
                ans+=wt;
            }
        }
        set <int> ss;
        for (int i=0;i<n;i++)
            ss.insert(root(i));
        //cout<<"*"<<endl;
   //     cout<<ss.size()<<endl;
        if (ss.size()>1)
            ans=-1;
        cout<<"Case "<<cas++<<": "<<ans<<endl;
    }
    return 0;
}

