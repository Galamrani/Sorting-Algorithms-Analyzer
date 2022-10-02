#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#define _CRT_SECURE_NO_WARNINGS


//PrintArray(arrayP, n);


int main()
{

	int k, n;
	int* A;
	int* B;

	// n is the number of members in the array
	// k is the number of the smallest members of the sorted array

	k = UserInput_nk("k");
	n = UserInput_nk("n");
	if ((n < 1) || (k < 1)) return 0;
	A = GetArray(n);
	B = GetArray(n);
	UserInput_format(A, B, n);


	AlgoA(n, k, A);
	AlgoB(n, k, B);


	return 0;
}


