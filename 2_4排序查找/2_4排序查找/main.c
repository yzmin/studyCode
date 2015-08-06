#include "sortsearch.h"

int Random[1000] = { 0 };


int main()
{
	CreateRandom(Random, 100);
	printf("ÅÅÐòÇ°Êý¾Ý:\n");
	Traverse(Random, 100);
	//bubble(Random, 100);
	//SelectSort(Random, 0, 100);
	//QuickSort(Random, 100);
	//InsertSort(Random, 0, 100);
	//BubbleSort(Random, 100);
	//ShellSort(Random, 100);
	QuickSort1(Random, 100);
	//MergeSort(Random, 100);
	printf("----------------------------------------------------------------------\n");
	Traverse(Random, 100);
	printf("----------------------------------------------------------------------\n");
	printf("%d\n",BinarayRec(Random, 0, 100, 22190));
	printf("----------------------------------------------------------------------\n");
	printf("%d\n", D_ValueRec(Random, 0, 100, 22190));
	system("pause");
	return 0;
}





