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
void pre(Bitree T)          //先序遍历
{
    stack<Bitree> q;
    Bitree t=T;
    while(!q.empty()||t!=NULL)
    {
        while(t!=NULL)
        {
            q.push(t);
            cout <<t->v<< ' ';
            t=t->l;
        }
        t=q.top();
        q.pop();
        t=t->r;
    }
}
void mid(Bitree T)          //中序遍历
{
    stack<Bitree> q;
    Bitree t=T;
    while(!q.empty()||t!=NULL)
    {
        while(t!=NULL)
        {
            q.push(t);
            t=t->l;
        }
        t=q.top();
        cout <<t->v<<' ';
        q.pop();
        t=t->r;
    }
}

void cengci(Bitree T)           //层次遍历
{
    queue<Bitree> q;
    Bitree t;
    q.push(T);
    while(!q.empty())
    {
        t=q.front();
        if(t->l!=NULL) q.push(t->l);
        if(t->r!=NULL) q.push(t->r);
        cout << t->v<<' ';
        q.pop();
    }
}

int main()
{
    Bitree rt= new Bitnode;
    createBiTree(&rt);
    pre(rt);
    cout << endl;
    mid(rt);
    cout << endl;
    cengci(rt);
    return 0;
}
