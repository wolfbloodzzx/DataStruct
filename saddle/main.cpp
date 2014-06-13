#include <iostream>

using namespace std;

int num[1000][1000];
int imin[1000];
int jmax[1000];
int main()
{
    int r,c;
    while(cin >> r>>c&&r!=0&&c!=0)
    {
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
            {
                cin >> num[i][j];
                if(j==0) imin[i]=0;
                else imin[i]=num[i][imin[i]]>num[i][j]?j:imin[i];
                if(i==0) jmax[j]=0;
                else jmax[j]=num[jmax[j]][j]>num[i][j]?jmax[j]:i;
            }
        int state=0;
        for(int i=0; i<r; i++)
            if(jmax[imin[i]]==i)
            {
                cout <<"a["<<jmax[imin[i]]<<"]["<<imin[i]<<"]="<<num[jmax[imin[i]]][imin[i]]<<endl;
                state=1;
            }
        if(state==0) cout <<"none"<<endl;
    }
    return 0;
}
