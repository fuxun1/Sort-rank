//大根堆堆排序
#include<iostream>
using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0
typedef int Status;

//自定义记录类型
typedef struct{
    int key;
}RedType;

//顺序表
typedef struct{
    RedType* r; //r指向数组基地址
    int length;
}SqTable;

typedef SqTable HeapType;

Status InitSqTable(HeapType &H){
    H.r=new RedType[MAXSIZE+1]; //0号位置不存元素
    if(!H.r){
        cout<<"内存分配失败"<<endl;
        return ERROR;
    }
    H.length=0;
    cout<<"内存分配成功"<<endl;
    return OK;
}

//筛选的调整过程
void HeapAdjust(HeapType &H,int s,int m){   //s是待调整节点下标,m是最后一个元素下标
    RedType rc=H.r[s];
    for(int j=2*s;j<=m;j*=2){
        if(j<m&&H.r[j].key<H.r[j+1].key){
            ++j;
        }
        if(rc.key>=H.r[j].key) break;
        H.r[s]=H.r[j];
        s=j;
    }
    //回移筛选下来的记录
    H.r[s]=rc;
}

//辅助函数:交换根节点和最后一个叶子结点
void swap(RedType &a,RedType &b){
    RedType temp;
    temp=a;
    a=b;
    b=temp;
}

//堆排序
void HeapSort(HeapType &H){
    //对顺序表H进行堆排序
    for(int i=H.length/2;i>0;--i){
        HeapAdjust(H,i,H.length);
    }

    for(int i=H.length;i>1;--i){
        swap(H.r[1],H.r[i]);
        HeapAdjust(H,1,i-1);    //将剩下的i-1个结点重新调整为大根堆
    }
}

int main(){
    HeapType H;
    InitSqTable(H);
    int n;
    cout<<"请输入元素个数:"<<endl;
    cin>>n;
    H.length=n;
    cout<<"请输入这"<<n<<"个元素:"<<endl;
    for(int i=1;i<=H.length;++i){
        cin>>H.r[i].key;
    }
    HeapSort(H);
    cout<<"堆排序结果为:"<<endl;
    for(int i=1;i<=H.length;++i){
        cout<<H.r[i].key<<" ";
    }

    return 0;
}


