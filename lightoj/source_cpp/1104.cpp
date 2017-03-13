#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vi vector<int>
#define vii vector < pii >
#define si set<int>
#define ll long long int
#define pb push_back
#define mp make_pair
#define fr first
#define se second
#define MAX 10100
#define MOD 1000003

int main ()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int cas=1;
	while (t--){
		cout<<"Case "<<cas++<<": ";
        double n;
        cin>>n;
        double p = 1.0;
        int ans;
        for (int i=1;p > 0.5 ;i++){
            ans=i;
            p = p*(1.0-((double)i)/n);
        }
        cout<<ans<<endl;
	}
	return 0;
}

