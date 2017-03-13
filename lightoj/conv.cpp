#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.cpp","r",stdin);
    freopen("output.cpp","w",stdout);
    char ch;
    while (scanf("%c",&ch)!=EOF){
        if (ch=='>')
            cout<<"&gt;";
        else if (ch=='<')
            cout<<"&lt;";
        else if (ch=='\'')
            cout<<"&apos;";
        else
            cout<<ch;
    }
    return 0;
}
