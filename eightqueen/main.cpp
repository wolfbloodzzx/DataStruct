#include <iostream>
#include <cstring>

using namespace std;
int map[64];
int ans=0;
void dfs(int);
bool pan(int ,int);

int main()
{
    memset(map,0,sizeof(map));
    dfs(0);
    cout << ans<<endl;
    return 0;
}
void dfs(int n)
{
    if(n==8)
    {
        ans++;
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
                cout << map[i*8+j]<<" ";
            cout <<endl;
        }
        cout << "----------------"<<endl;
        return;
    }
    for(int i=0; i<8; i++)
    {
        if(pan(n,i))
        {
            map[n*8+i]=1;
            dfs(n+1);
            map[n*8+i]=0;
        }
    }
}
bool pan(int x,int y)
{
    for(int i=0; i<x; i++)
        if(map[i*8+y]==1) return false;
    for(int j=0; j<y; j++)
        if(map[x*8+j]==1) return false;
    int xx=x,yy=y;
    while(xx>=0&&yy>=0)
        if(map[xx*8+yy]==1) return false;
        else
        {
            xx--;
            yy--;
        }
    xx=x;
    yy=y;
    while(xx>=0&&yy<8)
        if(map[xx*8+yy]==1) return false;
        else
        {
            xx--;
            yy++;
        }
    return true;
}
