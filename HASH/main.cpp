#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string hashtable[11];
int empty[11];
int hash(const char* s)
{
    int l=strlen(s);
    int sum=0;
    for(int i=0; i<l; i++)
        sum+=s[i];
    int h=sum%11,d=1;
    while(empty[h])
    {
        h=(h+d)%11;
        d++;
    }
    return h;
}
bool search(const char* s)
{
    int l=strlen(s);
    int v[11];
    memset(v,0,sizeof(v));
    int sum=0;
    for(int i=0; i<l; i++)
        sum+=s[i];
    int h=sum%11,d=1;
    while(!v[h])
    {
        if(!empty[h]) return false;
        else if(!strcmp(s,hashtable[h].data())) return true;
        else
        {
            d++;
            h=(h+d)%11;
        }
    }
    return false;
}
int main()
{
    memset(empty,0,sizeof(empty));
    int n;
    string key;
    cout << "�����¼������";
    cin >> n;
    cout<< "�����¼��"<<endl;
    for(int i=0; i<n&&i<11; i++)
    {
        cin >>key;
        hashtable[hash(key.data())]=key;
//        cout <<key<<hashtable[hash(key.data())]<<endl;
        empty[hash(key.data())]=1;
    }
    cout << "HASH�������"<<endl;
    while(1)
    {
        cout << "����������ݣ�";
        cin >> key;
        if(search(key.data()))
            cout << "���ڱ�������"<<endl;
        else
            cout << "δ�ҵ���������"<<endl;
    }
    return 0;
}
