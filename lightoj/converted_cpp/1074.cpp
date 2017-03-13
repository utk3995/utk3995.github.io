#include &lt;bits/stdc++.h&gt;
using namespace std;

#define MAX 1050

int n;// no. of nodes
int m;// no. of edges

vector &lt; pair&lt; int , pair &lt;int,int&gt; &gt; &gt; e;
long long int dis[MAX];


int main ()
{
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
	int t;
	cin&gt;&gt;t;
	int cas=1;
	while (t--){
        cin&gt;&gt;n;
        long long int ww[n];
        for (int i=1;i&lt;=n;i++){
            dis[i]=INT_MAX;
            cin&gt;&gt;ww[i];
        }

        e.clear();

        cin&gt;&gt;m;
        for(int i=0;i&lt;m;i++){
            int x,y;
            cin&gt;&gt;x&gt;&gt;y;
            long long int w = (ww[y]-ww[x])*(ww[y]-ww[x])*(ww[y]-ww[x]);
            e.push_back(make_pair(w,make_pair(x,y)));
        }

        dis[1]=0;

        for (int i=1;i&lt;n;i++){
            for (int j=0;j&lt;m;j++){
                int x = e[j].second.first;
                int y = e[j].second.second;
                long long int w = e[j].first;
                if (dis[x] != INT_MAX && dis[x] + w &lt; dis[y])
                    dis[y] = dis[x] + w;
            }
        }


        //check for -ve weight cycle

        /*for (int j=0;j&lt;m;j++){
            int x = e[j].second.first;
            int y = e[j].second.second;
            int w = e[j].first;
            if (dis[x] != INT_MAX && dis[x] + w &lt; dis[y]){
                an.push_back(x);
                f=1;
            }
        }*/
        int q;
        cin&gt;&gt;q;
        cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;":"&lt;&lt;endl;
        while (q--){
            int k;
            cin&gt;&gt;k;
            if (dis[k]&lt;3 || dis[k]==INT_MAX)
                cout&lt;&lt;"?"&lt;&lt;endl;
            else
                cout&lt;&lt;dis[k]&lt;&lt;endl;
        }
	}
	return 0;
}


