#include <iostream>
#include <queue>
#include <vector>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdio>
#define MAX_CAR 100
#define S_PRICE (1/60)
using namespace std;

struct car
{
    time_t s_hour;
    int id;
    char num[256];
};

queue <car> wait_car;
queue <int> park_pos;
vector <car> parking_car;

void init();
void showmenu();
void addcar(char*);
void delcar(char*);
string format_time(time_t);
void show();

int main()
{
    showmenu();
    int c;
    char num[256];
    init();
    while(cin>>c)
    {
        switch(c)
        {
        case 1:
            cout << "�����복�ƣ�";
            cin >> num;
            addcar(num);
            break;
        case 2:
            cout << "�����복�ƣ�";
            cin >> num;
            delcar(num);
            break;
        case 3:
            show();
            break;
        case 0:
            return 0;
            break;
        default:
            break;
        }
        showmenu();
    }
    return 0;
}
void showmenu()
{
    cout <<"----------Welcome-----------" <<endl;
    cout <<"1.����һ����" <<endl;
    cout <<"2.�뿪һ����" <<endl;
    cout <<"3.��ʾ��ǰͣ����״̬" <<endl;
    cout <<"4.�˳�����" <<endl;
    cout <<"----------------------------" <<endl;
}
void init()
{
    for(int i=1; i<=MAX_CAR; i++)
        park_pos.push(i);
}
void addcar(char* num)
{
    car temp;
    strcpy(temp.num,num);
    if(!park_pos.size())
        wait_car.push(temp);
    else
    {
        temp.s_hour=time(0);
        temp.id=park_pos.front();
        parking_car.push_back(temp);
        park_pos.pop();
    }
}
void delcar(char* num)
{
    bool state=false;
    for(int i=0; i<parking_car.size(); i++)
        if(!strcmp(num,parking_car[i].num))
        {
            time_t t=time(0)-parking_car[i].s_hour;
            cout <<"����"<<format_time(parking_car[i].s_hour)<<"ͣ��"<<format_time(time(0))<<endl;
            printf("����Ҫ�ɷ�%.2lfԪ\n",(double)t*S_PRICE);
            park_pos.push(parking_car[i].id);
            parking_car.erase(parking_car.begin()+i);
            state=true;
            break;
        }
    if(!state)
        cout <<"��������ͣ������"<<endl;
    else if(!wait_car.empty())
    {
        wait_car.front().s_hour=time(0);
        wait_car.front().id=park_pos.front();
        parking_car.push_back(wait_car.front());
        park_pos.pop();
    }
}

void show()
{
    for(int i=0; i<parking_car.size(); i++)
        cout <<parking_car[i].num<<"��ͣ��"<<parking_car[i].id<<"ͣ��λ"<<endl;
}
string format_time(time_t timeData)
{
    string strDateStr;
    char chTmp[50];
    memset(chTmp,0,sizeof(chTmp));

    struct tm *p;
    p = localtime(&timeData);

    p->tm_year = p->tm_year + 1900;

    p->tm_mon = p->tm_mon + 1;

    snprintf(chTmp,sizeof(chTmp),"%04d-%02d-%02d %d:%d",
        p->tm_year, p->tm_mon, p->tm_mday,p->tm_hour,p->tm_min);

    strDateStr = chTmp;
    return strDateStr;
}
