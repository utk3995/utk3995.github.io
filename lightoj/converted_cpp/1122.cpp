#include &lt;bits/stdc++.h&gt;
using namespace std;
int main ()
{
    int t;
    cin&gt;&gt;t;
    int p=1;
    while(t--){
        int n,i,j,k,m;
        cin&gt;&gt;n&gt;&gt;m;
        int a[n];
        for (i=0;i&lt;n;i++)
            cin&gt;&gt;a[i];
        int b[n][m+1];
        for (i=0;i&lt;m+1;i++){
            for (j=0;j&lt;n;j++){
                b[j][i]=0;
            }
        }
        for (i=0;i&lt;n;i++)
            b[i][1]=1;
        for (i=2;i&lt;m+1;i++){
            for (j=0;j&lt;n;j++){
                for (k=0;k&lt;n;k++){
                    if (fabs(a[j]-a[k])&lt;=2){
                        b[j][i]+=b[k][i-1];
                    }
                }
            }
        }
        int ans=0;
        for (i=0;i&lt;n;i++)
            ans+=b[i][m];
        cout&lt;&lt;"Case "&lt;&lt;p++&lt;&lt;":"&lt;&lt;" ";
        cout&lt;&lt;ans&lt;&lt;endl;
    }
    return 0;
}

