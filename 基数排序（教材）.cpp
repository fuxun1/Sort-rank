//堆排序
//2025.10.22
//堆排序需要重新定义记录类型（RedType），除了包含关键字之外，还需要记录关键字的位数
//一个关键字定义为数组形式 keys[关键字项数最大值]便于把各位数分离 

#define MAX_NUM_OF_KEY 6
#define RADIX 10
#define MAXSIZE 10000
typedef int ElemType;

typedef struct{
	ElemType keys[MAX_NUM_OF_KEY]； 
	int bitsnum; 
}RedType;

typedef struct{
	RedType r[MAXSIZE+1];
	int length;
}SqList;

void RadixSort(SqList &L){
	RedType C[L.length];	//开设辅助空间 
	i=bitsnum-1; 
	
}
