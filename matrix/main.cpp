#include <iostream>
#include <cstring>
using namespace std;
typedef struct node
{
    int x,y;
    int v;
} node;

typedef struct matrix
{
    int r,c;
    int n;
    node d[10000];
} matrix;

int show[100][100];
void showmenu()
{
    cout << "1、显示矩阵"<<endl;
    cout << "2、转置矩阵"<<endl;
    cout << "0、退出"<<endl;
}
int main()
{
    matrix m;
    while(cin >> m.r >> m.c >>m.n)
    {
        cout <<"输入各个点信息："<<endl;
        for(int i=0; i<m.n; i++)
            cin >>m.d[i].x >>m.d[i].y >>m.d[i].v;
        int cmd,state=1;
        showmenu();
        while(cin >>cmd)
        {
            switch(cmd)
            {
            case 1:
                memset(show,0,sizeof(show));
                for(int i=0; i<m.n; i++)
                    show[m.d[i].x][m.d[i].y]=m.d[i].v;
                for(int i=0; i<m.r; i++)
                {
                    for(int j=0; j<m.c; j++)
                        cout << show[i][j]<<" ";
                    cout <<endl;
                }
                break;
            case 2:
                int t;
                t=m.c;
                m.c=m.r;
                m.r=t;
                for(int i=0; i<m.n; i++)
                {
                    t=m.d[i].x;
                    m.d[i].x=m.d[i].y;
                    m.d[i].y=t;
                }
                break;
            case 0:
                state=0;
            default:
                break;
            }
            if(!state) break;
            else showmenu();
        }
    }
    return 0;
}
