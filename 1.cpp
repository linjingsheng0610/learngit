#include<stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
#define LISE_SIZE 20
typedef struct
{ int r[LISE_SIZE+1];
  int l[LISE_SIZE+1]; 
  int length;
} RecordList;
typedef struct
{
	int a;
	int b;
}bj;//创建一个能存储两个整形的结构体 
int QKPass(int r[],int l[],int low,int high)
{
	bj m;
	int x=r[low],y=l[low];
	while(low<high){
		while(low<high&&r[high]>x) high--;//当遍历到小于等于基准记录的第一关键字时退出循环 
		if(low<high) 
		{
			if (r[high]<x)
			{
				
				r[low]=r[high];
				l[low]=l[high];
		        low++;
			}
		    else if (r[high]==x)//如果该位置的关键字等于基准记录时 
		    {
		    	m.a=r[high];
		    	m.b=l[high];
		    	//使结构体的值分别等于该位置的两个关键字 
		    	if (y<l[high])
		    	//比较第二关键字，将基准记录中的第二关键字替换为较大的那一个 
		    	{
		    		int t;
		    		t=y;
		    		y=l[high];
		    		m.b=t;
				}
				r[low]=m.a;
				l[low]=m.b;
				low++;
			}
		}
		while(low<high&&r[low]<x) low++;
		//当遍历到大于等于基准记录的第一关键字时退出循环 
		if(low<high) 
		{ 
		    if (r[low]>x)
		    {
		    	r[high]=r[low];
				l[high]=l[low]; 
			    high--;
			}
		    else if (r[low]==x)
		    {
		    	m.a=r[low];
		    	m.b=l[low];
		    	if (y>l[low])
		    	//比较第二关键字，将基准记录中的第二关键字替换为较小的那一个 
		    	{
		    		int t;
		    		t=y;
		    		y=l[low];
		    		m.b=t;
				}
				r[high]=m.a;
				l[high]=m.b;
				//将结构体中的数据存入high位置 
				high--;
			}
		}
	} 
	r[low]=x;
	l[low]=y;
	return low;
} 

 
void QKSort(int r[],int l[],int low,int high )
/* 对记录数组 r[low . . high]用快速排序算法进行排序 */ 
{   
    if(low<high){
   	int pos=QKPass(r,l,low,high);/*调用一趟快速排序，以枢轴元素为界划分两个子表*/ 
   	QKSort(r,l,low,pos-1);/*对左部子表快速排序*/ 
   	QKSort(r,l,pos+1,high); /*对右部子表快速排序*/
   }
}

int main()
{	RecordList L;
	int i,j;
	int x;
	printf ("软工207-林静圣-202012900816\n");
	printf("请输入数组长度 :");
	scanf("%d",&i);
	printf("输入要排序的 %d个数据的第一关键字:\n",i);
	L.length=i;
	for(j=1;j<=i;j++)
	{scanf("%d",&L.r[j]);
	}
	printf("输入要排序的 %d个数据的第二关键字:\n",i);
	for(j=1;j<=i;j++)
	{scanf("%d",&L.l[j]);
	}
	QKSort(L.r,L.l,1,L.length);
	
    printf("快速排序后顺序如下：\n");
    for(i=1;i<=L.length;i++)
	printf("%d   %d\n",L.r[i],L.l[i]);
	} 
