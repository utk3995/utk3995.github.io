/*
Suppose in the beginning u r standing in front of maze. Say this state as X.
Now lets say that the expected value of result for this question be E.
If there are n doors, E = Average of expected time taken to take each door.
E = (E1 + E2 + E3 ... + En)/N.
==&gt; If the value of Ai is positive, Ei = Ai coz it will take Ai time to get out of maze.
==&gt; If the value of Ai is negative, Ei = abs(Ai) + E coz u will roam around in the maze
for Ai minutes and then again go back to beginning, i.e. state X.
Now if all the values are negative then we will never be able to get out of the maze.
Then the answer will be infinity.*/


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
#define MOD 1000003
#define MAX 10100

ll gcd ( ll a , ll b )
{
    if (a%b == 0)
        return b;
    return gcd(b,a%b);
}


int main ()
{
    //cout &lt;&lt; setprecision(7) &lt;&lt; fixed;
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	int t;
	cin&gt;&gt;t;
	int cas=1;
	while (t--){
		cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;": ";
        int n;
        cin&gt;&gt;n;
        int a[n];
        for (int i=0;i&lt;n;i++){
            cin&gt;&gt;a[i];
        }
        int numer = 0;
        int denom = n;
        int negetives = 0;
        for (int i=0;i&lt;n;i++){
            numer += abs(a[i]);
            negetives += (a[i] &lt; 0) ? 1 : 0;
        }
        denom -= negetives;
        if (denom == 0)
            cout&lt;&lt;"inf"&lt;&lt;endl;
        else{
            int gc = gcd(numer,denom);
            cout&lt;&lt;numer/gc&lt;&lt;"/"&lt;&lt;denom/gc&lt;&lt;endl;
        }
	}
	return 0;
}


