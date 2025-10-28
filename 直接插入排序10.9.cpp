//插入排序——直接插入排序
//2025.10.9
//本章讨论的所有排序算法一律以下列顺序表为操作对象

#include<stdio.h>

#define MAXSIZE 20
typedef int KeyType;

//结点结构（数据类型） 
typedef struct{
	KeyType key;
}RcdType;

//顺序表结构（数据类型） 
typedef struct{
	RcdType r[MAXSIZE+1];
	int length;
}SqList; 
//核心部分 
void InsertSort(SqList &L){
	int i,j;
	for(i=2;i<=L.length;i++){
			L.r[0].key=L.r[i].key;	//把待排序的关键字赋值给哨兵 
			for(j=i-1;L.r[0].key<L.r[j].key;j--){
				L.r[j+1]=L.r[j];	//后移 
			}
			L.r[j+1]=L.r[0];
	}
	
}

int main(){
	SqList L;
	int i,n;
	printf("请输入要排序的元素个数：");
	scanf("%d",&n);
	L.length=n; 
	printf("请输入顺序表：");
	for(i=1;i<=n;i++){
		scanf("%d",&L.r[i].key);
	}
	//传的是指针，直接就把顺序表修改了，不用再额外接收 
	InsertSort(L);	//c语言中可用指针传递，c++中可直接用引用 
	for(i=1;i<=L.length;i++){
		printf("%d ",L.r[i].key);
	}
	printf("\n");
	
	return 0;
} 

/*性能分析：
	最好的情况：关键字在记录序列中顺序有序（n个元素）：
		比较次数：n-1;移动次数：0 
	最坏的情况：关键字在记录序列中逆序有序（n个元素）：
		第n个元素比较n-1次，所以总的比较次数：1+2+3+...+n-1=(n-1)n/2;
		如果包含哨兵的比较次数，就是（n+2)(n-1)/2次，对应移动次数为1/4*(n+6)*(n-1) */
		



 
