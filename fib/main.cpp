#include <iostream>

using namespace std;
typedef long long LL;

typedef struct
{
    int head;
    int tail;
    int count;
    LL data[4];
} circleque;

void init(circleque*);
bool push(circleque*,int);
bool pop(circleque*);
int fib();

int main()
{
    cout << fib()<<endl;
    return 0;
}
void init(circleque* c)
{
    c->head=c->tail=c->count=0;
}
bool push(circleque* c,int d)
{
    if(c->count==4) return false;
    else
    {
        c->data[c->tail]=d;
        c->tail=(c->tail+1)%4;
        c->count++;
    }
    return true;
}
bool pop(circleque*c)
{
    if(c->count==0) return false;
    else
    {
        c->head=(c->count+1)%4;
        c->count--;
    }
    return true;
}
int fib()
{
    circleque c;
    LL d;
    init(&c);
    push(&c,0);
    push(&c,0);
    push(&c,0);
    push(&c,1);
    for(int i=4;; i++)
    {
        d=0;
        for(int j=0; j<4; j++)
            d+=(c.data[j]);
        pop(&c);
        push(&c,d);
        if(d>200&&c.data[(c.head+3)%4]<=200)
            return i;
    }
}
