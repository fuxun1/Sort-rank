//简单选择排序
//2025.10.21

#include<stdio.h>

#define MAXSIZE 20
typedef int ElemType;

typedef struct{
	ElemType key;
}RedType;

typedef struct{
	RedType r[MAXSIZE+1];
	int length;
}SqList;

void SelectSort(SqList &L){
	int i,j,k;
	int temp;
	for(i=1;i<=L.length;i++){
		k=i;
		for(j=i+1;j<=L.length;j++){
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
	printf("请输入要排序的元素个数:");
	scanf("%d",&n);
	L.length=n;
	printf("请输入%d个元素（空格分隔）：",n);
	for(int i=1;i<=L.length;i++){
		scanf("%d",&L.r[i].key);
	}
	SelectSort(L);
	printf("排序结果：\n");
	for(int i=1;i<=L.length;i++){
		printf("%d ", L.r[i].key);
	}
	
	return 0;
	
}



