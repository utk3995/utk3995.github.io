#include <bits/stdc++.h>
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
    nn->data = 0;
    int i;
    for (i=0;i<4;i++){
        nn->child[i]=NULL;
    }
    return nn;
}

int getidx(char ch)
{
    if (ch=='A')
        return 0;
    else if (ch=='C')
        return 1;
    else if (ch=='G')
        return 2;
    else
        return 3;
}

void nodeinsert(trie *t, char *str)
{
    int i,len=strlen(str);
    node *temp = t->root;
    for (i=0;i<len;i++){
        int idx = getidx(str[i]);
        temp->data = temp->data + 1 ;
        if ((temp->child[idx])!=NULL){
            temp = temp->child[idx];
        }
        else{
            temp->child[idx]=newnode();
            temp = temp->child[idx];
        }
    }
    temp->data = temp->data + 1;
}


void func1(node *n,int level)
{
    int i;
    if (mv < level*(n->data)){
        mv = level*(n->data);
    }
    for (i=0;i<4;i++){
        if ((n->child[i])!=NULL)
            func1(n->child[i],level+1);
    }
}


int main ()
{
    //freopen("input.txt","r",stdin);
    int test;
    cin>>test;
    int tn=1;
    while (test--){
        mv=0;
        trie *t = (trie *)malloc(sizeof(trie));
        t->root = newnode();
        int n;
        cin>>n;
        while (n--){
            char str[51];
            scanf("%s",str);
            nodeinsert(t,str);
        }
        func1(t->root,0);
        cout<<"Case "<<tn++<<": "<<mv<<endl;
    }
    return 0;
}

