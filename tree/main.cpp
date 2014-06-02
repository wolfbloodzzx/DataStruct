#include <iostream>
#include <cstdio>
#include <cstring>
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
void pre(Bitnode*T)
{
    if(T!=NULL)
    {
        cout <<T->v<<' ';
        pre(T->l);
        pre(T->r);
    }
}
void mid(Bitnode*T)
{
    if(T!=NULL)
    {
        mid(T->l);
        cout << T->v<<' ';
        mid(T->r);
    }
}
void hou(Bitnode*T)
{
    if(T!=NULL)
    {
        hou(T->l);
        hou(T->r);
        cout << T->v<<' ';
    }
}
int main()
{
    Bitnode *rt=new Bitnode;
    createBiTree(&rt);
    pre(rt);
    cout << endl;
    mid(rt);
    cout << endl;
    hou(rt);
    return 0;
}
