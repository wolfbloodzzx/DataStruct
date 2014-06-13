#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STRING 256
typedef struct staff                        //staff结构，用来保存每个员工信息
{
    char name[MAX_STRING];
    char num[MAX_STRING];
    char pos[MAX_STRING];
} staff;
typedef struct table                    //线性表
{
    staff * st;
    int ans;
} table;

table tb;                                       //主线性表，保存员工信息
int N=2;
void showmenu();                    //显示菜单
void AddStaff(staff*);              //添加一个员工信息到线性表
void DelStaff(staff*);                //从线性表中删除一个员工信息
void show();                               //显示线性表中的所有员工信息
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
        case 1:                                     //添加一个员工信息
            getchar();
            printf("Name:");
            gets(t.name);
            printf("Num:");
            gets(t.num);
            printf("Job:");
            gets(t.pos);
            AddStaff(&t);
            break;
        case 2:                                     //删除一个员工信息
            getchar();
            printf("Name:");
            gets(t.name);
            printf("Num:");
            gets(t.num);
            printf("Job:");
            gets(t.pos);
            DelStaff(&t);
            break;
        case 3:                                 //显示信息
            show();
            break;
        case 0:                                //退出程序
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
    if(tb.st==NULL)                                                     //若初次申请内存块（每次申请了N块空间）
        tb.st=(staff*)malloc(sizeof(staff)*N);
    if(tb.ans>=N)                                                           //线性表溢出处理，再次申请
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
            //用name，num，pos分别匹配，若有一个匹配成功，则认为找到，删除节点
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
