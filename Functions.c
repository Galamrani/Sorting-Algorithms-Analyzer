#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#define _CRT_SECURE_NO_WARNINGS


/* global variable declaration */

int comparisons_algoA = 0;
int comparisons_algoB = 0;


int UserInput_nk(char* x)
{
	int y, a;
	printf("Type the value of %s: ", x);
	a = scanf_s("%d", &y);
	return y;
}

void UserInput_format(int* A, int* B, int n)
{
	int x, a;
	printf("for randomised filling (type 0),  for manual filling, (type 1) :	");
	a = scanf_s("%d", &x);
	if (x == 0 || x == 1) FillArray(A, B, x, n);
	else printf("invalid input");
}

void PrintArray(int* A, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d \n", *(A + i));
	}
}

void FillArray(int* A, int* B, int x, int n)
{
	int a, num;
	for (int i = 0; i < n; i++)
	{
		if (x == 0)
		{
			num = (rand() % 999);
			*(A + i) = num;
			*(B + i) = num;
		}
		else
		{
			printf("type the %d number ", i + 1);
			a = scanf_s("%d", &num);
			*(A + i) = num;
			*(B + i) = num;
		}
	}
}

void Swap(int* A, int j, int i)
{
	int temp = *(A + j);
	*(A + j) = *(A + i);
	*(A + i) = temp;
}

int* GetArray(int n)
{
	int* arrayP;
	arrayP = (int*)malloc(sizeof(int) * n);
	if (arrayP == NULL)
	{
		printf("memory error");
		exit(1);
	}
	return arrayP;
}





/* Algo A -- > Heap Sort */

void AlgoA(int n, int k, int* A)
{
	BuildMinHeap(A, n);
	ExtractMin(A, n - 1, k);
	PrintOutputA(A, n, k);
}

void PrintOutputA(int* A, int n, int k)
{
	printf("\n********************************  Heap Sort results  ********************************");
	printf("\n\nk minimum numbers in in the array:  ");
	for (int i = n; i > (n - k); i--)
	{
		printf("%d, ", A[i - 1]);
	}
	printf("\nnumber of comparisons of Heap Sort (Algo A) is:  %d\n\n", comparisons_algoA);
}

int Left(int i)
{
	return i * 2;
}

int Right(int i)
{
	return i * 2 + 1;
}

void BuildMinHeap(int* A, int n)
{
	int x = n / 2;
	for (int i = x; i > -1; i--)
	{
		MinHeapify(A, i, n);
	}

}

void MinHeapify(int* A, int i, int n)
{
	int min;
	while (1)
	{
		min = i;
		if (Left(i) <= n - 1)
		{
			comparisons_algoA++;
			if (*(A + Left(i)) < A[min])
			{
				min = Left(i);
			}
		}
		if (Right(i) <= n - 1)
		{
			comparisons_algoA++;
			if (*(A + Right(i)) < A[min])
			{
				min = Right(i);
			}
		}
		if (min == i)
		{
			return;
		}
		Swap(A, min, i);
		i = min;
	}
}

void ExtractMin(int* A, int size, int k)
{
	int temp;
	for (int i = 0; i < k; i++)
	{
		temp = *(A + 0);
		*(A + 0) = *(A + size);
		*(A + size) = temp;
		size = size - 1;
		MinHeapify(A, 0, size);
	}
}



/* Algo B -- > Quick Sort */

void AlgoB(int n, int k, int* B)
{
	KthSmallest(B, 0, n - 1, k - 1);
	QuickSort(B, 0, k);
	PrintOutputB(B, n, k);
}

int KthSmallest(int* A, int left_index, int right_index, int k)
{
	int q = RamdomizedSelect(A, left_index, right_index);

	if (q == k) return q;
	if (q > k) return KthSmallest(A, left_index, q - 1, k);
	return KthSmallest(A, q + 1, right_index, k);
}

int RamdomizedSelect(int* A, int p, int r)
{
	int i = (rand() % r);
	Swap(A, r, i);
	return Partition(A, p, r);
}

int Partition(int* A, int p, int r)
{
	int pivot, i, j;
	pivot = *(A + r);
	i = p - 1;
	for (j = p; j < r; j++)
	{
		if (*(A + j) <= pivot)
		{
			i = i + 1;
			Swap(A, i, j);
		}
		comparisons_algoB++;
	}
	Swap(A, i + 1, r);
	return  i + 1;
}

void QuickSort(int* A, int l, int r)
{
	int q;
	if (r <= l) return;
	q = Partition(A, l, r);
	QuickSort(A, l, q - 1);
	QuickSort(A, q + 1, r);
}

void PrintOutputB(int* B, int n, int k)
{
	printf("\n\n********************************  Quick Sort results  ********************************");
	printf("\n\nk minimum numbers in in the array:  ");
	for (int i = 0; i < k; i++)
	{
		printf("%d, ", B[i]);
	}
	printf("\nnumber of comparisons of Quick Sort (Algo B) is:  %d\n\n", comparisons_algoB);
}






