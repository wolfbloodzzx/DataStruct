#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STRING 256
typedef struct staff                        //staff�ṹ����������ÿ��Ա����Ϣ
{
    char name[MAX_STRING];
    char num[MAX_STRING];
    char pos[MAX_STRING];
} staff;
typedef struct table                    //���Ա�
{
    staff * st;
    int ans;
} table;

table tb;                                       //�����Ա�����Ա����Ϣ
int N=2;
void showmenu();                    //��ʾ�˵�
void AddStaff(staff*);              //���һ��Ա����Ϣ�����Ա�
void DelStaff(staff*);                //�����Ա���ɾ��һ��Ա����Ϣ
void show();                               //��ʾ���Ա��е�����Ա����Ϣ
int main()
{
    tb.ans=0;
    tb.st=NULL;
    showmenu();
    int i,state=0;
    while(1)
    {
        printf("Input your choice:");
        scanf("%d",&i);
        staff t;
        switch(i)
        {
        case 1:                                     //���һ��Ա����Ϣ
            getchar();
            printf("Name:");
            gets(t.name);
            printf("Num:");
            gets(t.num);
            printf("Job:");
            gets(t.pos);
            AddStaff(&t);
            break;
        case 2:                                     //ɾ��һ��Ա����Ϣ
            getchar();
            printf("Name:");
            gets(t.name);
            printf("Num:");
            gets(t.num);
            printf("Job:");
            gets(t.pos);
            DelStaff(&t);
            break;
        case 3:                                 //��ʾ��Ϣ
            show();
            break;
        case 0:                                //�˳�����
            state=1;
            break;
        default:
            break;
        }
        if(state==1) break;
    }
    free(tb.st);
    return 0;
}

void showmenu()
{
    printf("1.Add a new staff\n");
    printf("2.Del a staff\n");
    printf("3.Show all staffs\n");
    printf("0.Exit\n");
}
void AddStaff(staff *t)
{
    if(tb.st==NULL)                                                     //�����������ڴ�飨ÿ��������N��ռ䣩
        tb.st=(staff*)malloc(sizeof(staff)*N);
    if(tb.ans>=N)                                                           //���Ա���������ٴ�����
    {
        N+=5;
        tb.st=(staff*)realloc(tb.st,sizeof(staff)*N);
    }
    tb.st[tb.ans]=*t;
    tb.ans++;
}

void DelStaff(staff * t)
{
    int state=0;
    for(int i=0; i<tb.ans; i++)
    {
        if(state==0)
        {
            //��name��num��pos�ֱ�ƥ�䣬����һ��ƥ��ɹ�������Ϊ�ҵ���ɾ���ڵ�
            if(!strcmp(tb.st[i].name,t->name)||!strcmp(tb.st[i].num,t->num)||!strcmp(tb.st[i].pos,t->num))
                state=1;
        }
        else
            tb.st[i-1]=tb.st[i];
    }
    if(state==1) tb.ans--;
}
void show()
{
    printf("------------------------\n");
    for(int i=0; i<tb.ans; i++)
    {
        printf("Name:%s\n",tb.st[i].name);
        printf("Num:%s\n",tb.st[i].num);
        printf("Job:%s\n",tb.st[i].pos);
        printf("------------------------\n");
    }
}
