#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int count =0;
int isbusy[7];
int people[7];

queue<int> t1;
queue<int> t2;
queue<int> t3;


void showmenu();
void addhao()
{
    cout << "您领到的号码为"<<++count<<endl;
}

int main()
{
    memset(isbusy,0,sizeof(isbusy));
    cout << "------Welcome To Our Bank------"<<endl;
    showmenu();
    int cmd;
    while(cin >> cmd)
    {
        int id=-1;
        switch(cmd)
        {
        case 1:
            addhao();
            if(!isbusy[1])
            {
                cout << "请您到1号窗口办理业务"<<endl;
                isbusy[1]=1;
                people[1]=count;
            }
            else
            {
                cout <<"请您在休息区等待"<<endl;
                t1.push(count);
            }
            break;
        case 2:
            addhao();
            for(int i=2; i<=4; i++)
                if(!isbusy[i])
                {
                    id=i;
                    isbusy[id]=1;
                    people[id]=count;
                    cout <<"请您到"<<id<<"号窗口办理业务"<<endl;
                    break;
                }
            if(id==-1)
            {
                cout <<"请您在休息区等待"<<endl;
                t2.push(count);
            }
            break;
        case 3:
            addhao();
            id=-1;
            for(int j=5; j<=6; j++)
            {
                if(!isbusy[j])
                {
                    id=j;
                    isbusy[id]=1;
                    people[id]=count;
                    cout <<"请您到"<<id<<"号窗口办理业务"<<endl;
                    break;
                }
            }
            if(id==-1)
                for(int i=2; i<=4; i++)
                    if(!isbusy[i])
                    {
                        id=i;
                        isbusy[id]=1;
                        people[id]=count;
                        cout <<"请您到"<<id<<"号窗口办理业务"<<endl;
                        break;
                    }
            if(id==-1)
            {
                cout <<"请您在休息区等待"<<endl;
                t2.push(count);
            }
            break;
        case 4:
            cout << "请输入您的号码"<<endl;
            cin >> id;
            for(int i=0;i<7;i++)
            {
                if(people[i]==id)
                {
                    isbusy[i]=0;
                    if(i==1)
                    {
                        if(t1.size()==0) break;
                        people[i]=t1.front();
                        isbusy[i]=1;
                    }
                    else if(i>=2&&i<=4)
                    {
                        if(t2.size()==0&&t3.size()==0) break;
                        if(t2.size()!=0)
                        {
                            people[i]=t2.front();
                            isbusy[i]=1;
                        }
                        else if(t3.size()!=0)
                        {
                            people[i]=t3.front();
                            isbusy[i]=1;
                        }
                    }
                    else if(i>=5&&i<=6)
                         {
                        if(t3.size()==0) break;
                        people[i]=t3.front();
                        isbusy[i]=1;
                    }
                }
            }
            break;
        case 5:
            for(int i=1;i<=6;i++)
            {
                if(isbusy[i])
                    cout << i<<"窗口"<<people[i]<<"号客户正在办理业务"<<endl;
                else
                    cout << i<<"窗口当前空闲"<<endl;
            }
            break;
        case 0:
            return 0;
            break;
        }
        showmenu();
    }
    return 0;
}
void showmenu()
{
    cout <<"-----------------------------"<<endl;
    cout << "1.办理公积金"<<endl;
    cout << "2.办理银行卡"<<endl;
    cout << "3.办理理财卡"<<endl;
    cout << "4.业务完成"<<endl;
    cout << "5.显示当前窗口状态"<<endl;
    cout << "0.离开银行"<<endl;
    cout <<"------------------------------"<<endl;
}
