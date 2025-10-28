//排序
//2025.9.24
#include<stdio.h>
//存储结构-记录序列以顺序表存储 
#define MAXSIZE 20	//宏定义，设置顺序表的最大容量为20 
typedef int KeyType;	//给int类型起别名"KeyType"，方便后续统一修改关键字类型，比如改为double，只需double KeyType 

//定义每个数据元素（记录）的结构 
typedef struct{
	KeyType key;	//关键字 
	//InfoType otherinfo;		//其他数据项 ，没有就不填 
} RedType;

//定义顺序表的结构（数据元素1，数据元素2...） 
typedef struct{
	RedType r[MAXSIZE+1]; //r[0]一般不记录元素，而是作哨兵或缓冲区，所以增加一个位置 
	int length;
}SqList;


//插入排序（关键步骤）
/*每一步将待排序对象，按其关键码大小，
插入到前面已经排好序的一组对象的适当位置，直到对象全部插入位置 
类似于摸牌*/

//x=a[i]	//前面0~i-1为有序，i~n-1为无序（总共n个元素）,从第i个元素开始插，赋值给x 
//for(j=i-1;j>=0&&x<a[j];j--)		//拿x在有序序列中从后往前与每个元素进行比较，所以j初始值为i-1,如果a[j]大，a[j]后移一位 
//	a[j+1]=a[j] ;	//后移一位	
//a[j+1]=x;
//
//也可不用x，而是赋值给哨兵
//L.r[0]=L.r[i];
//for(j=i-1;L.r[0].key<L.r[j].key;j--)
//	L.r[j+1]=L.r[j];
//L.r[j+1]=L.r[0];	//插入
//如果待插入元素比有序序列最后一个元素大，就不需要移动 



//算法（直接插入排序）
void InsertSort(SqList &L){		//作用对象：顺序表L，要让排序函数能修改原始的顺序表，需要通过指针传递参数（重点，否则只是修改副本，原顺序表不变）
	int i,j;	//加&用L.r[i].key访问或者加*用L->r[i].key访问 
	for(i=2;i<=L.length;i++){
		if(L.r[i].key<L.r[i-1].key){
			L.r[0]=L.r[i];
			for(j=i-1;L.r[0].key<L.r[j].key;j--){
				L.r[j+1]=L.r[j];
			}
			L.r[j+1]=L.r[0];
		}
	}
}

//打印顺序表（AI） 
void PrintList(SqList L) {
    printf("排序结果: ");
    for(int i = 1; i <= L.length; i++) {
        printf("%d ", L.r[i].key);	//顺序表中的每个数据元素是存放在数组中的，L.r[i].key表示L顺序表中的第i个数据元素的关键字
    }								//因为一个数据元素可能有多个关键字，虽然这里只有一个 
    printf("\n");					//如小明的成绩（数据元素）有语文成绩(key)、数学成绩(key)、英语成绩(key) 
}

// 主函数(AI)
int main() {
    SqList L;
    int n;
    
    printf("请输入要排序的元素个数(不超过%d): ", MAXSIZE);
    scanf("%d", &n);
    
    if(n <= 0 || n > MAXSIZE) {
        printf("输入的元素个数无效!\n");
        return 1;
    }
    
    L.length = n;
    
    printf("请输入%d个整数: ", n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &L.r[i].key);
        //L.r[i].otherinfo.data = 0;  
    }
    InsertSort(L);
    PrintList(L);
    return 0;
}
 






 
 
