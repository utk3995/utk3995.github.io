#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int t;
    cin>>t;
    int p=1;
    while(t--){
        int n,i,j,k,m;
        cin>>n>>m;
        int a[n];
        for (i=0;i<n;i++)
            cin>>a[i];
        int b[n][m+1];
        for (i=0;i<m+1;i++){
            for (j=0;j<n;j++){
                b[j][i]=0;
            }
        }
        for (i=0;i<n;i++)
            b[i][1]=1;
        for (i=2;i<m+1;i++){
            for (j=0;j<n;j++){
                for (k=0;k<n;k++){
                    if (fabs(a[j]-a[k])<=2){
                        b[j][i]+=b[k][i-1];
                    }
                }
            }
        }
        int ans=0;
        for (i=0;i<n;i++)
            ans+=b[i][m];
        cout<<"Case "<<p++<<":"<<" ";
        cout<<ans<<endl;
    }
    return 0;
}

