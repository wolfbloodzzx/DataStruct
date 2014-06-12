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
    cout << "输入未排序数据个数：";
    int n;
    cin >> n;
    cout << "输入数据序列："<<endl;
    for(int i=0; i<n; i++)
        cin >> src[i];
//    cout <<"二分插入排序结果："<<endl;
//    BInsertSort(src);
    cout <<"冒泡排序结果："<<endl;
    BubbleSort(src,n);
//    cout <<"快排结果："<<endl;
//    KSort(src);
//    cout << "归并排序："<<endl;
//    GSort(src);
//    cout <<"堆排序："<<endl;
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
