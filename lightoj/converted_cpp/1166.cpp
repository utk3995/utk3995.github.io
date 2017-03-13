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

map &lt; pair &lt;int,int&gt; , int &gt; dp;

int main ()
{
	//freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
    int t;
    cin&gt;&gt;t;
    int cas=1;
    while(t--){
        int n;
        cin&gt;&gt;n;
        int a[n];
        int b[n];
        for (int i=0;i&lt;n;i++){
            cin&gt;&gt;a[i];
            b[i]=a[i];
        }
        sort(b,b+n);
        int co=0;
        for (int i=0;i&lt;n;i++){
            if (a[i] != i+1){
                for (int j=i+1;j&lt;n;j++){
                    if (a[j]==i+1){
                        co++;
                        swap(a[i],a[j]);
                    }
                }
            }
        }
        cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;": "&lt;&lt;co&lt;&lt;endl;
    }
	return 0;
}

