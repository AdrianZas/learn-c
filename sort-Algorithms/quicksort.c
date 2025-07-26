#include <stdio.h>

int divide(int iBegin, int iEnd, int A[]) {
	int i = iBegin;
	int j = iEnd - 1;
	int pivot = A[iEnd];

	while (i < j) {
		while (i < j && A[i] <= pivot) {
			i += 1;
		}

		while (j > i && A[j] > pivot) {
			j -= 1;
		}

		if (A[i] > A[j]) {
			int tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}

	if (A[i] > pivot) {
		int tmp = A[i];
		A[i] = A[iEnd];
		A[iEnd] = tmp;
	} else {
		i = iEnd;
	}
	return i;
}

void quicksort(int iBegin, int iEnd, int A[]) {
	if (iBegin < iEnd) {
		int divider = divide(iBegin, iEnd, A);
		quicksort(iBegin, divider - 1, A);
		quicksort(divider + 1, iEnd, A);
	}
}

void printArray(int A[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

int main() {
	int A[5] = {5,4,3,2,1};
	printArray(A, 5);
	quicksort(0, 4, A);
	printArray(A, 5);
	return 1;
}
