#include <bits/stdc++.h>
using namespace std;

vector<int>graph[1003];
int n,m;
map <int,int> ma;

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
    int match[n+3+m];
    memset(match,-1,sizeof(match));
    int ans=0;
    for(int i=0;i<n;i++){
        bool seen[n+m+5];
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
        cin>>n;
        int a[n];
        for (int i=0;i<n;i++) {
            cin>>a[i];
        }
        cin>>m;
        int b[m];
        for (int i=0;i<m;i++){
            cin>>b[i];
            for (int j=0;j<n;j++){
                if (b[i]%a[j]==0)
                    graph[j].push_back(n+i);
            }
        }
        /*for (int i=0;i<n;i++){
            cout<<a[i]<<" : ";
            for (int j=0;j<graph[i].size();j++){
                cout<<graph[i][j]<<"  ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;*/
        cout<<"Case "<<cas++<<": "<<bpm()<<endl;
    }
    return 0;
}

//graph[i].push_back(j);
//cout<<bpm()<<endl;

