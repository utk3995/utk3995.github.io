#include &lt;bits/stdc++.h&gt;
using namespace std;

typedef struct node
{
    int data; //this is only to check if the node is a leaf node or not
    node *child[4];
}node;

typedef struct trie
{
    node *root;
}trie;

int mv=0;

struct node *newnode()
{
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn-&gt;data = 0;
    int i;
    for (i=0;i&lt;4;i++){
        nn-&gt;child[i]=NULL;
    }
    return nn;
}

int getidx(char ch)
{
    if (ch==&apos;A&apos;)
        return 0;
    else if (ch==&apos;C&apos;)
        return 1;
    else if (ch==&apos;G&apos;)
        return 2;
    else
        return 3;
}

void nodeinsert(trie *t, char *str)
{
    int i,len=strlen(str);
    node *temp = t-&gt;root;
    for (i=0;i&lt;len;i++){
        int idx = getidx(str[i]);
        temp-&gt;data = temp-&gt;data + 1 ;
        if ((temp-&gt;child[idx])!=NULL){
            temp = temp-&gt;child[idx];
        }
        else{
            temp-&gt;child[idx]=newnode();
            temp = temp-&gt;child[idx];
        }
    }
    temp-&gt;data = temp-&gt;data + 1;
}


void func1(node *n,int level)
{
    int i;
    if (mv &lt; level*(n-&gt;data)){
        mv = level*(n-&gt;data);
    }
    for (i=0;i&lt;4;i++){
        if ((n-&gt;child[i])!=NULL)
            func1(n-&gt;child[i],level+1);
    }
}


int main ()
{
    //freopen("input.txt","r",stdin);
    int test;
    cin&gt;&gt;test;
    int tn=1;
    while (test--){
        mv=0;
        trie *t = (trie *)malloc(sizeof(trie));
        t-&gt;root = newnode();
        int n;
        cin&gt;&gt;n;
        while (n--){
            char str[51];
            scanf("%s",str);
            nodeinsert(t,str);
        }
        func1(t-&gt;root,0);
        cout&lt;&lt;"Case "&lt;&lt;tn++&lt;&lt;": "&lt;&lt;mv&lt;&lt;endl;
    }
    return 0;
}

