#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node //链表节点结构
{
    int id;
    node* pnext;
} node;

node * pfirst;    //链表首地址
node * ptail;      //链表尾地址

void build(int);    //构建链表
void print(int,int);    //打印结果

int main()
{
    int n,m;
    printf("please input n:");
    scanf("%d",&n);
    printf("please input m:");
    scanf("%d",&m);
    build(n);
    print(n,m);
    return 0;
}
void build(int n)
{
    node *p;
    for(int i=1; i<=n; i++)
    {
        if(i==1)
        {
            pfirst=(node*)malloc(sizeof(node));
            p=pfirst;
        }
        else
        {
            p->pnext=(node*)malloc(sizeof(node));
            p=p->pnext;
        }
        p->id=i;
    }
    ptail=p;
    p->pnext=pfirst;
}
void print(int n,int m)
{
    node * p=pfirst;
    node * t;
    for(int i=0; i<n; i++)
    {
        if(m==1)           //当前遍历到的节点为当前链中首节点，则通过尾节点地址来确定其地址
        {
            m=ptail->pnext->id;
            t=ptail->pnext;
            ptail->pnext=ptail->pnext->pnext;
            p=ptail->pnext;
        }
        else  //依次遍历节点，知道遍历到下一个节点为满足条件的节点，停止遍历
        {
            for(int j=1; j<m-1; j++)
                p=p->pnext;
            m=(p->pnext)->id;
            t=p->pnext;
            if(p->pnext==ptail) ptail=p;
            p->pnext=p->pnext->pnext;
            p=p->pnext;
        }
        printf("%d ",m);  //打印节点信息
        free(t);   //释放该节点内存空间
    }
}
