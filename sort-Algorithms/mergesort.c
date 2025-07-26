#include <stdio.h>
#include <stdbool.h>

/*
Integer
*/
void printArrayInt(int A[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

void copyArrayInt(int A[], int iBegin, int iEnd, int B[]) {
	for(int i = iBegin; i < iEnd; i++) {
		B[i] = A[i];
	}
}

void TopDownMergeInt(int B[], int iBegin, int iMiddle, int iEnd, int A[]) {
	int i = iBegin, j = iMiddle;

	for (int k = iBegin; k < iEnd; k++) {
		if (i < iMiddle && (j >= iEnd || A[i] < A[j])) {
			B[k] = A [i];
			i = i + 1;
		} else {
			B[k] = A[j];
			j = j + 1;
		}
	}
}

void TopDownSplitMergeInt(int B[], int iBegin, int iEnd, int A[]) {
	if(iEnd - iBegin <= 1) {
		return;
	}

	int iMiddle = (iEnd + iBegin) / 2;

	TopDownSplitMergeInt(A, iBegin, iMiddle, B);
	TopDownSplitMergeInt(A, iMiddle, iEnd, B);

	TopDownMergeInt(B, iBegin, iMiddle, iEnd, A);
}

void TopDownMergeSortInt(int A[], int B[], int n){
	copyArrayInt(A, 0, n, B);
	TopDownSplitMergeInt(A, 0, n, B);
}

bool isSortedInt(int A[], int n){
	for (int i = 1; i < n; i++) {
		if (A[i - 1] > A[i]) return false;
	}
	return true;
}

/*
Double
*/

void printArrayDouble(double A[], int n) {
        for (int i = 0; i < n; i++) {
                printf("%.2f ", A[i]);
        }
        printf("\n");
}

void copyArrayDouble(double A[], int iBegin, int iEnd, double B[]) {
        for(int i = iBegin; i < iEnd; i++) {
                B[i] = A[i];
        }
}

void TopDownMergeDouble(double B[], int iBegin, int iMiddle, int iEnd, double A[]) {
        int i = iBegin, j = iMiddle;

        for (int k = iBegin; k < iEnd; k++) {
                if (i < iMiddle && (j >= iEnd || A[i] < A[j])) {
                        B[k] = A [i];
                        i = i + 1;
                } else {
                        B[k] = A[j];
                        j = j + 1;
                }
        }
}

void TopDownSplitMergeDouble(double B[], int iBegin, int iEnd, double A[]) {
        if(iEnd - iBegin <= 1) {
                return;
        }

        int iMiddle = (iEnd + iBegin) / 2;

        TopDownSplitMergeDouble(A, iBegin, iMiddle, B);
        TopDownSplitMergeDouble(A, iMiddle, iEnd, B);

        TopDownMergeDouble(B, iBegin, iMiddle, iEnd, A);
}

void TopDownMergeSortDouble(double A[], double B[], int n){
        copyArrayDouble(A, 0, n, B);
        TopDownSplitMergeDouble(A, 0, n, B);
}

bool isSortedDouble(double A[], int n){
	for (int i = 1; i < n; i++) {
		if (A[i - 1] > A[i]) return false;
	}
	return true;
}

void runIntSort() {
	printf("Type in 5 Integers in any order:\n");

	int A[5];
	int B[5];
	int count = 1;

	for (int i = 0; i < 5; i++) {
		printf("Number %d\n", count++);
		scanf("%d", &A[i]);
	}

	printArrayInt(A, 5);
	TopDownMergeSortInt(A, B, 5);
	printArrayInt(A, 5);

	if (isSortedInt(A, 5)) {
		printf("Array is sorted\n");
	} else {
		printf("Array is not sorted\n");
	}
}

void runDoubleSort() {
	printf("Type in 5 Doubles in any order:\n");
	double A[5];
	double B[5];
	int count = 1;

	for (int i = 0; i < 5; i++) {
		printf("Number %d\n", count++);
		scanf("%lf", &A[i]);
	}

	printArrayDouble(A, 5);
	TopDownMergeSortDouble(A, B, 5);
	printArrayDouble(A, 5);

	if (isSortedDouble(A, 5)) {
		printf("Array is sorted\n");
	} else {
		printf("Array is not sorted\n");
	}
}

int main() {
	int choice;

	printf("Which type do you want to sort?\n1.Integer\n2.Double\n");
	scanf("%d", &choice);

	switch(choice) {
	case 1:
		runIntSort();
		break;

	case 2:
		runDoubleSort();
		break;

	default:
		printf("Ungültige Auswahl.\n");
	}
	return 1;
}
