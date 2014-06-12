#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 0x7fffffff
using namespace std;

typedef struct node
{
    int id;
    int v;
    struct node *pnext;
} edge;

int n,m;
node *v[1000];
void show()
{
    for(int i=1; i<=n; i++)
    {
        node *p=v[i];
        cout << i<<" ";
        for(int j=0; p!=NULL; p=p->pnext)
            cout <<p->id<<" ";
        cout <<endl;
    }
}
int prime(int s)
{
    int dist[1000],vis[1000],sum=0;
    memset(vis,0,sizeof(vis));
    for(int i=0; i<n+1; i++)
        dist[i]=INF;
    node *p=v[s];
    while(p!=NULL)
    {
        dist[p->id]=p->v;
        p=p->pnext;
    }
    vis[s]=1;
    for(int i=1; i<=n; i++)
    {
        int min = INF;
        int id;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j]&&dist[j]<min)
            {
                min = dist[j];
                id=j;
            }
        }
        if(min == INF) break;
        sum+=min;
        vis[id]=1;
        node * p= v[id];
        while(p!=NULL)
        {
            if(dist[p->id]>p->v)
                dist[p->id]=p->v;
            p=p->pnext;
        }
    }
    return sum;
}
int main()
{
    memset(v,0,sizeof(v));
    cout <<"输入顶点数目：";
    cin >> n;
    cout <<"输入边数：";
    cin >> m;
    cout<<"输入各边（格式：顶点，终点，权值）："<<endl;
    for(int i=0; i<m; i++)
    {
        int s,e,val;
        scanf("%d,%d,%d",&s,&e,&val);
        edge *t= new edge;
        t->id=e;
        t->v=val;
        t->pnext=v[s];
        v[s]=t;
    }
    show();
    cout<<prime(1)<<endl;
    return 0;
}
