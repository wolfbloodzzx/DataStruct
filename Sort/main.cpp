#include <iostream>

using namespace std;

int src[10000];

void BInsertSort(int src[]);
void BubbleSort(int src[],int n);
void KSort(int src[]);
void GSort(int src[]);
void DSort(int src[]);

int main()
{
    cout << "����δ�������ݸ�����";
    int n;
    cin >> n;
    cout << "�����������У�"<<endl;
    for(int i=0; i<n; i++)
        cin >> src[i];
//    cout <<"���ֲ�����������"<<endl;
//    BInsertSort(src);
    cout <<"ð����������"<<endl;
    BubbleSort(src,n);
//    cout <<"���Ž����"<<endl;
//    KSort(src);
//    cout << "�鲢����"<<endl;
//    GSort(src);
//    cout <<"������"<<endl;
//    DSort(src);
    return 0;
}

void quicksort(int *s,int a,int b);
{
    int key=a;
    int i=a,j=b-1;
    while(i!=j&&i<=b&&j>=a)
    {
        while(s[key]<s[i]&&i<b) i++;

    }
}
void BubbleSort(int src[],int n)
{
    int tmp[10000];
    for(int i=0; i<n; i++)
        tmp[i]=src[i];
    for(int i=0; i<n; i++)
        for(int j=0; j<n-i-1; j++)
        {
            if(tmp[j]>tmp[j+1])
            {
                int t=tmp[j];
                tmp[j]=tmp[j+1];
                tmp[j+1]=t;
            }
        }
    for(int i=0; i<n; i++)
        cout << tmp[i]<<" ";
}
