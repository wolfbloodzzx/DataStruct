#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int map[1000][1000];

typedef struct node
{
    int id;
    struct node *pnext;
} edge;

int n,m;
node *v[1000];
int vis1[1000];
int vis2[1000];
void dfs1(int nn)
{
    vis1[nn]=1;
    cout << nn<<" ";
    node* p=v[nn];
    while(p!=NULL)
    {
        if(!vis1[p->id])
            dfs1(p->id);
        p=p->pnext;
    }
}
void dfs2(int nn)
{
    vis2[nn]=1;
    cout <<nn<<" ";
    for(int i=1;i<=n;i++)
        if(map[nn][i]&&!vis2[i]) dfs2(i);
}
int main()
{
    memset(v,0,sizeof(v));
    memset(vis1,0,sizeof(vis1));
    memset(vis2,0,sizeof(vis2));
    memset(map,0,sizeof(map));
    cout <<"���붥����Ŀ��";
    cin >> n;
    cout <<"���������";
    cin >> m;
    cout<<"������ߣ���ʽ�����㣬�յ㣩��"<<endl;
    for(int i=0; i<m; i++)
    {
        int s,e;
        scanf("%d,%d",&s,&e);
        edge *t= new edge;
        t->id=e;
        t->pnext=v[s];
        v[s]=t;
        map[s][e]=1;
    }
    cout << "DFS�ڽӱ��������"<<endl;
    dfs1(1);
    cout << endl;
    cout << "DFS�ڽӾ����������"<<endl;
    dfs2(1);
    cout << endl;
    return 0;
}
