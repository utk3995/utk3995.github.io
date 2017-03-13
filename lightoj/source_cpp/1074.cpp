#include <bits/stdc++.h>
using namespace std;

#define MAX 1050

int n;// no. of nodes
int m;// no. of edges

vector < pair< int , pair <int,int> > > e;
long long int dis[MAX];


int main ()
{
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int cas=1;
	while (t--){
        cin>>n;
        long long int ww[n];
        for (int i=1;i<=n;i++){
            dis[i]=INT_MAX;
            cin>>ww[i];
        }

        e.clear();

        cin>>m;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            long long int w = (ww[y]-ww[x])*(ww[y]-ww[x])*(ww[y]-ww[x]);
            e.push_back(make_pair(w,make_pair(x,y)));
        }

        dis[1]=0;

        for (int i=1;i<n;i++){
            for (int j=0;j<m;j++){
                int x = e[j].second.first;
                int y = e[j].second.second;
                long long int w = e[j].first;
                if (dis[x] != INT_MAX && dis[x] + w < dis[y])
                    dis[y] = dis[x] + w;
            }
        }


        //check for -ve weight cycle

        /*for (int j=0;j<m;j++){
            int x = e[j].second.first;
            int y = e[j].second.second;
            int w = e[j].first;
            if (dis[x] != INT_MAX && dis[x] + w < dis[y]){
                an.push_back(x);
                f=1;
            }
        }*/
        int q;
        cin>>q;
        cout<<"Case "<<cas++<<":"<<endl;
        while (q--){
            int k;
            cin>>k;
            if (dis[k]<3 || dis[k]==INT_MAX)
                cout<<"?"<<endl;
            else
                cout<<dis[k]<<endl;
        }
	}
	return 0;
}


