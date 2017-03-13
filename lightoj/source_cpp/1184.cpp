#include <bits/stdc++.h>
using namespace std;

vector<int>graph[1003]; // first n elements (0 to n-1) are set a therefter are set b
int n,m; // n is the left set and m is the right set size.

bool check(int i,bool *seen,int *match)
{
    for(int j=0;j<graph[i].size();j++){
        if(!seen[graph[i][j]]){
            seen[graph[i][j]]=true;
            if(match[graph[i][j]]<0||check(match[graph[i][j]],seen,match)){
                match[graph[i][j]]=i;
                return true;
            }
        }
    }
    return false;
}

int bpm()
{
    int match[5+n];
    memset(match,-1,sizeof(match));
    int ans=0;
    for(int i=0;i<m;i++){
        bool seen[n+5];
        memset(seen,false,sizeof(seen));
        if(check(i,seen,match))
        ans++;
    }
    return ans;
}

int main()
{
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    int cas=1;
    while (t--){
        for (int i=0;i<1003;i++)
            graph[i].clear();
        cin>>m>>n;
        int a[m][3];
        int b[n][3];
        for (int i=0;i<m;i++) {
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        for (int i=0;i<n;i++) {
            cin>>b[i][0]>>b[i][1]>>b[i][2];
            for (int j=0;j<m;j++){
                int f=1;
                if (fabs(a[j][0]-b[i][0])>12)
                    f=0;
                if (fabs(a[j][1]-b[i][1])>5)
                    f=0;
                if ((a[j][2]^b[i][2])==1)
                    f=0;
                if (f==1)
                    graph[j].push_back(i);
            }
        }
        cout<<"Case "<<cas++<<": "<<bpm()<<endl;
    }
    return 0;
}


