//节约空间的快速排序（交替式逼近直至low=high）
//2025.10.19
/*思路：QSort快速排序函数，接收操作对象表L，low指针起始位置1，high指针起始位置L.length三个参数，
low=1作为全局变量不会被Partition修改，里面改的low只是局部变量，作用是判断low=high并返回给pivotloc（枢轴位置） ， 
QSort快速排序函数里面调用Partition这种特殊的快速排序算法，得到枢轴元素的位置，再通过
递归对子表不断进行排序 
Partition快速排序算法的思路：同样接受操作对象，low/high指针起始位置三个参数，
把low位置上的元素给哨兵，再把哨兵位置上元素的key（值）给pivotkey（用作判断）
外层循环条件low<high，内层并列两个循环，第一个循环，因为一开始是前面空，
所以要从后面找，在满足low<high前提下，
只有当high指向的元素小于 pivotkey时才能跳出循环，同时把high指向的元素给前面空的位置（low位置），
否则high--;
第二个循环，因为后面空了，所以要从前面一直low++直到找到一个比pivotkey大的元素放到后面，
即将low指向的元素给high指的位置
最后退出外层循环，把哨兵元素放到枢轴位置（既是low位置也是high位置） 
将low的值返回出去传给pivotloc以便递归*/

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

//交替逼近快速排序算法 
int Partition(SqList &L,int low,int high){
	int pivotkey;
	L.r[0]=L.r[low];
	pivotkey=L.r[0].key;
	while(low<high){
		while(low<high&&L.r[high].key>=pivotkey){
			high--;
		}
		L.r[low].key=L.r[high].key;
		while(low<high&&L.r[low].key<=pivotkey){
			low++;
		}
		L.r[high].key=L.r[low].key;
	}
	L.r[low]=L.r[0];
	return low;
}

//快速排序的递归函数 
void QSort(SqList &L,int low,int high){
	int pivotloc;
	if(low<high){
	pivotloc=Partition(L,low,high);
	QSort(L,low,pivotloc-1);
	QSort(L,pivotloc+1,high);
}
	return;
}




int main(){
	SqList L;
	int n,i;
	printf("输入要排序的元素个数:\n");
	scanf("%d",&n);
	L.length=n;
	printf("请输入%d个元素(用空格分隔):\n",n);
	for(i=1;i<=L.length;i++){
		scanf("%d",&L.r[i].key);
	} 
	QSort(L,1,L.length);
	printf("排序结果为：\n");
	for(i=1;i<=L.length;i++){
		printf("%d ",L.r[i].key);
	}
	return 0;
} 



 
