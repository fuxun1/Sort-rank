//基数排序 C++
//2025.10.22

#include<bits/stdc++.h>
using namespace std;
//要排序的8个元素 
int a[8]={312,5,76,123,9871,456,222,10};
//0-9共10个桶，每个桶可存100个元素 
//约定b[n][0]表示第n个桶的长度 ,看成一个变量 
int b[10][100]; 

//求一个数是几位数
int Digit(int num){
	int k=0;
	while(num!=0){
		num/=10;
		k++;
	}
	return k;
} 

//输出
void print(int a[],int len){
	for(int i=0;i<len;i++){
		cout<<a[i]<<" ";
	}
	
} 

int main(){
	//求a[]中的最大值并判断其是几位数
	int maxNum=0;
	for(int i=0;i<8;i++){
		if(a[i]>maxNum){
			maxNum=a[i];
		}
	} 
	int k=Digit(maxNum);
	int Y=1;
	int num;
	//外层循环控制每一轮取8个元素的哪一位数（个位、十位...） ，最多循环k轮 
	for(int i=1;i<=k;i++){
		//循环之前要把桶清空
		memset(b,0,sizeof(b)); 
		//内层循环a数组，取出8个元素的同一位（个位开始） 
		for(int j=0;j<8;j++){
			num=a[j]/Y%10;
			//b[0~9][0]作为桶0~9的长度,因为还未放元素,所以初始值为0 
			//按照取出的数字num放到对应的桶b[num][]中 
			b[num][++b[num][0]]=a[j];	/*++b[num][0]=1,从1开始存储 ,b[num][0]表示num桶的第0个元素不用来存取，
			而用作存储桶的长度或者说记录当前桶里面存了多少个元素 
			第一个元素入桶时，b[num][0] 从0变为1，元素存在 b[num][1]。
			第二个元素入桶时，b[num][0] 从1变为2，元素存在 b[num][2]。
			以此类推，b[num][0] 的值始终等于该桶中已存储的元素个数（即 “长度”）*/ 
		}
		//依次把桶中元素拿出，放到a中
		int a_len=0;
		for(int n=0;n<=9;n++){
			//遍历一个桶中的所有元素 
			for(int m=1;m<=b[n][0];m++){
				a[a_len++]=b[n][m] ;
			}
			}
			print(a,8);
			cout<<endl;
			Y*=10; 
		} 
		
	}





