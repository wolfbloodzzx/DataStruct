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
    cout << "���쵽�ĺ���Ϊ"<<++count<<endl;
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
                cout << "������1�Ŵ��ڰ���ҵ��"<<endl;
                isbusy[1]=1;
                people[1]=count;
            }
            else
            {
                cout <<"��������Ϣ���ȴ�"<<endl;
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
                    cout <<"������"<<id<<"�Ŵ��ڰ���ҵ��"<<endl;
                    break;
                }
            if(id==-1)
            {
                cout <<"��������Ϣ���ȴ�"<<endl;
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
                    cout <<"������"<<id<<"�Ŵ��ڰ���ҵ��"<<endl;
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
                        cout <<"������"<<id<<"�Ŵ��ڰ���ҵ��"<<endl;
                        break;
                    }
            if(id==-1)
            {
                cout <<"��������Ϣ���ȴ�"<<endl;
                t2.push(count);
            }
            break;
        case 4:
            cout << "���������ĺ���"<<endl;
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
                    cout << i<<"����"<<people[i]<<"�ſͻ����ڰ���ҵ��"<<endl;
                else
                    cout << i<<"���ڵ�ǰ����"<<endl;
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
    cout << "1.��������"<<endl;
    cout << "2.�������п�"<<endl;
    cout << "3.������ƿ�"<<endl;
    cout << "4.ҵ�����"<<endl;
    cout << "5.��ʾ��ǰ����״̬"<<endl;
    cout << "0.�뿪����"<<endl;
    cout <<"------------------------------"<<endl;
}
