//直接插入排序
//2025.9.24
#include<stdio.h>

#define MAXSIZE 20
typedef int KeyType;

typedef struct{
	KeyType key;
}RedType; 

typedef struct{
	RedType r[MAXSIZE+1];
	int length;	
}Sqlist;

//排序函数 
void InsertSort(Sqlist *L){
	int i,j;
	for(i=2;i<=L->length;i++){
		if(L->r[i].key<L->r[i-1].key){
			L->r[0]=L->r[i];
			for(j=i-1;L->r[0].key<L->r[j].key;j--){
				L->r[j+1].key=L->r[j].key;
			}
			L->r[j+1].key=L->r[0].key;
		}
	}
}

//打印顺序表函数
void PrintList(Sqlist L) {
	printf("排序结果：");
	for( int i=1;i<=L.length;i++){
		printf("%d ",L.r[i].key);	//顺序表中的每个数据元素是存放在数组中的，L.r[i].key表示L顺序表中的第i个数据元素的关键字 
	}
	printf("\n"); 
}

//主函数
int main(){
	Sqlist L;	//Sqlist是自定义类型，类似于int,double... 
	int n;
	
	printf("请输入顺序表要排序的元素个数（不超过%d）：",MAXSIZE);
	scanf("%d",&n);
	
	if(n<=0||n>MAXSIZE) {
		printf("输入无效\n");
		return 0;
	}
	
	L.length=n;
	
	printf("请输入%d个整数：",n);
	//需要一个个存进去，用一个for循环,i=0(哨兵)不用村 
	for(int i=1;i<=L.length;i++) {
	scanf("%d",&L.r[i].key);
	}
	
	//调用函数
	InsertSort(&L);
	PrintList(L);
	
	return 0;
	 
} 







