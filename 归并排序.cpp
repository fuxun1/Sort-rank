//归并排序 
//2025.10.21

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20
typedef int ElemType;

typedef struct{
	ElemType key;
}RedType;

typedef struct{
	RedType r[MAXSIZE+1];
	int length;
}SqList;

//归并函数 （划分＋归并）
//将顺序表SR划分为左子序列r[1]-r[m]和右子序列r[m+1]-r[n] 
//TR为临时空间用来存储归并结果，长度与SR相同 
void Merge(SqList &SR,SqList &TR,int i,int m,int n){
	int k=i; //k作为TR数组的临时指针，指向第一个元素 
	int j;	//j为指向右子序列第一个元素的指针
	//i为指向左子序列第一个元素的指针 
	for(j=m+1;i<=m&&j<=n;k++){
		if(SR.r[i].key<=SR.r[j].key){
			TR.r[k].key=SR.r[i].key;
			i++;
		}else{
			TR.r[k].key=SR.r[j].key;
			j++;
		}
	} 
	//跳出for循环意味着必有一个子列已为空，把另一个子序列剩的元素直接拿过来 
	//两个while循环顺序无要求 
	while(i<=m){
		TR.r[k].key=SR.r[i].key;
		i++;
		k++;
	}
	while(j<=n){
		TR.r[k].key=SR.r[j].key;
		j++;
		k++;
	}
	
}

//归并排序递归函数,将SR的[s..t]排序到TR1的[s..t]
void MSort(SqList &SR,SqList &TR1,int s,int t){
	SqList TR2;	 // 临时数组，用于中间存储
	//递归终止条件
	if(s==t){
		TR1.r[s].key=SR.r[s].key;
	}else{
		int m;
		//关键：递归部分，比较难理解，需要多想几遍 
		m=(s+t)/2;	//// 中间位置，用于分割序列
		MSort(SR,TR2,s,m);	// 递归排序左半部分SR[s-m]到TR2
		MSort(SR,TR2,m+1,t);	// 递归排序右半部分[m+1~t]到TR2
		Merge(TR2,TR1,s,m,t);	// 合并TR2的两部分到TR1
	}

} 

//归并排序入口函数 
void MergeSort(SqList &L){
	MSort(L,L,1,L.length);
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
	MergeSort(L);
	printf("排序结果：\n");
	for(int i=1;i<=L.length;i++){
		printf("%d ", L.r[i].key);
	}
	
	return 0;
	
	
}
