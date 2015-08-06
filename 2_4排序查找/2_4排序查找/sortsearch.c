#include "sortsearch.h"

extern int Random[1000];

//两个数交换
void Swap(int *p1, int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
//指定位置交换
void Swap1(int *pint, int i, int j)
{
	int tmp = *(pint + i);
	*(pint + i) = *(pint + j);
	*(pint + j) = tmp;
}
//创造随机数存放指定的数组中
void CreateRandom(int *pint, int length)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < length; i++)
	{
		pint[i] = rand();
	}
}
//冒泡排序
void bubble(int *pint, int length)
{
	//外循环控制
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (pint[j] > pint[j + 1])
			{
				Swap(&pint[j], &pint[j + 1]);
			}
		}
	}
}
//优化冒泡排序
void BubbleSort(int *pint, int length) // O(n*n)
{
	int i = 0;
	int j = 0;
	int exchange = 1; //表明数组是否已经排好序 已经排好序为0   1表示没有排好序
	for (i = 0; (i < length) && exchange; i++)
	{
		exchange = 0;//认为已经排序完毕
		for (j = length - 1; j > i; j--)
		{
			if (pint[j] < pint[j - 1])
			{
				Swap1(pint, j, j - 1);
				exchange = 1;// 如果35 36行被执行，说明还没有排好序
			}
		}
	}
}
//打印指定数组中的内容
void Traverse(int *pint, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%7d", pint[i]);
		if ((i + 1) % 10 == 0)
		{
			printf("\n");
		}
	}
}
//在指定范围内，寻找数组最小元素的下标
int MinIndex(int *pint, int Low_Index, int High_Index)
{
	int key = pint[Low_Index];//默认一个元素就是最小的元素
	int min_index = Low_Index;//最小元素所在数组的下标
	for (int i = Low_Index + 1; i < High_Index; i++)
	{
		if (key>pint[i])
		{
			key = pint[i];
			min_index = i;
		}
	}
	return min_index;//返回最小元素所在数组的下标
}
//选择排序
void SelectSort(int *pint, int Low_Index, int High_Index)
{
	for (int i = Low_Index; i < High_Index; i++)
	{
		int j = MinIndex(pint, i, High_Index);//得到从i，到high之间最小元素的下标
		if (i != j)
		{
			Swap(&pint[i], &pint[j]);
		}
	}
}


int  Compareint(const void *p1, const void *p2)
{
	const int num1 = *((const int *)p1);
	const int num2 = *((const int *)p2);
	if (num1 == num2)
	{
		return 0;
	}
	else if (num1 > num2)
	{
		return 1;
	}
	else if (num1 < num2)
	{
		return -1;
	}
}
//库函数的快速排序
void QuickSort(int *pint, int length)
{
	qsort(pint, length, sizeof(int), Compareint);
}


//二分查找
int  Binaray(int *pint, int Low_Index, int High_Index, int key)
{
	while (Low_Index <= High_Index)
	{
		int mid_index = (Low_Index + High_Index) / 2;//取中间值
		if (key == pint[mid_index])
		{
			return mid_index;
		}
		else if (key > pint[mid_index])
		{
			Low_Index = mid_index + 1;
		}
		else
		{
			High_Index = mid_index - 1;
		}
	}
	return -1;
}

int  BinarayRec(int *pint, int Low_Index, int High_Index, int key)
{
	if (Low_Index <= High_Index)
	{
		int mid_index = (Low_Index + High_Index) / 2;
		if (key == pint[mid_index])
		{
			return mid_index;
		}
		else if (key > pint[mid_index])
		{
			return BinarayRec(pint, mid_index + 1, High_Index, key);
		}
		else
		{
			return BinarayRec(pint, Low_Index, mid_index - 1, key);
		}
	}
	else
	{
		return -1;
	}
}

int  D_Value(int *pint, int Low_Index, int High_Index, int key)
{
	while (Low_Index <= High_Index)
	{//差值，求比例
		int mid_index = Low_Index + (High_Index - 1 - Low_Index)*(key - pint[Low_Index]) / (pint[High_Index - 1] - pint[Low_Index]);
		//zhong = tou + (wei - tou)*(key - p[tou]) / (p[wei] - p[tou]); /
		if (key == pint[mid_index])
		{
			return mid_index;
		}
		else if (key > pint[mid_index])
		{
			Low_Index = mid_index + 1;
		}
		else
		{
			High_Index = mid_index - 1;
		}
	}
	return -1;
}

