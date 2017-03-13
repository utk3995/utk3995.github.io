#include&lt;bits/stdc++.h&gt;
using namespace std;

#define ll long long int
#define pii pair&lt;int,int&gt;
#define pll pair&lt;ll,ll&gt;
#define vi vector&lt;int&gt;
#define pb push_back
#define mp make_pair
#define fr first
#define se second
#define MOD 1000000007
#define pl pair &lt; int , vector &lt; int &gt; &gt;


int main ()
{
	//freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
    int t;
    int cas=1;
    cin&gt;&gt;t;
    while (t--){
        int n,w;
        cin&gt;&gt;n&gt;&gt;w;
        vi yy;
        for (int i=0;i&lt;n;i++){
            int foo,y;
            cin&gt;&gt;foo&gt;&gt;y;
            yy.pb(y);
        }
        sort(yy.begin(),yy.end());
        ll ly=yy[0]+w;
        int co1=1;
        for (int i=1;i&lt;yy.size();i++){
            if (yy[i] &lt;= ly)
                continue;
            else{
                co1++;
                ly = yy[i]+w;
            }
        }
        ly=yy[yy.size()-1]-w;
        int co2=1;
        for (int i=yy.size()-2;i&gt;=0;i--){
            if (yy[i] &gt;= ly)
                continue;
            else{
                co2++;
                ly = yy[i] - w;
            }
        }
        cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;": "&lt;&lt;min(co1,co2)&lt;&lt;endl;
    }
	return 0;
}

