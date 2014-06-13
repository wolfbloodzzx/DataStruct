#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node //����ڵ�ṹ
{
    int id;
    node* pnext;
} node;

node * pfirst;    //�����׵�ַ
node * ptail;      //����β��ַ

void build(int);    //��������
void print(int,int);    //��ӡ���

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
        if(m==1)           //��ǰ�������Ľڵ�Ϊ��ǰ�����׽ڵ㣬��ͨ��β�ڵ��ַ��ȷ�����ַ
        {
            m=ptail->pnext->id;
            t=ptail->pnext;
            ptail->pnext=ptail->pnext->pnext;
            p=ptail->pnext;
        }
        else  //���α����ڵ㣬֪����������һ���ڵ�Ϊ���������Ľڵ㣬ֹͣ����
        {
            for(int j=1; j<m-1; j++)
                p=p->pnext;
            m=(p->pnext)->id;
            t=p->pnext;
            if(p->pnext==ptail) ptail=p;
            p->pnext=p->pnext->pnext;
            p=p->pnext;
        }
        printf("%d ",m);  //��ӡ�ڵ���Ϣ
        free(t);   //�ͷŸýڵ��ڴ�ռ�
    }
}
