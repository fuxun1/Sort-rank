//选择排序——简单选择排序 
//2025.10.19

#include<stdio.h>

#define MAXSIZE 10
typedef int ElemType;
//顺序表数据结构 
typedef struct{
	int key;
}RedType;

typedef struct{
	RedType r[MAXSIZE+1];
	int length;
}SqList;

void SelectSort(SqList &L){
	int i,temp;
	int n,j,k;
	n=L.length;
	for(i=1;i<=n;i++){
		k=i;	//利用k记录当前最小值位置 
		for(j=i+1;j<=n;j++){
		if(L.r[j].key<L.r[k].key){
			k=j;
		}

		}
	if(k!=i){
		temp=L.r[k].key;
		L.r[k].key=L.r[i].key;
		L.r[i].key=temp;
		}		
	}
	return;		
} 

int main(){
	SqList L;
	int n;
	printf("请输入要排序元素个数:");
	scanf("%d",&n);
	L.length=n;
	printf("请输入%d个元素（空格分隔）:\n",n);
	for(int i=1;i<=L.length;i++){
		scanf("%d",&L.r[i].key);
	}
	
	SelectSort(L);
	printf("排序结果为:\n");
	for(int i=1;i<=L.length;i++){
		printf("%d ",L.r[i].key);
	} 
	
	
	return 0;
	
}


