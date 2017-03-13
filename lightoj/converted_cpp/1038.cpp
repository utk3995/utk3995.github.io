/*
The first person has a 100% chance of a unique number (of course)
The second has a (1 – 1/365) chance (all but 1 number from the 365)
The third has a (1 – 2/365) chance (all but 2 numbers)
The 23rd has a (1 – 22/365) (all but 22 numbers)
p(different) = 1 * (1-1/d) * (1 - 2/d) * (1 - 3/d) ....
p(exist a match) = 1 - p(different)
*/

#include &lt;bits/stdc++.h&gt;
using namespace std;
#define pii pair&lt;int,int&gt;
#define vi vector&lt;int&gt;
#define vii vector &lt; pii &gt;
#define si set&lt;int&gt;
#define ll long long int
#define pb push_back
#define mp make_pair
#define fr first
#define se second
#define MAX 10100
#define MOD 1000003

double ans[100100];
int divi[100100];
void precompute()
{
    ans[1]=0;
    for (int i=2;i&lt;100100;i++){
        ans[i] = (ans[i] + divi[i] + 2)/((double)(divi[i] + 1));
        for (int j=2;i*j&lt;100100;j++){
            ans[i*j] += ans[i];
            divi[i*j]++;
        }
    }
}

int main ()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	int t;
	cout &lt;&lt; setprecision(7);
	cout &lt;&lt; fixed;
	cin&gt;&gt;t;
	int cas=1;
	precompute();
	while (t--){
		cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;": ";
        int n;
        cin&gt;&gt;n;
        cout&lt;&lt;ans[n]&lt;&lt;endl;
	}
	return 0;
}

