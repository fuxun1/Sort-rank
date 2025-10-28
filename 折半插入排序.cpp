//折半插入排序（也就是二分法，把已知有序序列分成两半，待插入元素如果比中间值大，就在右半区找插入位置，反之在左半区找） 
//2025.10.9
#include<stdio.h>

#define MAXSIZE 20
typedef int KeyType;
//定义节点类型 
typedef struct{
	KeyType key;
}RcdType; 
//定义顺序表结构
typedef struct{
	RcdType r[MAXSIZE+1];
	int length;
}SqList; 

//定义折半排序算法
void BinsertSort(SqList &L){
	int i,j;
	int high;
	int low;
	int mid;
	for(i=2;i<=L.length;i++){
		high=i-1;
		low=1; 
		L.r[0]=L.r[i];
		while(low<=high){
			mid=(low+high)/2;
			if(L.r[0].key<L.r[mid].key){
				high=mid-1;
			}else{
				low=mid+1;
			}
		}
		for(j=i-1;j>=high+1;j--){
			L.r[j+1]=L.r[j];
		}
		L.r[high+1]=L.r[0];
	}
} 

//主函数
int main(){
	SqList L;
	int i,n;
	printf("请输入要排序的元素个数：\n");
	scanf("%d",&n);
	L.length=n;
	printf("请输入顺序表（用空格分隔）：");
	for(i=1;i<=n;i++){
		scanf("%d",&L.r[i].key);
	}
	BinsertSort(L);
	printf("排序结果：");
	for(i=1;i<=n;i++){
		printf("%d ",L.r[i].key);
	}
	printf("\n");
	
	return 0;
} 





