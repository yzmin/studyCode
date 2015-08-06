#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <memory.h>

void Swap(int *p1, int *p2);//����������
void Swap1(int *pint, int i, int j);//����������
void CreateRandom(int *pint, int length);//������������ָ����������
void bubble(int *pint, int length);//ð������O(n^2)
void BubbleSort(int *pint, int length);//O(n^2)
void Traverse(int *pint, int length);//��ӡָ�������е�����
int  MinIndex(int *pint, int Low_Index, int High_Index);//��ָ����Χ�ڣ�Ѱ��������СԪ�ص��±�
void SelectSort(int *pint, int Low_Index, int High_Index);//ѡ������O(n^2)
int  Binaray(int *pint, int Low_Index, int High_Index, int key);//���ֲ���
int  BinarayRec(int *pint, int Low_Index, int High_Index, int key);//���ֲ��ҵݹ�
int  D_Value(int *pint, int Low_Index, int High_Index, int key);//��ֵ����
int  D_ValueRec(int *pint, int Low_Index, int High_Index, int key);//��ֵ���ҵݹ�
void InsertSort(int *pint, int Low_Index, int High_Index);//��������O(n^2)
void ShellSort(int array[], int len);//ϣ������O(nlogn)=O(1.3n)

int  Compareint(const void *p1, const void *p2);
void QuickSort(int *pint, int length);//��������

int Partition(int *pint, int Low_Index, int High_Index);//High_Index����±�
void QSort(int *pint, int Low_Index, int High_Index);//��������
void QuickSort1(int *pint, int length);


void Merge(int src[], int des[], int low, int mid, int high);
void MSort(int src[], int des[], int low, int high, int max);
void MergeSort(int array[], int len);

