//冒泡排序
//2025.10.16

#include<stdio.h> 
#define MAXSIZE 10
typedef int ElemType;
//定义每个节点（数据元素）的结构
typedef struct{
	ElemType key;
}RedType; 
//定义顺序表结构 
typedef struct{
	RedType r[MAXSIZE+1];
	int length;
}SqList;

//RedType和SqList是抽象数据类型类型，可以像用int定义整数、char定义字符那样用它们定义结点和线性表 
//冒泡排序算法
//n个记录（关键字），最多比较n-1趟，每趟比较n-m次 (核心部分) 
void BubbleSort(SqList &L,int n){
	int temp;
	int m,j;
	for(m=1;m<=n-1;m++){	//m代表轮次 
		for(j=1;j<=n-m;j++){	//每轮排序后，末尾m个元素已排好序（无需再比较），因此内层循环的范围随m增大而缩小
			if(L.r[j].key>L.r[j+1].key){
				//交换 
				temp=L.r[j].key;
				L.r[j].key=L.r[j+1].key;
				L.r[j+1].key=temp;
			}
		}
	} 
}

int main(){
	int n;
	int i;
	SqList L;
	L.length = 0;  // 初始化顺序表长度（规范操作）
	printf("输入要排序的元素个数：\n");
	scanf("%d",&n) ;
	printf("请输入n个记录：\n");
	for(i=1;i<=n;i++){
		scanf("%d",&L.r[i].key);
	}
	BubbleSort(L,n);
	printf("排序结果为:\n");
	for(i=1;i<=n;i++){
		printf("%d ",L.r[i].key);
	}
	printf("\n");
	return 0;
}

/*在原有基础上，还可以提高效率，就是一旦某一趟不出现记录交换，排序结束，已经排好序了 
所以可以增加一个标志，用来判断一趟下来有没有发生记录交换 
void BubbleSort(SqList &L,int n){
	int temp;
	int flag=1; flag作标记,1代表发生了交换，0代表未发生 
	int m,j;
	for(m=1;m<=n-1&&flag;m++){	//如果一趟下来未发生交换，flag=0，不满足循环条件，不再进行下次循环，直接退出 
		flag=0; 
		for(j=1;j<=n-m;j++){
			if(L.r[j].key>L.r[j+1].key){
				//交换 
				flag=1; 
				temp=L.r[j].key;
				L.r[j].key=L.r[j+1].key;
				L.r[j+1].key=temp;
			}
		}
	} 
}
*/ 






