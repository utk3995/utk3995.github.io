#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define mp make_pair
#define fr first
#define se second
#define MOD 1000000007


char m[15][15];
int chx[26];
int chy[26];
int to[15][15];
int ans=0;
int n;

int xm[]={0,1,0,-1};
int ym[]={1,0,-1,0};

void clea()
{
    for (int i=0;i<15;i++){
        for (int j=0;j<15;j++){
            to[i][j]=0;
        }
    }
}

bool bfs(int so)
{
    bool ret=false;
    int an=0;
    queue < pair < pair<int,int> , int > > q;
    q.push(mp(mp(chx[so],chy[so]),0));
    to[chx[so]][chy[so]]=1;
    while (!q.empty()){
        pair < pair<int,int> , int > po = q.front();
        q.pop();
        int x=po.fr.fr;
        int y=po.fr.se;
        int w=po.se;
        if (x==chx[so+1] && y==chy[so+1]){
            an=w;
            ret=true;
            break;
        }
        for (int i=0;i<4;i++){
            int nx = x+xm[i];
            int ny = y+ym[i];
            if (nx>=0 && nx<n && ny>=0 && ny<n && m[nx][ny]!='#' && to[nx][ny]==0){
                if (m[nx][ny]=='.'){
                    to[nx][ny]=1;
                    q.push(mp(mp(nx,ny),w+1));
                }
                else if ((m[nx][ny]-'A')<=so+1){
                    to[nx][ny]=1;
                    q.push(mp(mp(nx,ny),w+1));
                }
            }
        }
    }
    if (ret)
        ans+=an;
    return ret;
}


int main ()
{
	//freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    int cas=1;
    while (t--){
        for (int i=0;i<26;i++)
            chx[i]=chy[i]=0;
        cin>>n;
        int co=0;
        ans=0;
        int sx,sy,dx,dy;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cin>>m[i][j];
                if (m[i][j]=='A'){
                    sx=i;
                    sy=j;
                }
                if (m[i][j] >= 'A' && m[i][j] <='Z'){
                    co++;
                    chx[m[i][j]-'A']=i;
                    chy[m[i][j]-'A']=j;
                }
            }
        }
        ans=0;
        bool flag = true;
        for (int i=0;i<co-1;i++){
            clea();
            flag = flag & bfs(i);
        }

        if (flag==false)
            cout<<"Case "<<cas++<<": Impossible"<<endl;
        else
            cout<<"Case "<<cas++<<": "<<ans<<endl;
    }
    return 0;
}

