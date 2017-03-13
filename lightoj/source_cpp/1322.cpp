#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector <int>
#define ll long long int

int mm=0;

vi ins;
vi input;
map < int , int > ma;
map < int , int > fa;

void func()
{
    ll la = 2;
    ll cur=5;
    int pos=0;
    while (ins[pos] == 1){
        pos++;
        ma[1]=2;
        fa[1]=0;
    }
    int flag=0;
    for (int i=2;i<min(mm+1,100000100);i++){
        ll temp = cur;
        cur = (la*i+1);
        if (cur > 10000)
            flag=1;
        cur = cur%10000;
        //cout<<i<<"  "<<cur<<"  "<<la<<endl;
        la=cur;

        while (pos < ins.size() && ins[pos] == i){
            ma[i] = cur;
            fa[i] = flag;
            pos++;
        }
        if (pos >= ins.size())
            break;
    }
}

int main ()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        int foo;
        scanf("%d",&foo);
        input.pb(foo);
        ins.pb(foo);
        mm = max(mm,foo);
    }
    sort(ins.begin(),ins.end());
    func();
    for (int i=1;i<=t;i++){
        if (fa[input[i-1]] == 1)
            printf("Case %d: %04d\n",i,ma[input[i-1]]);
        else
            printf("Case %d: %d\n",i,ma[input[i-1]]);
        //cout<<"Case "<<i<<": "<<ma[input[i-1]]<<endl;
    }
    return 0;
}

