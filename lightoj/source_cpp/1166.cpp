#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define fr first
#define se second
#define MOD 1000000007

map < pair <int,int> , int > dp;

int main ()
{
	//freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    int cas=1;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        int b[n];
        for (int i=0;i<n;i++){
            cin>>a[i];
            b[i]=a[i];
        }
        sort(b,b+n);
        int co=0;
        for (int i=0;i<n;i++){
            if (a[i] != i+1){
                for (int j=i+1;j<n;j++){
                    if (a[j]==i+1){
                        co++;
                        swap(a[i],a[j]);
                    }
                }
            }
        }
        cout<<"Case "<<cas++<<": "<<co<<endl;
    }
	return 0;
}

