#include&lt;bits/stdc++.h&gt;
using namespace std;

#define ll long long int
#define pii pair&lt;int,int&gt;
#define pll pair&lt;ll,ll&gt;
#define vi vector&lt;int&gt;
#define vl vector&lt;ll&gt;
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
    for (int i=0;i&lt;15;i++){
        for (int j=0;j&lt;15;j++){
            to[i][j]=0;
        }
    }
}

bool bfs(int so)
{
    bool ret=false;
    int an=0;
    queue &lt; pair &lt; pair&lt;int,int&gt; , int &gt; &gt; q;
    q.push(mp(mp(chx[so],chy[so]),0));
    to[chx[so]][chy[so]]=1;
    while (!q.empty()){
        pair &lt; pair&lt;int,int&gt; , int &gt; po = q.front();
        q.pop();
        int x=po.fr.fr;
        int y=po.fr.se;
        int w=po.se;
        if (x==chx[so+1] && y==chy[so+1]){
            an=w;
            ret=true;
            break;
        }
        for (int i=0;i&lt;4;i++){
            int nx = x+xm[i];
            int ny = y+ym[i];
            if (nx&gt;=0 && nx&lt;n && ny&gt;=0 && ny&lt;n && m[nx][ny]!=&apos;#&apos; && to[nx][ny]==0){
                if (m[nx][ny]==&apos;.&apos;){
                    to[nx][ny]=1;
                    q.push(mp(mp(nx,ny),w+1));
                }
                else if ((m[nx][ny]-&apos;A&apos;)&lt;=so+1){
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
    cin&gt;&gt;t;
    int cas=1;
    while (t--){
        for (int i=0;i&lt;26;i++)
            chx[i]=chy[i]=0;
        cin&gt;&gt;n;
        int co=0;
        ans=0;
        int sx,sy,dx,dy;
        for (int i=0;i&lt;n;i++){
            for (int j=0;j&lt;n;j++){
                cin&gt;&gt;m[i][j];
                if (m[i][j]==&apos;A&apos;){
                    sx=i;
                    sy=j;
                }
                if (m[i][j] &gt;= &apos;A&apos; && m[i][j] &lt;=&apos;Z&apos;){
                    co++;
                    chx[m[i][j]-&apos;A&apos;]=i;
                    chy[m[i][j]-&apos;A&apos;]=j;
                }
            }
        }
        ans=0;
        bool flag = true;
        for (int i=0;i&lt;co-1;i++){
            clea();
            flag = flag & bfs(i);
        }

        if (flag==false)
            cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;": Impossible"&lt;&lt;endl;
        else
            cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;": "&lt;&lt;ans&lt;&lt;endl;
    }
    return 0;
}

