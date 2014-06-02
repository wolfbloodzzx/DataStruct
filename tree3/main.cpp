#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

typedef struct Bitnode
{
    char v;
    Bitnode *l,*r;
} Bitnode,* Bitree;

void createBiTree(Bitree *T)
{
    char c=getchar();
    if(c!='.')
    {
        (*T)=new Bitnode;
        (*T)->v=c;
        createBiTree(&(*T)->l);
        createBiTree(&(*T)->r);
    }
    else
        (*T)=NULL;
}

int deep(Bitree T)
{
    int dl,dr;
    if(T==NULL) return 0;
    dl=deep(T->r);
    dr=deep(T->l);
    return dl>dr?dl+1:dr+1;
}
int main()
{
    Bitree rt;
    createBiTree(&rt);
    cout <<deep(rt)<<endl;
    return 0;
}
