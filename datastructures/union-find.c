#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

size_t find(size_t A[], size_t i) {
	if (A[i] == SIZE_MAX) {
		return i;
	}

	return find(A, A[i]);
}

void myUnion(size_t A[], size_t i, size_t j) {
	if (find(A, i) != find(A, j)) {
		size_t root_i = find(A, i);
		size_t root_j = find(A, j);

		A[root_j] = root_i;
	}
}

int main() {
	size_t n;
	printf("How many elements?\n");
	scanf("%zu", &n);

	size_t* parent = malloc(n * sizeof(size_t));

	if (parent == NULL) {
		fprintf(stderr, "Memory could not be saved!\n");
		return 1;
	}

	for (size_t i = 0; i < n; i++) {
		parent[i] = SIZE_MAX;
	}

	myUnion(parent, 1, 2);
	myUnion(parent, 2, 3);

	printf("Root of 3 is: %zu\n", find(parent, 3));

	free(parent);
	return 0;
}
