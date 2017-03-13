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

double dp[510][510][2];
bool yes[510][510][2];

double func(int r,int b,int turn)
{
    if (r==0 && b!=0){
        return 1.0;
    }
    if (r!=0 && b==0){
        return 0.0;
    }
    if (yes[r][b][turn] == true)
        return dp[r][b][turn];;
    double ret=0;
    int nturn = (turn == 1) ? 0 : 1;
    if (turn == 1){
        ret = ((double)r/(double)(r+b))*func(r-1,b,nturn) + ((double)b/(double)(r+b))*func(r,b-1,nturn);
    }
    else {
        ret = func(r,b-1,nturn);
    }
    yes[r][b][turn] = true;
    return (dp[r][b][turn] = ret);
}

void clea()
{
    for (int i=0;i&lt;510;i++){
        for (int j=0;j&lt;510;j++){
            yes[i][j][0] = yes[i][j][1] = false;
        }
    }
    for (int i=0;i&lt;510;i++){
        dp[0][i][1] = 1.0;
        dp[i][0][1] = 0.0;
    }
}

void precompute()
{
    clea();
    for (int i=0;i&lt;510;i++){
        for (int j=0;j&lt;510;j++){
            for (int k=0;k&lt;2;k++){
                func(i,j,k);
            }
        }
    }
}

int main ()
{
    //cout &lt;&lt; setprecision(7) &lt;&lt; fixed;
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	#endif
	//ios_base::sync_with_stdio(false);
	int t;
	scanf("%d",&t);
	int cas=1;
	precompute();
	while (t--){
        //memset(dp,0,sizeof(dp));
		//cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;": ";
        printf("Case %d: ",cas++);
        int r,b;
        scanf("%d %d",&r,&b);
        printf("%.8lf\n",dp[r][b][1]);
	}
	return 0;
}


