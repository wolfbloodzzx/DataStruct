#include <iostream>

using namespace std;

int src[10000];
int n;
void BInsertSort(int src[]);
void BubbleSort(int src[]);
void KSort(int src[]);
void GSort(int src[]);
void DSort(int src[]);

int main()
{
    cout << "输入未排序数据个数：";
    cin >> n;
    cout << "输入数据序列："<<endl;
    for(int i=0; i<n; i++)
        cin >> src[i];
//    cout <<"二分插入排序结果："<<endl;
//    BInsertSort(src);
    cout <<"冒泡排序结果："<<endl;
    BubbleSort(src);
    cout <<"快排结果："<<endl;
    KSort(src);
    cout << "归并排序："<<endl;
    GSort(src);
//    cout <<"堆排序："<<endl;
//    DSort(src);
    return 0;
}

void quicksort(int *src,int a,int b)
{
    int key= src[a];
    int i=a,j=b;
    if(a<b)
    {
        while(i<j)
        {
            while(i<j&&src[j]>=key)
                j--;
            if(i<j)
            {
                src[i]=src[j];
                i++;
            }
            while(i<j&&src[i]<=key)
                i++;
            if(i<j)
            {
                src[j]=src[i];
                j--;
            }
        }
        src[j]=key;
        quicksort(src,a,i-1);
        quicksort(src,i+1,b);
    }
}
void mergesort(int *src,int a,int b)
{
    int mid=(a+b)/2;
    if(a<b)
    {
        mergesort(src,a,mid);
        mergesort(src,mid+1,b);
        int i=a,j=mid+1;
        int id=0;
        int temp[10000];
        while(i<=mid&&j<=b)
        {
            if(src[i]>src[j]) temp[id++]=src[j++];
            else temp[id++]=src[i++];
        }
        while(i<=mid)
            temp[id++]=src[i++];
        while(j<=b)
            temp[id++]=src[j++];
        for(int i=a;i<=b;i++)
            src[i]=temp[i-a];
    }
}
void KSort(int src[])
{
    int tmp[10000];
    for(int i=0; i<n; i++)
        tmp[i]=src[i];
    quicksort(tmp,0,n-1);
    for(int i=0; i<n; i++)
        cout << tmp[i]<<" ";
    cout << endl;
}
void BubbleSort(int src[])
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
    cout << endl;
}
void GSort(int src[])
{
    int tmp[10000];
    for(int i=0; i<n; i++)
        tmp[i]=src[i];
    mergesort(tmp,0,n-1);
    for(int i=0; i<n; i++)
        cout << tmp[i]<<" ";
    cout << endl;
}
