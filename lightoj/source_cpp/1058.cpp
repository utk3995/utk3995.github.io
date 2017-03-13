#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back

vector < pair < int,int > > v;
int x[1010],y[1010];

int main ()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    int cas=1;
    while (t--){
        v.clear();
        cout<<"Case "<<cas++<<": ";
        int n;
        cin>>n;
        for (int i=0;i<n;i++)
            cin>>x[i]>>y[i];
        for (int i=0;i<n-1;i++){
            for (int j=i+1;j<n;j++){
                ll xi=x[i];
                ll yi=y[i];
                ll xj=x[j];
                ll yj=y[j];
                int midx = ((x[i]+x[j]));
                int midy = ((y[i]+y[j]));
                //ll midx = ((xi+xj));
                //ll midy = ((yi+yj));
                v.pb(mp(midx,midy));
            }
        }
        sort(v.begin(),v.end());
        ll ans=0;
        int k=0;
        for (int i=1;i<v.size();i++){
            //if (v[i]==v[i-1])
            //    k++;
            if((v[i].first == v[i-1].first) and (v[i].second == v[i-1].second)) {
				k++;
            }
            else{
                ans += (k*(k+1))/2;
                k=0;
            }
            //cout<<v[i].first<<"  "<<v[i].second<<endl;
        }
        ans += (k*(k+1))/2;
        cout<<ans<<endl;
    }
}

