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
}bj;//����һ���ܴ洢�������εĽṹ�� 
int QKPass(int r[],int l[],int low,int high)
{
	bj m;
	int x=r[low],y=l[low];
	while(low<high){
		while(low<high&&r[high]>x) high--;//��������С�ڵ��ڻ�׼��¼�ĵ�һ�ؼ���ʱ�˳�ѭ�� 
		if(low<high) 
		{
			if (r[high]<x)
			{
				
				r[low]=r[high];
				l[low]=l[high];
		        low++;
			}
		    else if (r[high]==x)//�����λ�õĹؼ��ֵ��ڻ�׼��¼ʱ 
		    {
		    	m.a=r[high];
		    	m.b=l[high];
		    	//ʹ�ṹ���ֵ�ֱ���ڸ�λ�õ������ؼ��� 
		    	if (y<l[high])
		    	//�Ƚϵڶ��ؼ��֣�����׼��¼�еĵڶ��ؼ����滻Ϊ�ϴ����һ�� 
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
		//�����������ڵ��ڻ�׼��¼�ĵ�һ�ؼ���ʱ�˳�ѭ�� 
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
		    	//�Ƚϵڶ��ؼ��֣�����׼��¼�еĵڶ��ؼ����滻Ϊ��С����һ�� 
		    	{
		    		int t;
		    		t=y;
		    		y=l[low];
		    		m.b=t;
				}
				r[high]=m.a;
				l[high]=m.b;
				//���ṹ���е����ݴ���highλ�� 
				high--;
			}
		}
	} 
	r[low]=x;
	l[low]=y;
	return low;
} 

 
void QKSort(int r[],int l[],int low,int high )
/* �Լ�¼���� r[low . . high]�ÿ��������㷨�������� */ 
{   
    if(low<high){
   	int pos=QKPass(r,l,low,high);/*����һ�˿�������������Ԫ��Ϊ�绮�������ӱ�*/ 
   	QKSort(r,l,low,pos-1);/*�����ӱ��������*/ 
   	QKSort(r,l,pos+1,high); /*���Ҳ��ӱ��������*/
   }
}

int main()
{	RecordList L;
	int i,j;
	int x;
	printf ("��207-�־�ʥ-202012900816\n");
	printf("���������鳤�� :");
	scanf("%d",&i);
	printf("����Ҫ����� %d�����ݵĵ�һ�ؼ���:\n",i);
	L.length=i;
	for(j=1;j<=i;j++)
	{scanf("%d",&L.r[j]);
	}
	printf("����Ҫ����� %d�����ݵĵڶ��ؼ���:\n",i);
	for(j=1;j<=i;j++)
	{scanf("%d",&L.l[j]);
	}
	QKSort(L.r,L.l,1,L.length);
	
    printf("���������˳�����£�\n");
    for(i=1;i<=L.length;i++)
	printf("%d   %d\n",L.r[i],L.l[i]);
	} 