int  D_ValueRec(int *pint, int Low_Index, int High_Index, int key)
{
	if (Low_Index <= High_Index)
	{
		int mid_index = Low_Index + (High_Index - 1 - Low_Index)*(key - pint[Low_Index]) / (pint[High_Index - 1] - pint[Low_Index]);
		if (key == pint[mid_index])
		{
			return mid_index;
		}
		else if (key > pint[mid_index])
		{
			return BinarayRec(pint, mid_index + 1, High_Index, key);
		}
		else
		{
			return BinarayRec(pint, Low_Index, mid_index - 1, key);
		}
	}
	else
	{
		return -1;
	}
}
//插入排序
void InsertSort(int *pint, int Low_Index, int High_Index)
{
	int k = -1;
	int tmp = -1;
	for (int i = 1; i < High_Index; i++)
	{
		k = i;//待插入位置
		tmp = pint[i];
		for (int j = i - 1; (j >= 0) && (pint[j] >tmp); j--)
		{
			pint[j + 1] = pint[j];//元素后移
			k = j; //k需要插入的位置
		}
		pint[k] = tmp;//元素插入
	}
}

void ShellSort(int array[], int len) //希尔排序
{
	int i = 0;
	int j = 0;
	int k = -1;
	int temp = -1;
	int gap = len;
	do
	{
		//业界统一实验的 平均最好情况 经过若干次后，收敛为1
		gap = gap / 3 + 1; //gap /2345 2000 都行  //O（n 1.3） gap = 1;

		for (i = gap; i<len; i += gap)
		{
			k = i;
			temp = array[k];

			for (j = i - gap; (j >= 0) && (array[j]>temp); j -= gap)
			{
				array[j + gap] = array[j];
				k = j;
			}

			array[k] = temp;
		}

	} while (gap > 1);

}



//快速排序
//划分过程 第一个元素当枢轴，分成2个有效子序列
int Partition(int *pint, int Low_Index, int High_Index)
{
	int pv = pint[Low_Index];

	while (Low_Index < High_Index)
	{
		while ((Low_Index < High_Index) && (pint[High_Index] >= pv))
		{
			High_Index--; //比基准大，本来就在右边，所以high前移动
		}
		Swap1(pint, Low_Index, High_Index);
		while ((Low_Index < High_Index) && (pint[Low_Index] <= pv))
		{
			Low_Index++;
		}
		Swap1(pint, Low_Index, High_Index);
	}
	//返回枢轴的位置。。。重要
	return Low_Index;
}

void QSort(int *pint, int Low_Index, int High_Index)
{
	if (Low_Index < High_Index)
	{
		//选一个pv值，把数据分别放在pv值得左右两边，并把pivot位置返回出来。。
		int pivot = Partition(pint, Low_Index, High_Index);

		//对子序列1排序
		QSort(pint, Low_Index, pivot - 1);
		//对子序列2排序
		QSort(pint, pivot + 1, High_Index);
	}
}

void QuickSort1(int *pint, int length) // O(n*logn)
{
	QSort(pint, 0, length - 1);
}

void Merge(int src[], int des[], int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = low;

	while ((i <= mid) && (j <= high)) //将小的放到目的地中
	{
		if (src[i] < src[j])
		{
			des[k++] = src[i++];
		}
		else
		{
			des[k++] = src[j++];
		}
	}

	while (i <= mid)  //若还剩几个尾部元素
	{
		des[k++] = src[i++];
	}

	while (j <= high) //若还剩几个尾部元素
	{
		des[k++] = src[j++];
	}
}

//每次分为两路 当只剩下一个元素时，就不需要在划分
void MSort(int src[], int des[], int low, int high, int max)
{
	if (low == high) //只有一个元素，不需要归并，结果赋给des[low]
	{
		des[low] = src[low];
	}
	else //如果多个元素，进行两路划分
	{
		int mid = (low + high) / 2;
		int* space = (int*)malloc(sizeof(int)* max);

		//递归进行两路，两路的划分 
		//当剩下一个元素的时，递归划分结束，然后开始merge归并操作
		if (space != NULL)
		{
			MSort(src, space, low, mid, max);
			MSort(src, space, mid + 1, high, max);
			Merge(space, des, low, mid, high); //调用归并函数进行归并

		}

		free(space);
	}
}

void MergeSort(int array[], int len) // O(n*logn)
{
	MSort(array, array, 0, len - 1, len);
}







