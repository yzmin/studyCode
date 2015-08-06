#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <memory.h>

void Swap(int *p1, int *p2);//两个数交换
void Swap1(int *pint, int i, int j);//两个数交换
void CreateRandom(int *pint, int length);//创造随机数存放指定的数组中
void bubble(int *pint, int length);//冒泡排序O(n^2)
void BubbleSort(int *pint, int length);//O(n^2)
void Traverse(int *pint, int length);//打印指定数组中的内容
int  MinIndex(int *pint, int Low_Index, int High_Index);//在指定范围内，寻找数组最小元素的下标
void SelectSort(int *pint, int Low_Index, int High_Index);//选择排序O(n^2)
int  Binaray(int *pint, int Low_Index, int High_Index, int key);//二分查找
int  BinarayRec(int *pint, int Low_Index, int High_Index, int key);//二分查找递归
int  D_Value(int *pint, int Low_Index, int High_Index, int key);//差值查找
int  D_ValueRec(int *pint, int Low_Index, int High_Index, int key);//差值查找递归
void InsertSort(int *pint, int Low_Index, int High_Index);//插入排序O(n^2)
void ShellSort(int array[], int len);//希尔排序O(nlogn)=O(1.3n)

int  Compareint(const void *p1, const void *p2);
void QuickSort(int *pint, int length);//快速排序

int Partition(int *pint, int Low_Index, int High_Index);//High_Index最大下标
void QSort(int *pint, int Low_Index, int High_Index);//快速排序
void QuickSort1(int *pint, int length);


void Merge(int src[], int des[], int low, int mid, int high);
void MSort(int src[], int des[], int low, int high, int max);
void MergeSort(int array[], int len);

