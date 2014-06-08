#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
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
void bfs1(int nn)
{
    queue<int> q;
    node * p;
    vis1[nn]=1;
    cout << nn<<" ";
    q.push(nn);
    while(!q.empty())
    {
        p=v[q.front()];
        while(p!=NULL)
        {
            if(!vis1[p->id])
            {
                cout << p->id<<" ";
                q.push(p->id);
                vis1[p->id]=1;
            }
            p=p->pnext;
        }
        q.pop();
    }
}
void bfs2(int nn)
{
    queue<int> q;
    q.push(nn);
    vis2[nn]=1;
    cout << nn<<" ";
    while(!q.empty())
    {
        int t=q.front();
        for(int i=1;i<=n;i++)
        {
            if(!vis2[i]&&map[t][i]==1)
            {
                q.push(i);
                cout <<i<<" ";
                vis2[i]=1;
            }
        }
        q.pop();
    }
}
int main()
{
    memset(v,0,sizeof(v));
    memset(vis1,0,sizeof(vis1));
    memset(vis2,0,sizeof(vis2));
    memset(map,0,sizeof(map));
    cout <<"输入顶点数目：";
    cin >> n;
    cout <<"输入边数：";
    cin >> m;
    cout<<"输入各边（格式：顶点，终点）："<<endl;
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
    cout << "DFS邻接表遍历序列"<<endl;
    bfs1(1);
    cout << endl;
    cout << "DFS邻接矩阵遍历序列"<<endl;
    bfs2(1);
    cout << endl;
    return 0;
}
