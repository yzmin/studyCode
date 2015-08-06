#include "sortsearch.h"

extern int Random[1000];

//����������
void Swap(int *p1, int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
//ָ��λ�ý���
void Swap1(int *pint, int i, int j)
{
	int tmp = *(pint + i);
	*(pint + i) = *(pint + j);
	*(pint + j) = tmp;
}
//������������ָ����������
void CreateRandom(int *pint, int length)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < length; i++)
	{
		pint[i] = rand();
	}
}
//ð������
void bubble(int *pint, int length)
{
	//��ѭ������
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
//�Ż�ð������
void BubbleSort(int *pint, int length) // O(n*n)
{
	int i = 0;
	int j = 0;
	int exchange = 1; //���������Ƿ��Ѿ��ź��� �Ѿ��ź���Ϊ0   1��ʾû���ź���
	for (i = 0; (i < length) && exchange; i++)
	{
		exchange = 0;//��Ϊ�Ѿ��������
		for (j = length - 1; j > i; j--)
		{
			if (pint[j] < pint[j - 1])
			{
				Swap1(pint, j, j - 1);
				exchange = 1;// ���35 36�б�ִ�У�˵����û���ź���
			}
		}
	}
}
//��ӡָ�������е�����
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
//��ָ����Χ�ڣ�Ѱ��������СԪ�ص��±�
int MinIndex(int *pint, int Low_Index, int High_Index)
{
	int key = pint[Low_Index];//Ĭ��һ��Ԫ�ؾ�����С��Ԫ��
	int min_index = Low_Index;//��СԪ������������±�
	for (int i = Low_Index + 1; i < High_Index; i++)
	{
		if (key>pint[i])
		{
			key = pint[i];
			min_index = i;
		}
	}
	return min_index;//������СԪ������������±�
}
//ѡ������
void SelectSort(int *pint, int Low_Index, int High_Index)
{
	for (int i = Low_Index; i < High_Index; i++)
	{
		int j = MinIndex(pint, i, High_Index);//�õ���i����high֮����СԪ�ص��±�
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
//�⺯���Ŀ�������
void QuickSort(int *pint, int length)
{
	qsort(pint, length, sizeof(int), Compareint);
}


//���ֲ���
int  Binaray(int *pint, int Low_Index, int High_Index, int key)
{
	while (Low_Index <= High_Index)
	{
		int mid_index = (Low_Index + High_Index) / 2;//ȡ�м�ֵ
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
	{//��ֵ�������
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
//��������
void InsertSort(int *pint, int Low_Index, int High_Index)
{
	int k = -1;
	int tmp = -1;
	for (int i = 1; i < High_Index; i++)
	{
		k = i;//������λ��
		tmp = pint[i];
		for (int j = i - 1; (j >= 0) && (pint[j] >tmp); j--)
		{
			pint[j + 1] = pint[j];//Ԫ�غ���
			k = j; //k��Ҫ�����λ��
		}
		pint[k] = tmp;//Ԫ�ز���
	}
}

void ShellSort(int array[], int len) //ϣ������
{
	int i = 0;
	int j = 0;
	int k = -1;
	int temp = -1;
	int gap = len;
	do
	{
		//ҵ��ͳһʵ��� ƽ�������� �������ɴκ�����Ϊ1
		gap = gap / 3 + 1; //gap /2345 2000 ����  //O��n 1.3�� gap = 1;

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



//��������
//���ֹ��� ��һ��Ԫ�ص����ᣬ�ֳ�2����Ч������
int Partition(int *pint, int Low_Index, int High_Index)
{
	int pv = pint[Low_Index];

	while (Low_Index < High_Index)
	{
		while ((Low_Index < High_Index) && (pint[High_Index] >= pv))
		{
			High_Index--; //�Ȼ�׼�󣬱��������ұߣ�����highǰ�ƶ�
		}
		Swap1(pint, Low_Index, High_Index);
		while ((Low_Index < High_Index) && (pint[Low_Index] <= pv))
		{
			Low_Index++;
		}
		Swap1(pint, Low_Index, High_Index);
	}
	//���������λ�á�������Ҫ
	return Low_Index;
}

void QSort(int *pint, int Low_Index, int High_Index)
{
	if (Low_Index < High_Index)
	{
		//ѡһ��pvֵ�������ݷֱ����pvֵ���������ߣ�����pivotλ�÷��س�������
		int pivot = Partition(pint, Low_Index, High_Index);

		//��������1����
		QSort(pint, Low_Index, pivot - 1);
		//��������2����
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

	while ((i <= mid) && (j <= high)) //��С�ķŵ�Ŀ�ĵ���
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

	while (i <= mid)  //����ʣ����β��Ԫ��
	{
		des[k++] = src[i++];
	}

	while (j <= high) //����ʣ����β��Ԫ��
	{
		des[k++] = src[j++];
	}
}

//ÿ�η�Ϊ��· ��ֻʣ��һ��Ԫ��ʱ���Ͳ���Ҫ�ڻ���
void MSort(int src[], int des[], int low, int high, int max)
{
	if (low == high) //ֻ��һ��Ԫ�أ�����Ҫ�鲢���������des[low]
	{
		des[low] = src[low];
	}
	else //������Ԫ�أ�������·����
	{
		int mid = (low + high) / 2;
		int* space = (int*)malloc(sizeof(int)* max);

		//�ݹ������·����·�Ļ��� 
		//��ʣ��һ��Ԫ�ص�ʱ���ݹ黮�ֽ�����Ȼ��ʼmerge�鲢����
		if (space != NULL)
		{
			MSort(src, space, low, mid, max);
			MSort(src, space, mid + 1, high, max);
			Merge(space, des, low, mid, high); //���ù鲢�������й鲢

		}

		free(space);
	}
}

void MergeSort(int array[], int len) // O(n*logn)
{
	MSort(array, array, 0, len - 1, len);
}







