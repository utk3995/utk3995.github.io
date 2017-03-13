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
#define MOD 1000003
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
        unsigned ll x;
        cin>>x;
        if (x%9 == 0){
            cout<<(x/9)*10-1<<" "<<(x/9)*10<<endl;
        }
        else{
            cout<<(x*10)/9<<endl;
        }
	}
	return 0;
}


